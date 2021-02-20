#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
#include "dequeaslist.h"

int main() {
    string name,command, url;
    Browser_historyDQ * BHDQ = new Browser_historyDQ();
    while(command != "exit"){
        //cout << "Enter a Command: ";
        cin >> command;
        //switch(){}
        if (command == "push_front") {
            std::getline(std::cin,name, '"');
            std::getline(std::cin,name, '"');
            std::getline(std::cin,url, '"');
            std::getline(std::cin,url, '"');
            cout << BHDQ->Push_front(name, url) << endl;
        }
        if (command == "push_back") {
            std::getline(std::cin,name, '"');
            std::getline(std::cin,name, '"');
            std::getline(std::cin,url, '"');
            std::getline(std::cin,url, '"');
            cout << BHDQ->Push_back(name, url) << endl;
        }
        if (command == "empty") {
            cout << "empty " << BHDQ->IsEmpty() << endl;
        }

        if(command == "print"){
            if(!BHDQ->IsEmpty()) {
                cout << BHDQ->Print();
            }
        }

        if(command == "front"){
            if(!BHDQ->IsEmpty()) {
                cout << "front is " << BHDQ->Front() << endl;
            }else{
                cout << "failure" << endl;
            }

        }
        if(command == "back"){
            if(!BHDQ->IsEmpty()) {
                cout << "back is " << BHDQ->Back() << endl;
            }else{
                cout << "failure" << endl;
            }

        }
        if(command == "size"){

            cout << "size is " << BHDQ->Size()  << endl;

        }
        if(command == "clear"){
            if(BHDQ->Clear()){
                cout << "success" << endl;
            }
        }
        if(command == "pop_front"){
            if(BHDQ->Pop_front()){
                cout << "success" << endl;
            }else{
                cout << "failure" << endl;
            }
        }

        if(command == "pop_back"){
            if(BHDQ->Pop_back()){
                cout << "success" << endl;
            }else{
                cout << "failure" << endl;
            }
        }
        if(command == "find"){
            std::getline(std::cin,name, '"');
            std::getline(std::cin,name, '"');
            cout << BHDQ->Find(name) << endl;
        }
    }

    delete BHDQ;
    BHDQ = nullptr;

    return 0;
}
