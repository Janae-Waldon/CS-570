#include "a2.h"

int actionPerformed; // this is the user input

char userFilePath[] = " "; //this is to take the files and dirs

void createfile(char* filename){
    FILE *fp;
    fp=fopen(filename,"w");
    fclose(fp);
    return ;
} //This is the funtion that creates the file

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
} //this is the funtion that reads the file

int writefile(char* filename)// this is the funtion that writes the file
{
    pid_t childPID = fork();

    if(childPID >= 0) {
      if(childPID == 0){
          sortalpha(filename);
      }
      else{
          reversesortalpha(filename);
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

    if(fp != NULL){
    //gets the user input into a buffer, then writes it to the specified file
      printf("What would you like to append: ");
      scanf (" %[^\n]%*c", towrite);
      fprintf (fp,"%s", towrite);

      fclose(fp);
    }
    else {
      printf("The File/Path cannot be opened \n");
    }
    return;
} //this well add on to the end of the file

void insert(char* filename, long offset){
    FILE * fp;
    char towrite[80];
    /* open the file for writing */
    fp = fopen (filename,"r+");
    if(fp != NULL){
      /* write 10 lines of text into the file stream*/
      scanf (" %[^\n]%*c", towrite);
      /* Moves to the specified offset to insert text */
      fseek(fp, offset, SEEK_SET);
      fprintf (fp,"%s", towrite);

      /* close the file*/
      fclose (fp);
    }
    else {
      printf("The File/Path cannot be opened \n");
    }
    return;
} //this will insert user input into a user specified place

void overWrite(char* filename){
    FILE * fp;
    char towrite[80];
    /* open the file for writing*/
    fp = fopen (filename,"w");
    if(fp != NULL){
      /* write 10 lines of text into the file stream*/
      scanf (" %[^\n]%*c", towrite);
      //scanf(stdin, "%s", towrite);
      fprintf (fp,"%s", towrite);

      /* close the file*/
      fclose (fp);
    }
    else {
      printf("The File/Path cannot be opened \n");
    }
} //this is used to overwrite the file entirely

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
}// this will make a new dir

void printfilestatus(char* filename){
    struct stat info;
    FILE *fp = fopen(filename, "r");
    if(fp != NULL){
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
    else {
      printf("The File/Path cannot be opened \n");
    }
}// this will print the file status

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
}//this will print the files inside a ditr
int cmp(const void *a, const void *b){
    return strcmp(*(char**)a, *(char**)b);
} //this is used as a comparer for the sort funtions
void sortalpha(char* filename){
  FILE *fp = fopen(filename, "r");
  char src[50], dest[50];
  strcpy(dest,filename);
  strcpy(src,".bak");
  strcat(dest,src);


  FILE *newAlphaFile=fopen(dest,"w");
      char text[256];
      char *words[100];
      char *word;
      int wmax=0, i;
      fscanf(fp,"%[^\0]", text);
      for(word = strtok(text, " "); word ; word = strtok(NULL, " ")){
          words[wmax++] = word;
      }
      qsort(words, wmax, sizeof(*words), cmp);
      for(i=0;i<wmax;++i)
          fprintf(newAlphaFile, "%s ", words[i]);

          fclose(fp);
          fclose(newAlphaFile);
          return;

}// this will create a new file in sorted order

void reversesortalpha(char* filename){

        FILE *fp = fopen(filename, "r");
        char src[50], dest[50];
        strcpy(dest,filename);
        strcpy(src,"reversed.bak");
        strcat(dest,src);


        FILE *newAlphaFile=fopen(dest,"w");
            char text[100];
            char *words[100];
            char *word;
            int wmax=0, i;
            fscanf(fp,"%[^\0]", text);
            for(word = strtok(text, " "); word ; word = strtok(NULL, " ")){
                words[wmax++] = word;
            }
            qsort(words, wmax, sizeof(*words), cmp);
            for(i=wmax-1;i>0;i--)
                fprintf(newAlphaFile, "%s ", words[i]);
      fclose(fp);
      fclose(newAlphaFile);
            return;
}// this will create a new file in reverse sorted order

void mainmenu(){
  printf("Hello, what would you like to do?\n");
  printf("1. Create a new directory\n");
  printf("2. Create a new file\n");
  printf("3. Read a file\n");
  printf("4. Write to a file\n");
  printf("5. Print file status\n");
  printf("6. Print directory listing\n");
  printf("0. Exit\n");


  scanf(" %d", &actionPerformed);
  if(actionPerformed == 1){
    printf("Directoryname: ");
    scanf(" %s", userFilePath);
    createDirectory(userFilePath);
    mainmenu();
  }
  if(actionPerformed == 2){
    printf("File path: ");
    scanf(" %s", userFilePath);
    createfile(userFilePath);
    printf("File has been added to filepath.\n");
    mainmenu();

  }
  if(actionPerformed == 3){
    printf("File path: ");
    scanf(" %s", userFilePath);
    readfile(userFilePath);
    mainmenu();
  }
  if(actionPerformed == 4){
    writefilemenu();
  }
  if(actionPerformed == 5){
    printf("File path: ");
    scanf(" %s", userFilePath);
    printfilestatus(userFilePath);
    mainmenu();
  }
  if(actionPerformed == 6){
    printf("File path: ");
    scanf(" %s", userFilePath);
    printdirlisting(userFilePath);
    mainmenu();
  }
  if(actionPerformed == 0){
    exit;
  }
}//this will run through the main menu
void writefilemenu(){
  printf("WRITE TO FILE MODE\n");
  printf("1. Append\n");
  printf("2. Insert\n");
  printf("3. Overrite\n");
  printf("5. Back\n");
  printf("0. Exit\n");
  long place=0;
  scanf(" %d", &actionPerformed);
  if(actionPerformed == 1){
    printf("Filepath: ");
    scanf(" %s", userFilePath);
    append(userFilePath);
    writefile(userFilePath);
  }
  if(actionPerformed == 2){
    printf("Filepath: ");
    scanf(" %s", userFilePath);
    printf("Place to insert: ");
    scanf("%ld",&place);
    insert(userFilePath,place);
    writefile(userFilePath);
  }
  if(actionPerformed == 3){
    printf("Filepath: ");
    scanf(" %s", userFilePath);
    overWrite(userFilePath);
    writefile(userFilePath);
  }
  if(actionPerformed == 5){
    mainmenu();
  }
  if(actionPerformed == 0){
    exit;
  }
} //this will be the submenu for the write choices
