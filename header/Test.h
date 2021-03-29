/******************************************************************************************/
/* File: Test.h. This is the header file for the Test class. This class is    */
/* one of the leaves of the Rshell system. Will print to console True if the evaluation of the test is possible and False if not.  */
/* Author: Manveer Saini                                                                  */
/******************************************************************************************/



#ifndef TEST_H
#define TEST_H

#include "Executable.h"
#include <unistd.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

class TestCommand : public Executable {
    public:

        TestCommand(const char* flag, char* const path[]) : Executable(flag, path){
            this->flag = flag;
            this->path = path;
        }
        
        
        int evaluate(int status){
            struct stat buf;
            stat(path[1], &buf);
            mode_t mode_pathname = buf.st_mode;

           // if (existence(path[2], buf)){ //Path exist
               // cout << "(True)" << endl;
               // cout << "Path exists" << endl;

                if(path[0] == "-e"){
                     if (existence(path[1], buf)){
                         cout << "(True)" << endl;
                     }  
                     else{
                         cout << "(False)" << endl;
                     }
                }
                else if (path[0] == "-f"){
                    if (isFile(mode_pathname)){
                        cout << "(True)" << endl;
                    }
                    else{
                        cout << "(False)" << endl;
                    }
                }
                else if (path[0] == "-d"){
                    if (isDir(mode_pathname)){
                        cout << "(True)" << endl;
                    }
                    else{
                        cout << "(False)" << endl;
                    }
                }
           // }
           // else{
             //   cout << "(False)" << endl;
           // }
             
            return 0;
        }
                
    private: 
        bool isDir(mode_t someMode){
            return S_ISDIR(someMode);
        }

        bool isFile(mode_t someMode){
            return S_ISREG(someMode);
        }

        bool existence(char* pathName, struct stat buf){
            bool existence = false; 

            if (stat(pathName, &buf) == 0){
                existence = true;
            }    
                                                    
            return existence;
        }

        const char* flag;
        char* const* path;
};

#endif

//TODO: Nothing
