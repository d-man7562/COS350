#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void decompress(const char *filename);
void compress(const char *filename);

int main(int argc, char **argv)
{
	/*Error checking*/
    if(argc != 2) {
        fprintf(stderr, "Usage: z827 filename\n");
        exit(1);
    }
	/*Case: compress or decompress*/
    if (strstr(argv[1], ".z827") != NULL) {
        decompress(argv[1]);
    } else {
        compress(argv[1]);
    }
    /*Delete input filename*/
    unlink(argv[1]);
    return 0;
}

void compress(const char *input_filename)
{	
	/*Error checking*/
    int input_fd = open(input_filename, O_RDONLY);
    if (input_fd == -1) {
        perror("Error opening input file");
        exit(1);
    }
	/*Get file size to write*/
    off_t file_size = lseek(input_fd, 0, SEEK_END);
    lseek(input_fd, 0, SEEK_SET);
	/*Create compressed filename*/
    char output_filename[strlen(input_filename) + 6];
    strcpy(output_filename, input_filename);
    strcat(output_filename, ".z827");
	/*Create compressed file*/
    int output_fd = creat(output_filename, 0644);
    if (output_fd == -1) {
        perror("Error creating output file");
        close(input_fd);
        exit(1);
    }

    /*Write file size in header*/
    write(output_fd, &file_size, 4);

    unsigned char in_buf[8];
    unsigned char out_buf[7];
    ssize_t bytes_read;
	/*Read maximum 8 byte chunks*/
    while ((bytes_read = read(input_fd, in_buf, 8)) > 0) {
	    /*Check top bit for proper encoding format*/
  	    for (ssize_t i = 0; i < bytes_read; i++) {
        if (in_buf[i] >> 7 == 1) {
            fprintf(stderr, "Error: incompatible encoding\n");
	    close(input_fd);
	    close(output_fd);
            unlink(output_filename);
	    exit(1); 
        }
    }
	    
	    /*Zero-pad empty bytes*/
        for (ssize_t i = bytes_read; i < 8; i++) {
            in_buf[i] = 0;
	}

	        /*Pack bytes*/
        out_buf[0] = (in_buf[0] << 1) | (in_buf[1] >> 6);
        out_buf[1] = (in_buf[1] << 2) | (in_buf[2] >> 5);
        out_buf[2] = (in_buf[2] << 3) | (in_buf[3] >> 4);
        out_buf[3] = (in_buf[3] << 4) | (in_buf[4] >> 3);
        out_buf[4] = (in_buf[4] << 5) | (in_buf[5] >> 2);
        out_buf[5] = (in_buf[5] << 6) | (in_buf[6] >> 1);
        out_buf[6] = (in_buf[6] << 7) | (in_buf[7] & 0x7F);

        /*Calculate how many output bytes needed to write*/
        size_t out_bytes = (bytes_read * 7 + 7) / 8;
        write(output_fd, out_buf, out_bytes);
    }
	/*Close*/
    close(input_fd);
    close(output_fd);
}

void decompress(const char *input_filename)
{
	/*Error checking*/
    int input_fd = open(input_filename, O_RDONLY);
    if (input_fd == -1) {
        perror("Error opening input file");
        exit(1);
    }

    /*Read original file size from header*/
    off_t original_size;
    if (read(input_fd, &original_size, 4) != 4) {
        perror("Error reading file size");
        close(input_fd);
        exit(1);
    }

    /*Create output filename (remove .z827)*/
    char output_filename[strlen(input_filename)];
    strncpy(output_filename, input_filename, strlen(input_filename) - 5);
    output_filename[strlen(input_filename) - 5] = '\0';

    int output_fd = creat(output_filename, 0644);
    if (output_fd == -1) {
        perror("Error creating output file");
        close(input_fd);
        exit(1);
    }

    unsigned char in_buf[7];
    unsigned char out_buf[8];
    off_t bytes_remaining = original_size;
    
    while (bytes_remaining > 0) {
        /*Calculate how many compressed bytes to read*/
        ssize_t to_read = (bytes_remaining >= 8) ? 7 : ((bytes_remaining * 7 + 7) / 8);
        ssize_t bytes_read = read(input_fd, in_buf, to_read);
        
        if (bytes_read <= 0) break;

        /*Zero-pad empty bytes*/
        for (ssize_t i = bytes_read; i < 7; i++) {
            in_buf[i] = 0;
        }

        /*Unpack bytes*/
        out_buf[0] = in_buf[0] >> 1;
        out_buf[1] = ((in_buf[0] & 0x01) << 6) | (in_buf[1] >> 2);
        out_buf[2] = ((in_buf[1] & 0x03) << 5) | (in_buf[2] >> 3);
        out_buf[3] = ((in_buf[2] & 0x07) << 4) | (in_buf[3] >> 4);
        out_buf[4] = ((in_buf[3] & 0x0F) << 3) | (in_buf[4] >> 5);
        out_buf[5] = ((in_buf[4] & 0x1F) << 2) | (in_buf[5] >> 6);
        out_buf[6] = ((in_buf[5] & 0x3F) << 1) | (in_buf[6] >> 7);
        out_buf[7] = in_buf[6] & 0x7F;

        /*Write unpacked bytes*/
        size_t to_write = (bytes_remaining >= 8) ? 8 : bytes_remaining;
        write(output_fd, out_buf, to_write);
        bytes_remaining -= to_write;
    }

    close(input_fd);
    close(output_fd);
}
