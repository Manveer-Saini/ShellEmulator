/******************************************************************************************/
/* File: Connectable.h. This is the header file for the Connector base class. Each of the */
/* decorators (Ampersands, Pipes, Semicolon) will inherit from this class.                */
/* Author: John Palacios                                                                  */
/******************************************************************************************/

#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "ProtoIn.h"
#include "Executable.h"

class Connector : public ProtoIn {
public:
	Connector(ProtoIn* c) : ProtoIn() { child = c; }
	~Connector() { delete child; }
	virtual int evaluate(int status) { return child->evaluate(status); }

protected:
	ProtoIn* child;
};

#endif // !CONNECTOR_H