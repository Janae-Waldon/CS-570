Prithipal Khalsa, cssc1182
Leonardo Gomez, cssc1194
Janae Waldon, cssc1183

1) File manifest (name of all files included in this project):
  a2.c
  a2.h
  main.c

2) Compile instructions:

3) Operating instructions (include any/all command line options/arguments, required inputs, etc):

4) List/description of novel/significant design decisions:
Path:
- All the functions that require user input will require the user to enter path, if path is not specified it will default to current path.
  ex: When the user runs the file the following outputs will happen.
  Menu
  Hello, what would you like to do?
  1. Create a new directory
  2. Create a new file
  3. Read a file
  4. Write to a file
  5. Print file status
  6. Print directory listing
  0. Exit
  USER: 1
  
  1. Create new directory
  2. Back
  0. Exit
  
  USER: 1
  
  File Path: dir/file.txt     (this will put "file.txt" inside the directory name "dir")

  

Functions:
void insert(char* filename, long offset): 
  - If the user chooses an offset that exceed the number of characters in the file, it will just append to the end.
  - the offset starts from the beginning of the file.
void overWrite(char* filename):
  - it will delete the previous written data on the file before instering new data.

5) List/description of any extra features/algorithms/functionality you included which were not required:

6) List/description of all known deficiencies or bugs:

7) Lessons Learned: