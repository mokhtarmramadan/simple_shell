# Introduction:
The simple shell project is a project for students of alx africa school and that project is the final project for the basics of c programming language , shell commands.The simple shell project is a simulation for the real shell of linux and it works with the same way which the real shell works with.
## Usage:
 In order to run this program,
 Clone This Repo
`https://github.com/mokhtarmramadan/simple_shell.git`
compile it with:
`gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o hsh`
 run it with `./hsh` command
## How to use it:
in order to use the sell program you will see a text which is:
`sash` you type any command you want beside that word
### Examples of commands which you can use:

- `ls` command:
you can use that command to list all files and directories in your folder or directory
- `env` command:
Displays the environment variable
- `exit` [exitstatus]
Exit from the program with exitstatus value. 0 by default.
## Files of simple shell:
- `shell.c`:
That is the main file of the project it has main code of the project which is:
	- code of the promot which has the word `sash`
	- code of `getline` function which get the input from the user
	- code of `check_getline` function which will check some important points:
		1. check if the `getline` function succeed or not
		2. check if the buffer array which has the input of the user has any spaces
		3. check if the command is `env` it will print the environment variable
	- code of arguments which are exist in any command for example `ls -l` or `touch Mo.c`
	- code of `execute` system call which will execute any command
- `print_env.c`:
  	It will print the environment in form of `key = value`
- `check_getline.c`:
	1. check if the `getline` function succeed or not
	2. check if the buffer array which has the input of the user has any spaces
	3. check if the command is `env` it will print the environment variable
	4. check if the input of the user is `exit` it will exit the program
- `check_getline.c`:
	1. check if the `getline` function succeed or not
	2. check if the buffer array which has the input of the user has any spaces
	3. check if the command is `env` it will print the environment variable
	4. check if the input of the user is `exit` it will exit the program
- `check_space.c`:
	Check if the input is only spaces without any letters or words
	if that function will find any letter it will return 1
- `contributors` :
	`Ahmed Elsharkwi`
	`Mokhtar M. Ramadan`
