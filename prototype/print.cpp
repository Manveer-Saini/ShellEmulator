#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

	for (int i = 1; i < argc - 1; i++){
		printf("%s, ", argv[i]);
	}
	
	
	cout << argv[argc - 1] << endl;
	 
	return 0;

}
