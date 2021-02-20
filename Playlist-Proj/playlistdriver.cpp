/**
    ECE250
    playlistdriver.cpp
    Purpose: Tester file for playlist class
    Read commands from standard input and writes  the  output  to  standard  output

    Author Albert Ndur-Osei
    Version 1.0  - 26/01/2021
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;


#include "Playlist.h" //Playlist class


int main(){
	std::string songartist,a,s,command;
	int n,num;

	cout<<"Enter a command"
			"d: ";
	cin >> command;
	cin >> num ;
	Playlist Songlist(num);

	cout<<"success"<<endl;

	while(command != "exit"){

		cout<<"Enter a command: ";
		cin >> command;

		if(command == "i"){
			cin >> songartist;

			std::size_t i{0};

			    for(;i < songartist.size(); i++){
			         if(songartist[i] != ';'){
			             s += songartist[i];
			         }else{
			            break;
			         }
			    }
			    for(i+=1; i < songartist.size(); i++){
			             a += songartist[i];
			    }


			cout<<Songlist.Add_song(s,a)<<endl;
		}

		if(command == "p"){
			cin >> n;

			cout<<Songlist.Play_song(n)<<endl;
		}

		if(command == "e"){
			cin >> n;

			cout<<Songlist.Remove_song(n)<<endl;
		}
	}
}

