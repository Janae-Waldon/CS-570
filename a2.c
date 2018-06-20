#include "a2.h"

#include "a2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int actionPerformed;

char userFilePath[] = " ";

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
    
    printf("%s Contains: \n", userFilePath);
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

void append(char* filename){
    FILE * fp;
    char towrite[80];
    //sets a pointer at the end of the file to append text
    fp = fopen(filename, "a");
    //gets the user input into a buffer, then writes it to the specified file
    printf("What would you like to append: ");
    scanf ("%[^\n]%*c", towrite);
    fprintf (fp,"%s", towrite);
    
    fclose(fp);
}


void insert(char* filename, long offset){
    FILE * fp;
    char towrite[80];
    /* open the file for writing */
    fp = fopen (filename,"r+");
    
    /* write 10 lines of text into the file stream*/
    scanf ("%[^\n]%*c", towrite);
    /* Moves to the specified offset to insert text */
    fseek(fp, offset, SEEK_SET);
    fprintf (fp,"%s", towrite);
    
    /* close the file*/
    fclose (fp);
}

void overWrite(char* filename){
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
        printf("Files in Directory: \n");
        while (ep = readdir(dp)) {
            printf("%s \n", ep->d_name);
        }
        (void) closedir (dp);
    } else{
        printf("Couldn't open the directory \n");
        printf("\n");
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
    printf("3. Read a file\n");
    printf("4. Write to a file\n");
    printf("5. Print file status\n");
    printf("6. Print directory listing\n");
    printf("0. Exit\n");
}

void performMenuInstructions(){
    int subMenuOption;
    int writeModeMenuOption;
    int appendMenuOption;
    
    do{
        menu();
        
        scanf("%d", &actionPerformed);
        //        if(!(isdigit(actionPerformed)) ){
        //            printf("ENTER A NUMBER BETWEEN 0-9\n");
        //            break;
        //        }
        
        /* 1. Create a new directory:
         creates a sub menu that exits/ goes back to previous menu & creates a new directory file using user input. */
        if(actionPerformed == 1){
            
            printf("1. Create new directory\n");
            printf("2. Back\n");
            printf("0. Exit\n");
            
            scanf("%d", &subMenuOption);
            if(subMenuOption == 1){
                printf("File Path: ");
                scanf("%s", userFilePath);
                createDirectory(userFilePath);
                continue;
            }
            if(subMenuOption == 0){
                break;
            }
            if(subMenuOption == 2){
                continue;
            }
            else{
                printf("ENTER 1, 2, or 0\n");
                continue;
            }
        }

        /* 2. Create a new file:
         creates a sub menu to create a new file. Includes the ability to go back to the main menu, exit, create a file by passing user input for filename & path. */
        else if(actionPerformed == 2){
            
            printf("1. Create new file\n");
            printf("2. Back\n");
            printf("0. Exit\n");
            
            scanf("%d", &subMenuOption);
            if(subMenuOption == 1){
                printf("File path: ");
                scanf("%s", userFilePath);
                //get path of directory (open)
                //if (filepath = NULL)
                //do{
                //printf("Directory doen't exist!\n");
                //} while (filepath = NULL);
                //continue;
                //cast to directory path
                createfile(userFilePath);
                printf("File has been added to filepath.\n");
                continue;
            }
            if(subMenuOption == 0){
                break;
            }
            if(subMenuOption == 2){
                continue;
            }
            else{
                printf("ENTER 1, 2, or 0\n");
                printf("\n");
                continue;
            } //while (subMenuOption != sucessfulSearch);
        }

        /*3. Read an existing file
         another submenu that reads & opens file and prints the contents to stdout */
        else if(actionPerformed == 3){
            
            printf("1. Read a file\n");
            printf("2. Back\n");
            printf("0. Exit\n");
            
            scanf("%d", &subMenuOption);
            if(subMenuOption == 1){
                printf("File path: ");
                scanf("%s", userFilePath);
                readfile(userFilePath);
                continue;
            }
            if(subMenuOption == 0){
                break;
            }
            if(subMenuOption == 2){
                continue;
            }
            else{
                printf("ENTER 1, 2, or 0\n");
                continue;
            }
        }
         
         //write to an existing file (in insert, append, or overwite mode)
         else if(actionPerformed == 4){
         
             printf("1. Write to a file\n");
             printf("2. Back\n");
             printf("0. Exit\n");
         
             scanf("%d", &subMenuOption);
             if(subMenuOption == 0){
                 break;
             }
             if(subMenuOption == 2){
                 continue;
             }
             if(subMenuOption == 1){
                 
                 printf("WRITE TO FILE MODE\n");
                 printf("1. Append\n");
                 printf("2. Insert\n");
                 printf("3. Overwrite\n");
                 printf("4. Back\n");
                 printf("0. Exit\n");
                 
                 scanf("%d", &writeModeMenuOption);
                 if(writeModeMenuOption == 0){
                     break;
                 }
                 if(writeModeMenuOption == 4){
                     continue;
                 }
                 if(writeModeMenuOption == 1){
                     
                     printf("1. Append\n");
                     printf("2. Back\n");
                     printf("0. Exit\n");
                     
                     scanf("%d", &appendMenuOption);
                     if(appendMenuOption == 1){
                         printf("Filepath: ");
                         scanf("%s", userFilePath);
                         append(userFilePath);
                         continue;
                     }
                     if(writeModeMenuOption == 2){
                         continue;
                     }
                     if(writeModeMenuOption == 0){
                         break;
                     }
                     else{
                         printf("ENTER 1, 2, or 0\n");
                         continue;
                     }
                     continue;
                 }
                 if(writeModeMenuOption == 2){
                     //insert
                     printf("1. Insert\n");
                     printf("2. Back\n");
                     printf("0. Exit\n");
                     
                     scanf("%d", &appendMenuOption);
                     if(appendMenuOption == 1){
                         printf("Filepath: ");
                         scanf("%s", userFilePath);
                         //insert(userFilePath);
                         continue;
                     }
                     if(appendMenuOption == 2){
                         continue;
                     }
                     if(appendMenuOption == 0){
                         break;
                     }
                     else{
                         printf("ENTER 1, 2, or 0\n");
                         continue;
                     }
                     continue;
                 }
                 if(writeModeMenuOption == 4){
                     //overWrite
                     printf("1. Overwrite\n");
                     printf("2. Back\n");
                     printf("0. Exit\n");
                     
                     scanf("%d", &appendMenuOption);
                     if(appendMenuOption == 1){
                         printf("Filepath: ");
                         scanf("%s", userFilePath);
                         overWrite(userFilePath);
                         continue;
                     }
                     if(appendMenuOption == 2){
                         continue;
                     }
                     if(appendMenuOption == 0){
                         break;
                     }
                     else{
                         printf("ENTER 1, 2, or 0\n");
                         continue;
                     }
                     continue;
                 }
                 else{
                     printf("ENTER 1, 2, 3, 4, or 0\n");
                     continue;
            }
        }
        //print file status
        else if(actionPerformed == 5){
            
            printf("1. Print File Status\n");
            printf("2. Back\n");
            printf("0. Exit\n");
            
            scanf("%d", &subMenuOption);
            if(subMenuOption == 1){
                printf("File path: ");
                scanf("%s", userFilePath);

                printfilestatus(userFilePath);
                continue;
            }
            if(subMenuOption == 0){
                break;
            }
            if(subMenuOption == 2){
                continue;
            }
            else{
                printf("ENTER 1, 2, or 0\n");
                continue;
            }
        }
         }

        //print directory listing
        else if(actionPerformed == 6){
            
            printf("1. Print Directory Listing\n");
            printf("2. Back\n");
            printf("0. Exit\n");
            
            scanf("%d", &subMenuOption);
            if(subMenuOption == 1){
                printf("File path: ");
                scanf("%s", userFilePath);
            
                printdirlisting(userFilePath);
                continue;
            }
            if(subMenuOption == 0){
                break;
            }
            if(subMenuOption == 2){
                continue;
            }
            else{
                printf("ENTER 1, 2, or 0\n");
                continue;
            }
        }
         } while (actionPerformed != 0);
}

