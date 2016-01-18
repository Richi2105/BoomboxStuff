//============================================================================
// Name        : typelength.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define PRINTSIZE(type) cout << "size of " << #type << ": " << size##type << endl;

#define GETSIZE(type) int size##type = sizeof(type); \
		PRINTSIZE(type)


int main() {
	cout << "Memory sizes of different types: " << endl;

	enum enumType {ZERO, ONE, TWO, THREE};

	GETSIZE(enumType);

	GETSIZE(bool);
	GETSIZE(char);
	GETSIZE(short);
	GETSIZE(int);
	GETSIZE(long);

	int sizelonglong = sizeof(long long);
	PRINTSIZE(longlong);

	GETSIZE(float);
	GETSIZE(double);


	return 0;
}
