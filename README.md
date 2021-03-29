# CS 100 RShell
Spring 2019 John Palacios SID 862041445, Manveer Saini SID 862018324

# Introduction
The RShell program will be able to perform the following:
   1. Print a command prompt
   1. Read in a line of commands and connectors from standard input
   1. Execute the appropriate commands using `fork()`, `execvp()`, and `waitpid()`

in the following format:
	$ executable [argumentList] [connector] [command] ... etc.
Any number of commands may be entered, separated by ||, &&, or ;. These are the only valid connectors. # followed by text will be treated as a comment, and not processed.
The executable will be located in the path specified in [argumentList], a space separated list.

The following design patterns are used:
   * Composite pattern
       * Each class will represent a command or operator in RShell
   * Decorator pattern
	   * Each Connector class: Ampersands, Pipes and Semicolon will be a decorator
	     class.
  
# Diagram

![Image of UML Class diagram](https://github.com/cs100/spring-2019-assignment-the-null-terminators/blob/master/images/Assignment%203.png)

# Classes
The client has a pointer to an object of type RShell. RShell has as a member a pointer to an command object, called line, of type ProtoIn. When the RShell object
recieves input from the command line, it parses the string and instantiates objects of the Executable, Connector, or Exit classes, as appropriate, and calls it's
Command object's add function with the instantiated Executables, Connectors, and Exit instantiated earlier, then calls Command's evaluate function.
Command's evaluate function calls each of it's child's evaluate function.
The Pipes, Ampersands and Semicolon classes are decorator classes that take or wrap children Executable objects and are later added to get added to a Command Object's list of commands to execute or evaluate. The TestCommand class is used to determine the existence of a path and when specified with the flag "-f" to determine if it is a regular file. Whereas the when specified with the flag "-d" this is used to determine if it is a directory. When the test command is run it should return a (True) if the test was succesful or (False) when the test was unsuccesful.


# Protypes and Research
   Notes on how waitpid(), execvp(), and fork() functions, connectors act in different situations behave in the shell normally.

Two .cpp files were created to study the effects of the functions mentioned above called "print.cpp" and "test_print.cpp". Our protoype function file used was test_print.cpp was used to fork a child process to execute the executable "print" via execvp. In the creation of the child process via fork() we discovered that if successfully created fork would return the PID of the child in the parent process whereas the child process would recieve a value of 0. Otherwise there would be a scenario in which the child process was not successfully created or forked by the parent the value -1 would be returned in the parent. Other detail worth mentioning would be that execvp() or any other variant of exec() should return a value (-1) if there is an error. The execvp() function takes a filename/pathname as the first argument to the function and n arguments afterwards for any arguments to the executable in our case being ./print . Essentially the test_print executable can take input (C-Strings) via command line and once the ./print is executed via execvp in ./test_print the output will be separated comma wise. At the end of all of this the parent process will be waiting for confirmation that the child process is finished or has exited. This is where the function waitpid() comes into play. Essentially waitpid() system call suspends execution of the calling process (parent process) until a child specified by a PID argument to the function changes. The function will wait for terminated children but the behavior can be modified via following the options on the waitpid() documentation.
 
Refer to Documentation/Sources: 

[waitpid()](https://linux.die.net/man/2/wait)
[fork()](https://linux.die.net/man/2/fork)
[execvp()](https://linux.die.net/man/3/execvp)

# Development and Testing Roadmap
   - [x] Create first draft of documentation in README.md
   - [x] Create Prototype/ directory in repo
   - [x] Write prototype code to test and demonstrate `fork()`, `execvp()`, `waitpid()`, and how connectors work on hammer.
   - [x] Create UML documentation for Composite classes to accomplish assignment 2 
   - [ ] prototype class design 
   
