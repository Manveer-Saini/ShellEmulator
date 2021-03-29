/******************************************************************************************/
/* File: Pipes.h. This is the header file for the Pipes class. This class is a decorator  */
/* of the executable class. It will only pass through for failure status.                 */
/* Author: John Palacios                                                                  */
/******************************************************************************************/

#ifndef PIPES_H
#define PIPES_H

#include "Connector.h"

class Pipes : public Connector {
public:
	Pipes(ProtoIn* c) : Connector(c) {}
	virtual int evaluate(int status) { return status != 0 ? child->evaluate(status) : 0; }

private:

};

#endif // !PIPES_H
