#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void createfile(char* filename);

void readfile(char* filename);

int writefile(char* filename);

void printfilestatus(char* filename);

void printdirlisting(char* filedir);

void sortalpha();

void reversesortalpha();
