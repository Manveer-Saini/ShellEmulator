/******************************************************************************************/
/* File: main.cpp. This file is the entry point for the RShell program.                   */
/* Author: John Palacios                                                                  */
/*                                                                                        */
/******************************************************************************************/

// TODO: REMOVE COMMENTED OUT TEST CODE ONCE EVERYTHING IS WORKING PROPERLY.

#include <iostream>
#include <string>
#include <vector>
#include "../header/Connector.h"
#include "../header/Exit.h"
#include "../header/Command.h"
#include "../header/Executable.h"
#include "../header/Semicolon.h"
#include "../header/Pipes.h"
#include "../header/Ampersands.h"
#include "../header/ProtoIn.h"
#include "../header/Test.h"
//#include "../header/RShell.h"				// Not ready yet
using namespace std;

// Strips userString of comments (erases string starting at #)
string commentParser(string userString);

// Takes in a string and returns a vector containing words without whitespace
vector<string>* chopString(string userString);

// Returns true for white space characters, false otherwise
bool isWhiteSp(char userChar);

// Converts a vector of strings into a two dimensional char array.
// Quotation marks will be stripped out of char arrays.
char** buildCharArr(vector<string>* userString);

// Returns true for strings containing quotation marks.
bool constainsQuote(string userString);

// Returns true for string containing semicolon.
bool containsSemicolon(string userString);

// Returns userString without qotation marks.
string removeQuote(string userString);

// Returns userString without semicolon marks.
string removeSemicolon(string userString);

// Returns true if userString is "&&" or "||"
bool isConnector(string userString);

// takes user string
// Returns a vector of two dimensional char pointers
vector<char**>* argumentize(string userString);

// arguments[0] = "&&" => returns 1
// arguments[0] = "||" => returns 2
// arguments[i] = ";" => returns 3, -1 < i < n + 1
// arguments[0] = "exit" => returns 4
// else returns 0
int getCase(char** arguments);

bool charCompAmp(char* argument);

bool charCompPip(char* argument);

bool charCompExt(char* argument);

bool charCntSemi(char* argument);

char* charRmvSemi(char* argument);

string moveSemicolons(string userString);

// Uncomment parts that rely on linux system calls once on hamer
// takes case number (as above) an builds the appropriate 
// object int he RShell system. Use this fxn to add children
// to Command object.
ProtoIn* buildObject(int buildCase, char** arguments);


int main() {
	// Declare variables here
	string userIn;						// Holds user input to be executed by rshell.
	//string noComments;
	//vector<string>* parsed;
	vector<char**>* args;
	char** arr;
	int length;

	// Begin program operations here
	while (true) {
		cout << "$ ";
		getline(cin, userIn);
		Command* line = new Command();
		args = argumentize(userIn);
		length = args->size();
		for (int i = 0; i < length; i++) {
			line->Add(buildObject(getCase(args->at(i)), args->at(i)));
		}

		line->evaluate(0);
		delete line;
		line = nullptr;
	}
	//noComments = commentParser(userIn);
	//parsed = chopString(noComments);
	//length = parsed->size();
	//arr = buildCharArr(parsed);


	//for (int i = 0; i < length; i++) {
	//	/*cout << parsed->at(i) << "." << endl;
	//	if (constainsQuote(parsed->at(i))) { parsed->at(i) = removeQuote(parsed->at(i)); }
	//	cout << parsed->at(i) << "." << endl;*/
	//	cout << arr[i] << "." << endl;
	//}

	/*args = argumentize(userIn);
	length = args->size();
	for (int i = 0; i < length; i++) {
		int j = 0;
		while (args->at(i)[j] != NULL) {
			cout << *(args->at(i) + j) << endl;
			j++;
		}
	}*/

	// Will build objects by switching on arg[0],
	// pass *arg[1] and arg[1] to object durring construction
	// or create new char** args starting with arg[1] and
	// continuing to NULL.



	return 0;
}

string commentParser(string userString) {
	string noComments;
	int length = static_cast<int>(userString.size());

	for (int i = 0; i < length; i++) {
		if (userString.at(i) != '#') {
			noComments += userString.at(i);
		}
		else { break; }
	}

	return noComments;
}

vector<string>* chopString(string userStrg) {
	vector<string>* chopdString = new vector<string>();
	string userString = moveSemicolons(userStrg);

	for (int i = 0; i < static_cast<int>(userString.size()); i++) {	// Search the string for white space chars
		if (isWhiteSp(userString.at(i))) {							// if is white space, push substring
			chopdString->push_back(userString.substr(0, i));		// onto vector and delete from user string
			userString = userString.erase(0, i);
			i = 0;
			while ((isWhiteSp(userString.at(i))) && i < static_cast<int>(userString.size())) {
				i++;												// Continue to remove white spaces
				userString = userString.erase(0, i);				// if there are more than one
				i = 0;
				if (userString.empty()) {
					break;
					break;
				}
			}
		}
	}

	if (!userString.empty()) { chopdString->push_back(userString); }

	return chopdString;
}

bool isWhiteSp(char userChar) {
	return (userChar == ' ' || userChar == '\t' || userChar == '\n');
}

char** buildCharArr(vector<string>* userString) {
	const int length = static_cast<int>(userString->size() + 1);
	char** args = new char*[length];								// Pointer to a two d char array

	for (int i = 0; i < length - 1; i++) {
		userString->at(i) = removeQuote(userString->at(i));			// Strip quotation marks
		args[i] = const_cast<char*>(userString->at(i).c_str());		// Assign clean string to args[i]
		args[i][userString->at(i).size()] = '\0';
	}

	args[length - 1] = NULL;

	return args;
}

bool constainsQuote(string userString) {
	int length = static_cast<int>(userString.size());

	for (int i = 0; i < length; i++) {
		if (userString.at(i) == '"') { return true; }
	}

	return false;
}

bool containsSemicolon(string userString) {
	int length = static_cast<int>(userString.size());

	for (int i = 0; i < length; i++) {
		if (userString.at(i) == ';') { return true; }
	}

	return false;
}

string removeQuote(string userString) {
	for (int i = 0; i < static_cast<int>(userString.size()); i++) {
		if (userString.at(i) == '"') {
			userString = userString.erase(i, 1);
		}
	}

	return userString;
}

string removeSemicolon(string userString) {
	for (int i = 0; i < static_cast<int>(userString.size()); i++) {
		if (userString.at(i) == ';') {
			userString = userString.erase(i, 1);
		}
	}

	return userString;
}

bool isConnector(string userString) {
	if (static_cast<int>(userString.size()) < 2) { return false; }
	return ((userString.at(0) == '&' && userString.at(1) == '&')
		|| (userString.at(0) == '|' && userString.at(1) == '|'));
}

string moveSemicolons(string userString) {
	string newString;
	int length = static_cast<int>(userString.size());

	for (int i = 0; i < length; i++) {
		if (userString.at(i) == ';') { newString += ' '; }
		newString += userString.at(i);
	}
	return newString;
}

vector<char**>* argumentize(string userString) {
	vector<char**>* arguments = new vector<char**>();
	vector<string>* choppedString;
	vector<string>* temp;
	bool ignoreConnector = false;
	bool ignoreIndex = false;

	userString = commentParser(userString);		// Strip comments from user input
	choppedString = chopString(userString);		// break user input into words

	for (int i = 0; i < static_cast<int>(choppedString->size()); i++) {
		if (constainsQuote(choppedString->at(i)) && !ignoreConnector) {
			ignoreConnector = !ignoreConnector;
			ignoreIndex = !ignoreIndex;
		}
		if (constainsQuote(choppedString->at(i)) && ignoreConnector && !ignoreIndex) { ignoreConnector = false; }
		if ((isConnector(choppedString->at(i)) || containsSemicolon(choppedString->at(i))) && !ignoreConnector) {
			arguments->push_back(buildCharArr(new vector<string>(choppedString->begin(), choppedString->begin() + i)));
			choppedString->erase(choppedString->begin(), choppedString->begin() + i);
			i = 0;
		}
		if (ignoreIndex) { ignoreIndex = !ignoreIndex; }
	}

	if (!choppedString->empty()) {
		arguments->push_back(buildCharArr(new vector<string>(choppedString->begin(), choppedString->end())));
	}

	return arguments;
}

bool charCompAmp(char* argument) { return (argument[0] == '&' && argument[1] == '&'); }

bool charCompPip(char* argument) { return (argument[0] == '|' && argument[1] == '|'); }

bool charCompExt(char* argument) {
	string exit = "exit";
	for (int i = 0; i < 4; i++) {
		if (argument[i] != exit.at(i)) {
			return false;
		}
	}
	return true;
}

bool charCntSemi(char* argument) {
	int i = 0;
	while (argument[i] != '\0') {
		if (argument[i] == ';') { return true; }
		i++;
	}
	return false;
}

char* charRmvSemi(char* argument) {
	int i = 0;
	while (argument[i] != '\0') {
		if (argument[i] == ';') {
			argument[i] = '\0';
			return argument;
		}
		i++;
	}
	return argument;			// May be called on char pointer without semicolon.
}

int getCase(char** arguments) {
	int i = 0;
	while (arguments[i] != NULL) {
		if (charCompAmp(arguments[0]) && charCompExt(arguments[i])) { return 5; }
		i++;
	}
	i = 0;
	while (arguments[i] != NULL) {
		if (charCompPip(arguments[0]) && charCompExt(arguments[i])) { return 6; }
		i++;
	}
	i = 0;
	while (arguments[i] != NULL) {
		if (charCntSemi(arguments[0]) && charCompExt(arguments[i])) { return 7; }
		i++;
	}
	i = 0;
	if (charCompAmp(arguments[0])) { return 1; }
	if (charCompExt(arguments[0])) { return 4; }
	while (arguments[i] != NULL) {
		if (charCntSemi(arguments[i])) { return 3; }
		i++;
	}
	if (charCompPip(arguments[0])) { return 2; }	// Disorder is intentional
	else { return 0; }
}

ProtoIn* buildObject(int buildCase, char** arguments) {
	int length = 0;

	while (arguments[length] != NULL) {
		length++;
	}
	length++;

	switch (buildCase) {
	case 1: {		// Ampersands case
		char** args = new char*[length - 1];
		for (int i = 0; i < length - 1; i++) { args[i] = arguments[i + 1]; }
		const char* file = args[0];
		ProtoIn* temp = new Executable(file, args);
		temp = new Ampersands(temp);
		return temp;
		break;
	}
	case 2: {		// Pipes case
		char** args = new char*[length];
		for (int i = 0; i < length - 1; i++) { args[i] = arguments[i + 1]; }
		const char* file = args[0];
		ProtoIn* temp = new Executable(file, args);
		temp = new Pipes(temp);
		return temp;
		break;
	}
	case 3: {		// Semicolon case
		char** args = new char*[length];
		args = &arguments[1];
		/*for (int i = 0; i < length; i++) { charRmvSemi(args[i]); }*/
		const char* file = args[0];
		ProtoIn* temp = new Executable(file, args);
		temp = new Semicolon(temp);
		return temp;
		break;
	}
	case 4: {		// exit case
		char** args = new char*[length];
		args = &arguments[0];					//It doesn't matter
		const char* file = args[0];
		ProtoIn* temp = new Exit(file, args);
		return temp;
		break;
	}
	case 5: {		// Ampersands and exit case
		char** args = new char*[length - 1];
		for (int i = 0; i < length - 1; i++) { args[i] = arguments[i + 1]; }
		const char* file = args[0];
		ProtoIn* temp = new Exit(file, args);
		temp = new Ampersands(temp);
		return temp;
		break;
	}
	case 6: {		// Pipes and exit case
		char** args = new char*[length];
		for (int i = 0; i < length - 1; i++) { args[i] = arguments[i + 1]; }
		const char* file = args[0];
		ProtoIn* temp = new Exit(file, args);
		temp = new Pipes(temp);
		return temp;
		break;
	}
	case 7: {		// Semicolon and exit case
		char** args = new char*[length];
		args = &arguments[1];
		/*for (int i = 0; i < length; i++) { charRmvSemi(args[i]); }*/
		const char* file = args[0];
		ProtoIn* temp = new Exit(file, args);
		temp = new Semicolon(temp);
		return temp;
		break;
	}
	default: {
		char** args = new char*[length];
		args = &arguments[0];
		const char* file = args[0];
		ProtoIn* temp = new Executable(file, args);
		return temp;
		break;
	}
	}
}
