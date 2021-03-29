#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>

using namespace std;

bool existence(char* pathName, struct stat buf);

bool isDir(mode_t someMode);

bool isFile(mode_t someMode);

int main(int argc, char* argv[]){
    struct stat buf;
    struct stat buf2;
    struct stat buf3;

    char* fileName = "someFile.txt";
    char* directoryName = "someDir"; 
    char* invalidPathName = "something.dfd";

    stat(fileName, &buf); //file
    stat(directoryName, &buf2);  //directory
    stat(invalidPathName, &buf3); //invalid path

    mode_t mode_file = buf.st_mode;
    mode_t mode_directory = buf2.st_mode;
    mode_t mode_invalid_path = buf3.st_mode;
    
    //******FILE TEST****** 
    if (existence(fileName, buf)){
        cout << "(True)" << endl;
        if (isFile(mode_file)){
            cout << "This is a file." << endl;
        }
        else if(isDir(mode_file)){
            cout << "This is a directory" << endl;
        }
    }
    else{
        cout << "(False)" << endl;
    }
     
    //******DIRECTORY TEST****** 
    if (existence(directoryName, buf2)){
        cout << "(True)" << endl;
        if (isFile(mode_directory)){
            cout << "This is a file." << endl;
        }
        else if(isDir(mode_directory)){
            cout << "This is a directory" << endl;
        }
    }
    else{
        cout << "(False)" << endl;
    }
    
    //******INVALID PATH TEST******
    if (existence(invalidPathName, buf3)){
        cout << "(True)" << endl;
        if (isFile(mode_invalid_path)){
            cout << "This is a file." << endl;
        }
        else if(isDir(mode_invalid_path)){
            cout << "This is a directory" << endl;
        }
    }
    else{
        cout << "(False)" << endl;
    }    
     
    return 0;

    
}

bool isDir(mode_t someMode){

    return S_ISDIR(someMode);
   /* if (S_ISDIR(someMode))
        cout << "This is a directory" << endl;
    else
        cout << "This is not a directory" << endl;*/
}

bool isFile(mode_t someMode){
    return S_ISREG(someMode);
   /* if(S_ISREG(someMode))
        cout << "This is a file" << endl;
    else 
        cout << "This is not a file" << endl;*/    
}

bool existence(char* pathName, struct stat buf){
    bool existence = false; 

    if (stat(pathName, &buf) == 0){
        existence = true;
    }    
    else{
    }
    
    return existence;
}
