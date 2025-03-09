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

#include <fcntl.h>

void archive(char *fn, int flag);
char *give_proper_name(char *name);
bool file_exists_in_current_dir(const char *filename);
void two_args(char * a);
void three_args(char * a, char * b);
char ** list_dir(void);
void remove_newline(char *str);
void create_dir(char *fn);
void archive_select(char *archive_name, char **file_list, int num_files, int flag);
void unarchive(char *archive_name, char *extract_dir);
int is_ascii_file(FILE *filename);
int flag = 0;

struct header 
{
    unsigned int uid;
    char owner[64];
    unsigned int n_files;
};

struct file 
{
    size_t size;
    time_t timestamp;
    char file_name[256];
    unsigned int options;
};
    /*If two arguments, we need to get the name of the file to zip/unzip.*/
        /*If three arguments, determine whether to archive or extract.*/
         /*If four arguments, it must be to extract*/
             /*Show user how to properly input command*/


int main(int argc, char **argv)
{
    if (argc == 2 || argc == 3 || argc==4)
    {
    if (argc == 2)
    {
        two_args(argv[1]);
        return 0;
    }
    if (argc == 3)
    {
        three_args(argv[1], argv[2]);
        
    }
    if (argc==4)
    {
       if (strcmp(argv[1],"x")!=0){
        fprintf(stderr, "Usage: zarchive [x,c] filename extractdir\n");
        return 1;
       }
        unarchive(argv[2],argv[3]);
        return 0;
    }
    }

    else
    {
        fprintf(stderr, "Usage: zarchive [x,c] filename\n");
        return 1;
    }

    return 0;
}


/*We need to format for archive name, also ensure file does not exist for archiver and does exist for unarchiver.*/
void three_args(char *a, char *b)
{
     if (strcmp(a,"cz") ==0 || (strcmp(a,"zc")==0))
     {
        flag = 1;
        char * newname = give_proper_name(b);
        archive(newname, flag);
        return;
     }
    if (strcmp(a,"c") ==0 || strcmp(a,"x")==0)
    {
        /*Format name with .z extension.*/
    char * name = give_proper_name(b);
    if (strcmp(a,"c")==0)
    {
        if (!file_exists_in_current_dir(name)){
            archive(name,flag);
        }
        else
        {
            fprintf(stderr, "Error: archived filename already exists.\n");
            return;
        }
    }

    if (strcmp(a,"x")==0)
    {
        if (file_exists_in_current_dir(b)){
        unarchive(b, NULL);
    }
    else
    {   
    fprintf(stderr, "Error: file does not exist\n");
    return ;
}
}
}
else{
    fprintf(stderr, "Usage: zarchive [x,c] filename\n");
}
return;
}

     /*We need to ask the name of the file for both if branches.*/
void two_args(char *c)
{
     if (strcmp(c,"cz")==0  || (strcmp(c,"zc")==0))
     {
        flag = 1;
    
     }

   if (strcmp(c,"c")==0 || strcmp(c,"x") == 0 || strcmp(c,"cz")==0  || (strcmp(c,"zc")==0))
    {

        /*Buffer to input name of archive file.*/
    char buf[50];
    printf("Archived file name has not been provided. Please enter name of new archive file:\n");
    fgets(buf, sizeof(buf), stdin);

    /*Format with .z extension.*/
    char * name = give_proper_name(buf);

    if (strcmp(c,"c")==0 || strcmp(c,"cz")==0  || (strcmp(c,"zc")==0))
    {
        give_proper_name(name);
    if (file_exists_in_current_dir(name))
    {
        fprintf(stderr, "Error: archived filename already exists.\n");
        return;
    }
       else{

       
        archive(name,flag);
    }
}
if (strcmp(c,"x")==0)
    {
          give_proper_name(buf);
        if (file_exists_in_current_dir(buf)){

            unarchive(buf, NULL);
        }
    
   else
    {
        fprintf(stderr, "Error: archived filename does not exist.\n");
        return;
    }
    }
}
    else
    {
    fprintf(stderr, "Usage: zarchive [x,c] filename\n");
}

return;
}

/*Check if string is formatted with '.z' extension.*/
char *give_proper_name(char *name)
{
    char *newname = name;
    remove_newline(newname);
    int len = strlen(newname);
    
    // Check if name already ends with .z
    if (len < 2 || newname[len - 2] != '.' || newname[len - 1] != 'z')
    {
        char zappend[3] = {'.', 'z', '\0'};
        strcat(newname, zappend);
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

    /*Filter out . , ..*/
    for (int i = 0; i < n; i++) {
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


void archive(char *fn,int flag)
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
            archive_select(fn, namelist, n, flag);
            free(buf);
            return;
        }

        /*If name in intermediary is in directory, save it in buffer*/
        if (file_exists_in_current_dir(inter)) {
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
        archive_select(fn, buf, index, flag);
    } else {
        fprintf(stderr, "Error: no files provided\n");
    }

}



void archive_select(char *archive_name, char **file_list, int num_files, int flag) {
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
        
        /*Print archived file info*/
         char buf[80];
         strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&st.st_mtime));
         printf("%-30s %-20s %-10ld\n", file_hdr.file_name, buf, file_hdr.size);
        


         /*Write file data.*/
        FILE *file = fopen(file_list[i], "rb");
        if (!file) {
            perror("Failed to open file");
            continue;
        }
        /*For compression.*/
        if (flag==1 && is_ascii_file(file)==1)
        {
            int input_fd = open(file_list[i], O_RDONLY);
          if (input_fd == -1) {
            perror("Error opening input file");
            exit(1);
    }
 
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
       fwrite( out_buf,sizeof(out_bytes), out_bytes, archive);
    }
    file_hdr.options = 1;
        
        }
    }
        else
        {

       

        char *buffer = malloc(file_hdr.size);
        fread(buffer, 1, file_hdr.size, file);
        fwrite(buffer, 1, file_hdr.size, archive);
        free(buffer);

        fclose(file);
        }

       
    }
    return;
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
    /*To decompress*/
        if (file_hdr.options ==1)
    {
    /*Read original file size from header*/
    off_t original_size = file_hdr.size;
   unsigned char in_buf[7];
    unsigned char out_buf[8];
    off_t bytes_remaining = original_size;
    
    while (bytes_remaining > 0) {
        /*Calculate how many compressed bytes to read*/
        ssize_t to_read = (bytes_remaining >= 8) ? 7 : ((bytes_remaining * 7 + 7) / 8);
        ssize_t bytes_read = fread(in_buf, 1, to_read, archive);
        
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

/* Calculate how many uncompressed bytes to write */
        size_t to_write = (bytes_remaining < 8) ? bytes_remaining : 8;
        
        /* Write decompressed data */
        fwrite(out_buf, 1, to_write, file);
        
        /* Update bytes remaining */
        bytes_remaining -= to_write;
    }

    }  
    
        if (file_hdr.options ==0)
{


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
    }
    
    fclose(archive);
    /*Return to original directory.*/
    if (extract_dir) {
        chdir(".."); 
    }
}

int is_ascii_file(FILE *filename) {
    //FILE *file = fopen(filename, "rb");
    //if (!file) return 0;
    
    unsigned char buffer[4096];
    size_t bytes_read;
    
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), filename)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            if (buffer[i] >> 7) {
               printf("Not an ASCII file\n");
               // fclose(file);
                return 0; 
            }
        }
    }
    
    //fclose(file);
    return 1; 
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


   
   
  

/*
    in cases
    check if cz or zc 
    flag = 1
    in archive 
    flag = 1
    in archive select
    if flag = 1
    if file is ascii
    print file header 


archive_and_compress(archive_name)
create and write archive header
create file header
write file header
if file is ascii
compress file
write file
end

in unarchive:
if option==1
decompress:
read file size from header
read binary
decompresss
write uncompressed to extracted file
*/