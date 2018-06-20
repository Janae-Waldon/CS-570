#ifndef A2_H
#define A2_H

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

void createfile(char* filename);
void readfile(char* filename);
int writefile(char* filename);
void append(char* filename);
void insert(char* filename, long offset);
void overWrite(char* filename);
void printfilestatus(char* filename);
void printdirlisting(char* filedir);
void performMenuInstructions();
void sortalpha();
void menu();

void reversesortalpha();

#endif
