/******************************************************************************************/
/* File: ProtoIn.h. This is the header file for the ProtoIn class. This class is the base */
/* class for Connector, Command, and Executable classes. Proto input class.               */
/* Author: John Palacios                                                                  */
/******************************************************************************************/

#ifndef PROTOIN_H
#define PROTOIN_H

class ProtoIn {
public:
	ProtoIn() {}
	int virtual evaluate(int status) = 0;

private:

};

#endif // !PROTOIN_H