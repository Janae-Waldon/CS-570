Prithipal Khalsa, cssc1182
Leonardo Gomez, cssc1194
Janae Waldon, cssc1183

1) File manifest (name of all files included in this project):
  a2.c
  a2.h
  main.c

2) Compile instructions:
	open the file & type 'make' into the command line

3) Operating instructions (include any/all command line options/arguments, required inputs, etc):
    - Program will output a Menu, the user will have to input the number they want.
    Ex:
    Hello, what would you like to do?
    1. Create a new directory
    2. Create a new file
    3. Read a file
    4. Write to a file
    5. Print file status
    6. Print directory listing
    0. Exit
    (user will have to enter a number 0-6 depending on the option they want)
    
    - Once a user chooses a menu, a sub-menu will appear giving the user the ability to go back, exit and proceed with menu.
    Ex:
    1. Create new directory
    2. Back
    0. Exit

4) List/description of novel/significant design decisions:
	Writing:
	  - when writing to a file the user is restricted to how much he/she can write.
	  - Program will stop if the user inputs a word longger than 100 characters.
	  - Program will stop if the user inputs a sentence longer than 100 words.
    Path:
      - All the functions that require user input will require the user to enter path, if path is not specified it will default to current path.
		Ex: When the user runs the file the following outputs will happen.
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

	Sort:
		When the user writes to a file, two files are more files are created one sorted alphabetically and the other sorted backwards.
		Ex: if user writes to file "file.txt" the program should output the following
		
		file.txt (original file)
		file.txt.bak (Sorted file alphabetically)
		reversesortedfile.txt.bak (sorted alphabetically in reverse order)
		
		Note: The file that is sorted alphabetically will apend .bak to the file, but the reverse order will add "reversesorted" at the begining of the file.
		
	Functions:
		void insert(char* filename, long offset): 
			- If the user chooses an offset that exceed the number of characters in the file, it will just append to the end.
			- the offset starts from the beginning of the file.
		void overWrite(char* filename):
			- it will delete the previous written data on the file before instering new data.

5) List/description of any extra features/algorithms/functionality you included which were not required:

6) List/description of all known deficiencies or bugs:
	- If the user enters a letter instead of a number it will give an infinite loop.
	- Some sub-menus do not have a mechanism to prevent the program from crashing if the user puts the wrong input.
	- If the user writes to file inside a directory it will name the reverse order as "file.txtreverseorder.bak" instead of "reverseorderfile.txt.bak"

7) Lessons Learned:
	 We learned to implement a multi-processing file editor with the following functions:
	 1. Create new directory files
	 2. Create new regular files
	 3. Create child process to write sorted output
	 4. Create child process to shadow write/read regular files
	 5. Read from a file (print out to stdout)
	 6. Write to a file in either insert, append, or overwrite mode
	 7. Print file status (print out to stdout)
	 8. Print directory listing (contents of dir file) (print out to stdout)
