#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <utime.h>
void archive(char *fn);
char *give_proper_name(char *name);
bool file_exists_in_current_dir(const char *filename);
char * two_args(char * a);
char * three_args(char * a, char * b);
char ** list_dir(void);
void remove_newline(char *str);
void create_dir(char *fn);
void archive_select(char *archive_name, char **file_list, int num_files);
void unarchive(char *archive_name, char *extract_dir);
struct header {
    unsigned int uid;
    char owner[64];
    unsigned int n_files;
};

struct file {
    size_t size;
    time_t timestamp;
    char file_name[256];
    unsigned int options;
};

int main(int argc, char **argv)
{
    char *archivename;

    if (argc == 2 || argc == 3 || argc==4)
    {
    /*If two arguments, we need to get the name of the file to zip/unzip.*/
    if (argc == 2)
    {
        two_args(argv[1]);
        return 0;
    }
    /*If three arguments, determine whether to archive or extract.*/
    if (argc == 3)
    {
        three_args(argv[1], argv[2]);
        return 0;
    }
    /*If four arguments, it must be to extract*/
    if (argc==4)
    {
       if (strcmp(argv[1],"c")==0){
        fprintf(stderr, "Usage: zarchive [x,c] filename extractdir\n");
        return 1;
       }
        unarchive(argv[2],argv[3]);
        return 0;
    }
    }
    /*Show user how to properly input command*/
    else
    {
        fprintf(stderr, "Usage: zarchive [x,c] filename\n");
        return 1;
    }

    return 0;
}


/*We need to format for archive name, also ensure file does not exist for archiver and does exist for unarchiver.*/
char *three_args(char *a, char *b)
{
    if (*a=='c' || *a=='x')
    {
        /*Format name with .z extension.*/
    char * name = give_proper_name(b);
    if (*a == 'c')
    {
        if (!file_exists_in_current_dir(name)){
            archive(name);
        }
        else
        {
            fprintf(stderr, "Error: archived filename already exists.\n");
            return NULL;
        }
    }

    if (*a == 'x')
    {
        if (file_exists_in_current_dir(b)){
        unarchive(b, NULL);
    }
    else
    {   
    fprintf(stderr, "Error: file does not exist\n");
    return NULL;
}
}
}
else{
    fprintf(stderr, "Usage: zarchive [x,c] filename\n");
}
}

     /*We need to ask the name of the file for both if branches.*/
char *two_args(char *c)
{
    if (*c =='c' || *c =='x')
    {

        /*Buffer to input name of archive file.*/
    char buf[50];
    
    printf("Archived file name has not been provided. Please enter name of new archive file:\n");
    fgets(buf, sizeof(buf), stdin);
    /*Format with .z extension.*/
    char * name = give_proper_name(buf);

    if (*c == 'c')
    {
    if (file_exists_in_current_dir(name))
    {
        fprintf(stderr, "Error: archived filename already exists.\n");
        return NULL;
    }
        if (!file_exists_in_current_dir(name)){
        archive(name);
    }
}
    if (*c == 'x')
    {
        if (file_exists_in_current_dir(buf)){

            unarchive(buf, NULL);
        }
    
    if (!file_exists_in_current_dir(buf))
    {
        fprintf(stderr, "Error: archived filename does not exist.\n");
        return NULL;
    }
    }
}
    else
    {
    fprintf(stderr, "Usage: zarchive [x,c] filename\n");
}
}

/*Check if string is formatted with '.z' extension.*/
char *give_proper_name(char *name)
{
    char * newname = name;
    remove_newline(newname);
    int len = strlen(newname);
    if (len >= 2 && newname[len - 2] != '.' && newname[len - 1] != 'z')
    {
        char zappend [3];
        zappend[0]='.';
        zappend[1]= 'z';
        zappend[2] = '\0';
        newname = strcat(newname, zappend);
    }
    return newname;
}

/*Boolean returns true if filename is found in current directory.*/
bool file_exists_in_current_dir(const char *filename)
{
    DIR *dir;
    struct dirent *entry;
    bool found = false;
    dir = opendir(".");
   
    if (dir == NULL)
    {
        perror("Unable to open current directory\n");
        return false;
    }
   
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, filename) == 0)
        {
            found = true;
            break;
        }
    }
    closedir(dir);
    return found;
}

char **list_dir(void) {
    DIR *dir;
    struct dirent **namelist;
    struct stat fs;
    int n;
    int valid_count = 0;

    n = scandir(".", &namelist, NULL, alphasort);
    if (n < 0) {
        perror("scandir");
        exit(EXIT_FAILURE);
    }
    /*Allocate buffer to hold dirents*/
    char **valid_files = malloc((n + 1) * sizeof(char *));
    if (!valid_files) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        /*Filter out . , ..*/
        if (strcmp(namelist[i]->d_name, ".") == 0 || strcmp(namelist[i]->d_name, "..") == 0) {
            free(namelist[i]);
            continue;
        }

        if (stat(namelist[i]->d_name, &fs) < 0) {
            perror("stat");
            free(namelist[i]);
            continue;
        }
        /*Buffer for time string*/
        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&fs.st_mtime));
        printf("%-30s %-20s %-10ld\n", namelist[i]->d_name, buf, fs.st_size);
        
        valid_files[valid_count++] = namelist[i]->d_name;
    }
    /*Free the extra index*/
    valid_files[valid_count] = NULL; 
    free(namelist); 
    
    return valid_files;
}

void remove_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}


void archive(char *fn)
{

    int n;
    char **namelist = list_dir();
    n = sizeof(namelist)/sizeof(char*);

    printf("Please select which files to archive, type -1 to end prompt and begin archive.\n");
    char **buf = malloc(n * sizeof(char *));
    if (buf == NULL) {
        perror("Failed to allocate memory");
        return;
    }
    /*Buffer to store filename one at a time which is passed to buf.*/
    char inter[50];
    int index = 0;

        while (1) {
        fgets(inter, sizeof(inter), stdin);
        remove_newline(inter);

        if (strcmp(inter, "-1") == 0) {
            break;
        }

        if (strcmp(inter, "*") == 0) {
            /*Archive all files.*/
            archive_select(fn, namelist, n);
            free(buf);
            return;
        }

        if (file_exists_in_current_dir(inter)) {
            /*Copy the file name.*/
            buf[index] = strdup(inter); 
            if (buf[index] == NULL) {
                perror("Failed to allocate memory");
                free(buf);
                return;
            }
            index++;
        } else {
            printf("File '%s' not found. Please try again.\n", inter);
        }
    }

    if (index > 0) {
        archive_select(fn, buf, index);
    } else {
        fprintf(stderr, "Error: no files provided\n");
    }

}



void archive_select(char *archive_name, char **file_list, int num_files) {
    if (file_list == NULL) {
        fprintf(stderr, "Error: no files provided\n");
        return;
    }

    FILE *archive = fopen(archive_name, "wb");
    if (!archive) {
        perror("Failed to open archive file");
        return;
    }

    /*Create archive header.*/
    struct header hdr;
    hdr.uid = getuid();
    struct passwd *pw = getpwuid(hdr.uid);
    strncpy(hdr.owner, pw->pw_name, sizeof(hdr.owner));
    hdr.n_files = num_files;

    fwrite(&hdr, sizeof(hdr), 1, archive);

    /*Add each file to the archive.*/
    for (int i = 0; i < num_files; i++) {
        struct stat st;
        if (stat(file_list[i], &st) != 0) {
            perror("Failed to stat file");
            continue;
        }
        /*Create file header.*/
        struct file file_hdr;
        file_hdr.size = st.st_size;
        file_hdr.timestamp = st.st_mtime;
        strncpy(file_hdr.file_name, file_list[i], sizeof(file_hdr.file_name));
        file_hdr.options = 0;

        fwrite(&file_hdr, sizeof(file_hdr), 1, archive);

        /*Write file data.*/
        FILE *file = fopen(file_list[i], "rb");
        if (!file) {
            perror("Failed to open file");
            continue;
        }
       

        char *buffer = malloc(file_hdr.size);
        fread(buffer, 1, file_hdr.size, file);
        fwrite(buffer, 1, file_hdr.size, archive);
        free(buffer);

        fclose(file);
    }

    fclose(archive);
}

void create_dir(char *fn)
{
 char path[256]; 

    strcpy(path, "./"); 
    strcat(path, fn);   
    remove_newline(path);
    
    if (mkdir(path, 0700) == -1) {
        perror("Error creating directory");
      
    } else {
        printf("Directory created successfully: %s\n", path);
    }
}

void unarchive(char *archive_name, char *extract_dir) 
{
    FILE *archive = fopen(archive_name, "rb");
    if (!archive) {
        perror("Failed to open archive file");
        return;
    }

    /*Read archive header.*/
    struct header hdr;
    if (fread(&hdr, sizeof(hdr), 1, archive) != 1) {
        perror("Failed to read archive header");
        fclose(archive);
        return;
    }

    /*Create the extract directory, if provided.*/
    if (extract_dir) {
        if (mkdir(extract_dir, 0700) == -1) {
            perror("Failed to create extraction directory");
            fclose(archive);
            return;
        }
        /*Change directory.*/
        chdir(extract_dir);
    }

    /*Extract each file from the archive.*/
    for (unsigned int i = 0; i < hdr.n_files; i++) {
        struct file file_hdr;
        if (fread(&file_hdr, sizeof(file_hdr), 1, archive) != 1) {
            perror("Failed to read file header");
            break;
        }

        /*Create the output file using header*/
        FILE *file = fopen(file_hdr.file_name, "wb");
        if (!file) {
            perror("Failed to create file");
            continue;
        }

        /*Read, write file data.*/
        char *buffer = malloc(file_hdr.size);
        if (!buffer) {
            perror("Failed to allocate memory");
            fclose(file);
            continue;
        }

        if (fread(buffer, 1, file_hdr.size, archive) != file_hdr.size) {
            perror("Failed to read file data");
            free(buffer);
            fclose(file);
            continue;
        }

        fwrite(buffer, 1, file_hdr.size, file);
        free(buffer);
        fclose(file);

        /*Restore the file's modification time*/
        struct utimbuf utime_buf;
        utime_buf.actime = file_hdr.timestamp; 
        utime_buf.modtime = file_hdr.timestamp; 
        utime(file_hdr.file_name, &utime_buf);
    }

    fclose(archive);
    /*Return to original directory.*/
    if (extract_dir) {
        chdir(".."); 
    }
}

bool is_ascii_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return 0;
    
    unsigned char buffer[4096];
    size_t bytes_read;
    
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            if (buffer[i] >> 7) {
                fclose(file);
                return 0; 
            }
        }
    }
    
    fclose(file);
    return 1; 
}