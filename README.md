Prithipal Khalsa, cssc1182
Leonardo Gomez, cssc1194
Janae Waldon, cssc1183

File manifest (name of all files included in this project):
  a2.c
  a2.h
  main.c

Compile instructions:

Operating instructions (include any/all command line options/arguments, required inputs, etc):

List/description of novel/significant design decisions:
Functions:
void insert(char* filename, long offset): 
  - If the user chooses an offset that exceed the number of characters in the file, it will just append to the end.
  - the offset starts from the beginning of the file.
void overWrite(char* filename):
  - it will delete the previous written data on the file before instering new data.

List/description of any extra features/algorithms/functionality you included which were not required:

List/description of all known deficiencies or bugs:

Lessons Learned:
