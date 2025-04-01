/*
 * scroller.c - A text file viewer with continuous scrolling functionality
 * Similar to 'more' but with continuous scrolling capabilities
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#define DEFAULT_SCROLL_INTERVAL 2   /* Default scroll interval in seconds */
#define MAX_BUFFER_SIZE 1000000   
#define SCROLL_RATE_CHANGE 0.2    


char *buffer;                   /* Buffer to hold the entire file */
int buffer_size = 0;            /* Size of the buffer */
int current_line = 0;           /* Current line being displayed */
int total_lines = 0;            /* Total number of lines in the file */
int *line_positions;            /* Array to store starting positions of each line */
int window_rows, window_cols;   /* Window dimensions */
int scrolling_active = 0;       /* Boolean flag for continuous scrolling */
double scroll_interval = DEFAULT_SCROLL_INTERVAL; /* Scroll interval in seconds */
struct termios original_termios; /* Store original terminal settings */
struct itimerval timer;         /* Timer for continuous scroll loop */


void setup_terminal();
void restore_terminal();
void read_file(const char *filename);
void display_screen();
void handle_keypress(char c);
void set_timer();
void stop_timer();
void handle_timer(int sig);
void get_window_size();
void display_prompt();
void cleanup_and_exit();

int main(int argc, char *argv[]) {
    char c;
    int keyboard_fd;

    /* Setup terminal for raw mode */
    setup_terminal();

    /* Get window size */
    get_window_size();

    /* Read file from argv or stdin */
    if (argc > 1) {
        read_file(argv[1]);
    } else {
        read_file(NULL); /* NULL = stdin */
    }

    /* Display first page */
    display_screen();

    /* Open keyboard device */
    keyboard_fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    if (keyboard_fd == -1) {
        perror("Unable to open keyboard device");
        cleanup_and_exit();
        return 1;
    }

    /* Set up signal handler for timer */
    signal(SIGALRM, handle_timer);


    /* 
    Main loop 
    - 
    wait for and process keyboard input 
    */
    
    while (1) {
        if (read(keyboard_fd, &c, 1) > 0) {
            handle_keypress(c);
        }
        usleep(10000); /* Sleep to prevent CPU hogging */
    }

    /* Exit upon error of above method */
    close(keyboard_fd);
    cleanup_and_exit();
    return 0;
}

/* Set up terminal */
void setup_terminal() {
    struct termios new_termios;

    /* Get current terminal attributes */
    tcgetattr(STDIN_FILENO, &original_termios);
    
    /* New terminal attributes */
    new_termios = original_termios;
    
    /* Turn off canonical and echo mode */
    new_termios.c_lflag &= ~(ICANON | ECHO);
    
    /* Set minimum characters and timeout */
    new_termios.c_cc[VMIN] = 1;
    new_termios.c_cc[VTIME] = 0;
    
    /* Apply new attributes */
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

/* Restore original terminal settings */
void restore_terminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &original_termios);
}

/* Read the entire file into the buffer */
void read_file(const char *filename) {
    FILE *file;
    int i, line_count = 0;
    
    /* Allocate memory for buffer */
    buffer = (char *)malloc(MAX_BUFFER_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    
    /* Open file or stdin */
    if (filename != NULL) {
        file = fopen(filename, "r");
        if (file == NULL) {
            perror("Error opening file");
            free(buffer);
            exit(EXIT_FAILURE);
        }
    } else {
        file = stdin;
    }
    
    /* Read file content into buffer */
    buffer_size = fread(buffer, 1, MAX_BUFFER_SIZE - 1, file);
    
    buffer[buffer_size] = '\0'; /* Add null terminator to end of buffer */
     
    /* Count and allocate line positions according to newline */
    for (i = 0; i < buffer_size; i++) {
        if (buffer[i] == '\n') {
            line_count++;
        }
    }
    line_count++; /* In case the last line doesn't contain a newline */
    
    line_positions = (int *)malloc((line_count + 1) * sizeof(int));
    if (line_positions == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        free(buffer);
        if (filename != NULL) {
            fclose(file); 
        }
        exit(EXIT_FAILURE);
    }
    
    /* Record starting position of each line to adjust line count */
    line_positions[0] = 0;
    line_count = 1;
    for (i = 0; i < buffer_size; i++) {
        if (buffer[i] == '\n') {
            line_positions[line_count++] = i + 1;
        }
    }
    
    total_lines = line_count;
    
    /* Close file if it was opened */
    if (filename != NULL) {
        fclose(file);
    }
}

/* Display a screen of text */
void display_screen() {
    int i, j, line, pos, len;
    char *start, *end;
    
    /* Clear screen */
    printf("\033[2J\033[H");
    
    /* Display lines */
    for (i = 0; i < window_rows - 1 && current_line + i < total_lines; i++) {
        line = current_line + i;
        pos = line_positions[line];
        
        /* Get the end of this line */
        if (line < total_lines - 1) {
            len = line_positions[line + 1] - pos - 1; /* -1 to exclude newline */
        } else {
            len = buffer_size - pos;
        }
        
        /* Handle wrapping lines */
        start = buffer + pos;
        j = 0;
        
        while (j < len) {
            end = start;
            int chars_to_print = 0;
            
            /* Handle tabs */
            while (chars_to_print < window_cols && j < len) {
                if (*end == '\t') {
                    chars_to_print += 8 - (chars_to_print % 8); 
                } else {
                    chars_to_print++;
                }
                end++;
                j++;
            }
            
            /* Print the portion of the line */
            write(STDOUT_FILENO, start, end - start);
            printf("\n");
            
            start = end;
        }
    }
    
    /* Display prompt at the bottom of the screen */
    display_prompt();
}

/* Handle keyboard input */
void handle_keypress(char c) {
    switch (c) {
        /* Space - move forward one screen */
        case ' ': 
            stop_timer();
            scrolling_active = 0;
            current_line += window_rows - 1;
            if (current_line >= total_lines) {
                current_line = total_lines - 1;
            }
            display_screen();
            break;
            /* Enter - toggle scrolling */
        case '\n': 
            if (scrolling_active) {
                stop_timer();
                scrolling_active = 0;
            } else {
                scrolling_active = 1;
                set_timer();
            }
            display_screen();
            break;
            /* Increase scrolling speed */
        case 'f': 
            scroll_interval *= (1.0 - SCROLL_RATE_CHANGE);
            if (scrolling_active) {
                set_timer();
            }
            display_screen();
            break;
            /* Decrease scrolling speed */
        case 's': 
            scroll_interval *= (1.0 + SCROLL_RATE_CHANGE);
            if (scrolling_active) {
                set_timer();
            }
            display_screen();
            break;
            /* Quit */
        case 'q': 
            cleanup_and_exit();
            exit(EXIT_SUCCESS);
            break;
    }
}

/* Set up timer for continuous scrolling */
void set_timer() {
    long sec = (long)scroll_interval;
    long usec = (long)((scroll_interval - sec) * 1000000);
    
    timer.it_value.tv_sec = sec;
    timer.it_value.tv_usec = usec;
    timer.it_interval.tv_sec = sec;
    timer.it_interval.tv_usec = usec;
    
    setitimer(ITIMER_REAL, &timer, NULL);
}

/* Stop the timer */
void stop_timer() {
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    
    setitimer(ITIMER_REAL, &timer, NULL);
}

/* Handle timer signal (SIGALRM) */
void handle_timer(int sig) {
    if (current_line < total_lines - 1) {
        current_line++;
        display_screen();
    } else {
        /* End of file reached */
        stop_timer();
        scrolling_active = 0;
        display_screen();
    }
}

/* Get the current window size */
void get_window_size() {
    struct winsize ws;
    
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
        /* Default values if ioctl fails */
        window_rows = 24;
        window_cols = 80;
    } else {
        window_rows = ws.ws_row;
        window_cols = ws.ws_col;
    }
}

/* Display the prompt line at the bottom of the screen */
void display_prompt() {
    char prompt[256];
    
    /* Move cursor to the bottom line */
    printf("\033[%d;1H", window_rows);
    
    /* Clear the line */
    printf("\033[2K");
    
    /* Create prompt */
    snprintf(prompt, sizeof(prompt), "Scroll: %s (%.1fs) -- %d/%d -- Press 'q' to quit, space for next page, enter to toggle scroll",
             scrolling_active ? "ON" : "OFF",
             scroll_interval,
             current_line + 1,
             total_lines);
    
    /* Print and display in invert color */
    printf("\033[7m%s\033[0m", prompt);
    fflush(stdout);
}

/* Free everything and restore terminal before exiting */
void cleanup_and_exit() {
    /* Stop the timer */
    stop_timer();
    
    /* Free allocated memory */
    if (buffer != NULL) {
        free(buffer);
    }
    if (line_positions != NULL) {
        free(line_positions);
    }
    
    /* Restore terminal settings */
    restore_terminal();
    
    /* Clear screen and reset cursor position */
    printf("\033[2J\033[H");
}
