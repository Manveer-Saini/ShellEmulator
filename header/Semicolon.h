/******************************************************************************************/
/* File: Semicolon.h. This is the header file for the Semicolon class. This class is a    */
/* decorator for the Executable class. Semicolon does not alter Connectors def of evaluate*/
/* Author: John Palacios                                                                  */
/******************************************************************************************/

#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Connector.h"

class Semicolon : public Connector {
public:
	Semicolon(ProtoIn* c) : Connector(c) {}

private:

};

#endif // !SEMICOLON_H