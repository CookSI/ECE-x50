/*
 * dequeaslist.cpp
 *	 Purpose: Tester file for playlist class
    Read commands from standard input and writes  the  output  to  standard  output
 *  Created on: Feb 8, 2021
 *
 */


#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
#include "dequeaslist.h"

int main(){

	string command, Url, name;

	while(command != "exit"){
		cout << "Enter a command" << endl;
		cin >> command;
		Browser_historyDQ BHDQ;

		if(command == "push_front"){
			cin >> name;
			cin >> Url;
			cout << BHDQ.Push_front(name, Url);
		}

		if(command == "print"){
				cout << BHDQ.Print();
		}
	}

	return 0;
}




