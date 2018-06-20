#include "a2.c"

int main(int argc, char const *argv[]){
    
    int actionPerformed, stringCompared;
    char buffer[] = " ";
    char help[] = "help";
    
    char userDirectoryName[] = " ";
    char userFileName[] = " ";
    
//    do{
        printf("Hello, what would you like to do?\n");
        printf("1. Create a new directory\n");
        printf("2. Create a new file\n");
        printf("3. Sort a file\n");
        printf("4. Read/Write to shadow file\n");
        printf("5. Read an exitsing file\n");
        printf("6. Write to a existing file\n");
        printf("7. Print file status\n");
        printf("8. Print directory listing\n");
        printf("9. Exit\n");
        printf("0. Help\n");
    
        
        
        //scanf("%d", &actionPerformed);
 //       scanf("%s", buffer);
    
        // stringCompared = strncmp(buffer, help, 1);
    
        //gives help message when user types help
        //if(stringCompared == 0){


//        //check for one argument in the command line(throwing exception)
//        if(strlen(buffer) != 1 &&  ! isdigit(atoi(buffer)){
//            printf("Please enter ONE NUMBER into the command line.\n");
//        }else{printf("im going here");}
//            //scan userInput and store it in variable
//
//        //create directory
//        if(actionPerformed = 1){
//            printf("New directory name: ");
//            scanf("%s", userDirectoryName);
//            createDirectory(userDirectoryName);
//        }
//        //create file
//        if(actionPerformed = 2){
//            printf("New filename: ");
//            //scan & store
//            createfile(userFilename);
//        }
//        //sort file
//        if(actionPerformed = 3){
//            printf("Enter the filename you would like to sort: ");
//            //scan & store
//            sortalpha();
//        }
//        //read/write to shadow
//        if(actionPerformed = 4){
//            printf("                     WHAT?                            ");
//            //scan & store
//            shadow();
//        }
//        //read an existing file
//        if(actionPerformed = 5){
//            printf("Filename: ");
//            //scan & store
//            readfile(userFilename);
//        }
//        //write to an existing file
//        if(actionPerformed = 6){
//            printf("Filename: ");
//            //scan & store
//            writefile(userFilename);
//        }
//        //print file status
//        if(actionPerformed = 7){
//            printf("Filename: ");
//            //scan & store
//            printfilestatus(userFilename);
//        }
//        //print directory listing
//        if(actionPerformed = 8){
//            printf("Directory name: ");
//            //scan & store
//            printdirlisting(userFilename);
//        }
//        //print directory listing
//        if(actionPerformed = 0){
//            printf("On the command line, type the number that corresponds to the action you want to be performed. For Example, if you would like to write to a file, you would type '6'. (Note only one parameter is excepted at a time.)\n For name, type in whatever filename or directory name you want. For example, when prompted for name, type 'Myfile' or 'Directory Name'\n");
//        }
//    }
//    } while (actionPerformed != 9);
}
