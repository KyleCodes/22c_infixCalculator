#include <iostream>
#include <string>
#include "InFixCalculator.h"
using namespace std;






int main()
{
	string eq;
	int answer;
	InfixCalculator mathEngine;


	cout << "*********************************************" << endl;
	cout << endl;
	cout << "THIS PROGRAM DEMONSTRATES MATH USING STACKS" << endl;
	cout << "equations will be converted to strings" << endl;
	cout << "_____________________________________________" << endl;
	cout << endl;
	cout << "     Please enter a valid mathematic expression:" << endl;
	cout << endl;
	cout << "inputting" << endl;
	cout << "	";
	
	getline(cin, eq);

	cout << "Input was successful, passing to function" << endl;

	answer = mathEngine.PostFix(eq);

	cout << "operation successful, displaying answer:" << endl;

	cout << answer << endl;


	system("pause");
	return 0;
}