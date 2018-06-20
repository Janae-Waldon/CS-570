#include "a2.h"

void createfile(char* filename){
    FILE *fp;
    fp=fopen(filename,"w");
    fclose(fp);
    return ;
}

void readfile(char* filename){
    FILE *fp;
    // Open file
    char  c;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
        exit(0); //TODO make this not exit but return to main menu instead
    }
    
    // Read contents from file
    c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
    
    fclose(fp);
    return;
}

int writefile(char* filename)
{
    FILE * fp;
    char towrite[80];
    /* open the file for writing*/
    fp = fopen (filename,"w");
    
    /* write 10 lines of text into the file stream*/
    scanf ("%[^\n]%*c", towrite);
    //scanf(stdin, "%s", towrite);
    fprintf (fp,"%s", towrite);
    
    /* close the file*/
    fclose (fp);
    
    //TODO: gotta fork those proccess per assingment request
    
    pid_t childPID = fork();
    
    if(childPID >= 0) {
        if(childPID == 0){
            //TODO: run alpha sort
        }
        else{
            //TODO: run reverse alpha sort
        }
    }
    else // fork failed
    {
        printf("\n Fork failed, quitting.\n");
        return 1;
    }
    return 0;
}

void createDirectory(char* dirname){
    int dir;
    /*Makes a directory with a name passed by the user;
      All the variables starting with "S_" denote the user permissions.
      S_IRUSER = permission to read by owner
      S_IWUSR  = permission to write by owner
      S_IRGRP  = permission to read by group
      S_IROTH  = permission to read by others
      S_IXUSR  = owner has executable permissions
      S_IXGRP  = group has executable permission
      S_IXOTH  = others have executable permission
    */
    dir = mkdir(dirname, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | S_IXUSR | S_IXGRP | S_IXOTH);
}

void printfilestatus(char* filename){
    struct stat info;
    FILE *fp = fopen(filename, "r");
    int fb = fileno(fp);

    if (fstat(fb, &info) != 0){
        perror("Error");
    } else {
        puts("File Status:");
        printf("  inode:   %d\n",   (int) info.st_ino);
        printf(" dev id:   %d\n",   (int) info.st_dev);
        printf("   mode:   %08x\n",	  info.st_mode);
        printf("  links:   %d\n",         info.st_nlink);
        printf("    uid:   %d\n",   (int) info.st_uid);
        printf("    gid:   %d\n",   (int) info.st_gid);
    }
	fclose(fp);
}

void printdirlisting(char* filedir){
    DIR *dp;
    struct dirent *ep;

    dp = opendir (filedir);
    if (dp != NULL){
        while (ep = readdir (dp)){
            puts (ep->d_name);
        }
        (void) closedir (dp);
    } else{
        perror ("Couldn't open the directory");
    }

}

void sortalpha(){
    
}

void reversesortalpha(){
    
}

