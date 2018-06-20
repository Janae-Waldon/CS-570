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

void menu(){
    printf("Hello, what would you like to do?\n");
    printf("1. Create a new directory\n");
    printf("2. Create a new file\n");
    printf("3. Write to a file\n");
    printf("4. Read/Write to shadow file\n");
    printf("5. Read an exitsing file\n");
    printf("6. Write to a existing file\n");
    printf("7. Print file status\n");
    printf("8. Print directory listing\n");
    printf("9. Exit\n");
    printf("0. Help\n");
}

void performMenuInstruction(){
    int subMenuOption;
    
    do{
        //0. Gives the user instructions how the main menu works.
        if(actionPerformed == 0){
            printf("On the command line, type the number that corresponds to the action you want to be performed. For Example, if you would like to write to a file, you would type '6'. (Note only one parameter is excepted at a time.)\n For name, type in whatever filename or directory name you want. For example, when prompted for name, type 'Myfile' or 'Directory Name'.\n");
        }
        
        //1. creates a sub menu that exits/ goes back to previous menu & creates a new directory file using user input.
        else if(actionPerformed == 1){
            int subActionPerformed;
            
            //submenu
            printf("1. New directory\n");
            printf("2. Back\n");
            printf("9. Exit\n");
            
            scanf("%d", &subActionPerformed);
            if(subMenuOption == 1){
                printf("Filename: ");
                scanf("%s", userDirectoryName);
                createDirectory(userDirectoryName);
            }
            else if(subMenuOption == 2){
                continue;                                               //go to main menu
            }
            else if(subMenuOption == 9){
                break;
            }
//            else{
//                printf("Not an option");
//                continue;
//            }
            //return;
        }
        /*
         //2. creates a new file using user input; additionally creates a sub menu that exits/ goes back to previous menu
         else if(actionPerformed == 2){
         printf("New filename: ");
         scanf("%s", userFilename);
         createfile(userFilename);
         
         //submenu
         printf("0. Back\n");
         printf("1. Exit\n");
         
         if(subMenuOption == 0){
         //menu();
         }
         else if(subMenuOption == 1){
         //exit program
         break;
         }
         else{
         printf("Not an option");
         break;
         }
         
         
         
         //write to a file
         case 3:
         printf("Filename: ");
         scanf("%s", userFilename);
         writefile(userFilename);
         break;
         
         //read/write to shadow
         case 4:
         printf("                     WHAT?                            ");
         //scan & store
         //shadow();
         break;
         
         //read an existing file
         case 5:
         printf("Filename: ");
         //scan & store
         //readfile(userFilename);
         readfile(userFilename);
         break;
         
         //write to an existing file (in insert, append, or overwite mode)
         case 6:
         printf("Filename: ");
         //scan & store
         writefile(userFilename);
         break;
         
         //print file status
         case 7:
         printf("Filename: ");
         
         //scan & store
         printfilestatus(userFilename);
         break;
         
         //print directory listing
         case 8:
         printf("Directory name: ");
         
         printdirlisting(userFilename);
         break;
         
         default:
         printf("Please enter one number between 0-9.\n");
         }
         */
    } while (actionPerformed != 9 && isdigit(actionPerformed));
}
    
int main(int argc, char const *argv[]){
        
            menu();
            scanf("%d", &actionPerformed);
            performMenuInstruction();
            
   
}
