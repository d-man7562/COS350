#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>


void archive(char* fn);
void unarchive(char* fn);
char * give_proper_name(char * name);
bool file_exists_in_current_dir(const char *filename);


int main(int argc, char**argv) {
	/*should be argv[2]*/
	char* archivename;

	/*get users name from system*/
	uid_t uid = getuid();
	struct passwd *pw = getpwuid(uid);

	if (argc ==2) {
    		printf("Archived file name has not been provided. Please enter name of archived file:\n");
    	 	   archivename = scanf(stdin);
   	 	if (argv[1] == 'c'){
        		give_proper_name(archivename);
        		archive(archivename);
   	 }
    
   	 	if (argv[1] == 'x'){
        		unarchive(/*filename*/);

}
	}		
	if (argc ==3) {

		archivename = argv[2];
	if (argv[1] == 'c'){
		printf("Archived file name has not been provided. Please enter name of archived file:\n");
        	archivename = scanf(stdin);    		
		archive(archivename);
	}
    if (argv[1] == 'x'){
        unarchive(/*filename*/);
   }
}

	else{
   	 fprintf(stderr, "Usage: zarchive [x,c] filename\n");
    	return 1;
	}

return 0;
}

char * give_proper_name(char * name){
    int len = strlen(name);
    if (!len >= 2 && name[len-2] == '.' && name[len-1] == 'z') {
        char * new_string = '.z'; 
        name = strcat(new_string, name);
    }
    return name;
    }

    bool file_exists_in_current_dir(const char *filename) {
        DIR *dir;
        struct dirent *entry;
        bool found = false;
        
        // Open the current directory
        dir = opendir(".");
        if (dir == NULL) {
            perror("Unable to open current directory");
            return false;
        }
        
        // Read directory entries
        while ((entry = readdir(dir)) != NULL) {
            // Compare the entry name with the target filename
            if (strcmp(entry->d_name, filename) == 0) {
                found = true;
                break;
            }
        }
        
        // Close the directory
        closedir(dir);
        
        return found;
    
}


void archive(char * fn) { 
	/*Check if file name is in the system
		if so, return an error. 
	otherwise, continue with control flow*/

	if (file_exists_in_current_dir(fn)) {
	perror("Error: file already exists in current directory.\n");
		return 1;
	}
	
	list_dir();
}

 void list_dir(void)
{
	DIR *dir;
        struct dirent **namelist;
	struct stat stat;
	int n;
	 n = scandir('.', namelist, NULL, alphasort)
	if (stat(namelist, stat) ==0){
	printf("\n")


        dir = opendir(".");
        while ((entry = readdir(dir)) != NULL) {
            snprintf(filepath, sizeof(filepath), "./%s", entry->d_name);
        
        // Get file statistics
        if (stat(filepath, &file_stat) == -1) {
            perror("Failed to get file stats");
            continue;
        }
        
        // Format the modification time
        struct tm *time_info = localtime(&file_stat.st_mtime);
        strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", time_info);
        
        // Print file information
        printf("%-30s %-10ld %-20s\n", 
               entry->d_name, 
               file_stat.st_size, 
               timestr);
    }
}


