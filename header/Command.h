/******************************************************************************************/
/* File: Command.h. This is the header file for the Command class. This class is a        */
/* composite which will hold Executable and Connector objects.                            */
/* Author: John Palacios                                                                  */
/******************************************************************************************/

#ifndef COMMAND_H
#define COMMAND_H

#include "ProtoIn.h"
#include <vector>
using namespace std;

class Command : public ProtoIn {
    public:
    	Command() { status = 0; }
    	virtual int evaluate(int status) { 
    		for(auto e : list){ status = e->evaluate(status); } 
    		return status;
    	}

        void Add(ProtoIn* someExecutable){
            list.push_back(someExecutable);
        }
    
        ProtoIn* GetChild(int someChild){
            return list.at(someChild);    
        }    
    private:
    	vector<ProtoIn*> list;
    	int status;
};

#endif // !COMMAND_H
