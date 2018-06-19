
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

int writefile(char* filename){
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
    else{
    printf("\n Fork failed, quitting.\n");
    return 1;
    }
     return 0;
}



void printfilestatus(){

}

void printdirlisting(){

}

void sortalpha(){

}

void reversesortalpha(){

}
