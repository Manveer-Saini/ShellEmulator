/******************************************************************************************/
/* File: Exit.h. This is the header file for the Exit class. This is a special subclass   */
/* of the Executable class which simply calls exit when evaluate is called.               */
/* Author: John Palacios                                                                  */
/******************************************************************************************/

#ifndef EXIT_H
#define EXIT_H

#include "Executable.h"

class Exit : public Executable {
public:
	Exit(const char* file, char* const argv[]) : Executable(file, argv) {}
	virtual int evaluate(int stat) { _exit(0); }

private:

};

#endif // !EXIT_H
