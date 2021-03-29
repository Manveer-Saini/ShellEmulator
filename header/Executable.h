/******************************************************************************************/
/* File: Executable.h. This is the header file for the Executable class. This class is    */
/* one of the leaves of the Rshell system. forks process, calls execvp on call evaluate.  */
/* Author: John Palacios                                                                  */
/******************************************************************************************/

#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "ProtoIn.h"
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

class Executable : public ProtoIn {
public:
	Executable(const char* file, char* const argv[]) : file(file), argv(argv) {}
	virtual int evaluate(int stat) {
		int status = 0;
		int returnVal;
		pid_t pid = fork();

		if (pid < 0) {  // failure if child process was not created
			perror("fork failed.");
			exit(1);
		}
		if (pid == 0) { // success of child process creation in fork
			if (execvp(file, argv) == -1) {
				perror("execvp failed");
				exit(-1);
			}
			
		}
		else{
			if (waitpid(pid, &status, 0) == -1) {	// parent process waits for child process to end or exit, status
				perror("waitpid failure");			// of 0 indicates success.
			}
			if (WIFEXITED(status)){ 
				returnVal = WEXITSTATUS(status);	// Masks for all but the return value, which we want.
				return (returnVal != 0 ? -1 : 0);
			}
			return returnVal;
		}
		//Returns in else block now.
		/*exit(-1);*/
	}

private:
	const char* file;
	char* const* argv;
};

#endif // !EXECUTABLE_H
