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
void archive(char *fn);
//void unarchive(char *fn);
char *give_proper_name(char *name);
bool file_exists_in_current_dir(const char *filename);
char * two_args(char * a);
char * three_args(char * a, char * b);
int list_dir(void);
void remove_newline(char *str);
void create_dir(char *fn);

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

    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if (argc == 2 || argc == 3)
    {
    /*If two arguments, we need to get the name of the file to zip/unzip.*/
    if (argc == 2)
    {
        two_args(argv[1]);
    }
    /*If three arguments, determine whether to archive or extract.*/
    if (argc == 3)
    {
        three_args(argv[1], argv[2]);
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
        //unarchive(b);
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

    char buf[50];
    
    printf("Archived file name has not been provided. Please enter name of archived file:\n");
    fgets(buf, sizeof(buf), stdin);
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

            // unarchive(buf);
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

struct dirent **list_dir(void)
{
    DIR *dir;
    struct dirent **namelist;
    struct stat fs;
    int n;
    n = scandir(".", &namelist, NULL, alphasort);
    if (n < 0)
    {
        perror("scandir");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        /*Filter out . and ..*/
        if (strcmp(namelist[i]->d_name, ".") == 0 || strcmp(namelist[i]->d_name, "..") == 0) {
            free(namelist[i]); 
            continue;
        }
        if (stat(namelist[i]->d_name, &fs) < 0)
        {
            perror("stat");
            free(namelist[i]);
            exit(EXIT_FAILURE);
        }

        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&fs.st_mtime));
            /*Print the size, modification date and time, and the file name.*/
            printf("%-30s %-20s %-10ld\n", namelist[i]->d_name,
                   buf,
                   fs.st_size);
                   
                   free(namelist[i]);
                }
                free(namelist);
                
                return namelist;
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
    struct dirent **namelist = list_dir();
    n = sizeof(namelist)/sizeof(struct dirent**);
    printf("Please select which files to archive, type -1 to end prompt and begin archive.\n");
    char **buf;
    char inter[50];
    while (inter!="-1")
    {
    if (strcmp(inter,"*")){
    archive_files(fn,buf, sizeof(namelist)/sizeof(struct dirent**), namelist);
        break;
    }

    fgets(inter, sizeof(inter), stdin);
    if (file_exists_in_current_dir(inter))
    {
    strcat(buf, inter);
    }

    }
    if (inter=="-1")
    {
        if (buf == NULL)
        {
    fprintf(stderr, "Error: no files provided");
        }
        archive_files(fn, buf, sizeof(buf)/sizeof(char**), namelist);

    }

}
void archive_files(char *archive_name, char **file_list, int num_files, struct dirent **file_list) {
    FILE *archive = fopen(archive_name, "wb");
    if (!archive) {
        perror("Failed to open archive file");
        return;
    }

    // Create and write the archive header
    struct header hdr;
    hdr.uid = getuid();
    struct passwd *pw = getpwuid(hdr.uid);
    strncpy(hdr.owner, pw->pw_name, sizeof(hdr.owner));
    hdr.n_files = num_files;

    fwrite(&hdr, sizeof(hdr), 1, archive);

    // Add each file to the archive
    for (int i = 0; i < num_files; i++) {
        struct stat st;
        if (stat(file_list[i], &st) != 0) {
            perror("Failed to stat file");
            continue;
        }

        struct file file_hdr;
        file_hdr.size = st.st_size;
        file_hdr.timestamp = st.st_mtime;
        strncpy(file_hdr.file_name, file_list[i], sizeof(file_hdr.file_name));
        file_hdr.options = 0; // Assuming no compression for now

        fwrite(&file_hdr, sizeof(file_hdr), 1, archive);

        // Write the file data
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