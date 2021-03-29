/******************************************************************************************/
/* File: Ampersands.h. This is the header file for the Ampersands class. This class is a  */
/* decorator of the Executable class. It will only pass through for success status.       */
/* Author: John Palacios                                                                  */
/******************************************************************************************/

#ifndef AMPERSANDS_H
#define AMPERSANDS_H

#include "Connector.h"

class Ampersands : public Connector {
public:
	Ampersands(ProtoIn* c) : Connector(c) {}
	virtual int evaluate(int status) { return status == 0 ? child->evaluate(status) : 0; }

private:

};

#endif // !AMPERSANDS_H