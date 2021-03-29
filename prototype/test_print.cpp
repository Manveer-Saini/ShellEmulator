#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main (int argc, char* argv[]){
	
	cout << "test_print: My pid is " << getpid() << endl;
	pid_t pid = fork();
	
	if (pid < 0) {  // failure if child process was not created
		perror("fork failed.");
		exit(1);
	}
	if (pid == 0) { // success of child process creation in fork
			cout << "test_print: My pid is " << getpid() << endl;
			execvp(argv[1], argv);
			
	}
	
	cout << "I am the parent. waiting for child to complete.\n";
	waitpid(pid, NULL, 0); // parent process waits for child process to end or exit.
	cout << "Parent exiting.\n";
	
	return 0;
} 
