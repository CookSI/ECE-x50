/**
    ECE250
    playlist.cpp
    Purpose: Class to represent a song playlist with many entries
    Provides services to play, add & remove songs from/to the playlist.

    Author Albert Ndur-Osei
    Version 1.0  - 26/01/2021
*/

#include <iostream>
#include <string>


#include "Playlist.h"

	bool Insensitivestrcompare(std::string a, std::string b){

			bool equ = true;
			if( a.size() != b.size() ){
				return false;
			   }

			std::string str_a = a;
			std::string str_b = b;

			for(std::size_t i{0}; i < a.size(); i++){
			 if(std::toupper((unsigned char)(str_a[i])) != std::toupper((unsigned char)(str_b[i]))){
					return false;
				}
			}
			return equ;
		}

	Playlist::Playlist(const int n){
		 capacity = n;
		 size = 0 ;
			p_list = new Entry[capacity];

			for (int i{0}; i< capacity-1; i++){
				p_list[i].name ="\0";
				p_list[i].artist ="\0";
			}
	 }


	Playlist::~Playlist(){
		delete [] p_list;
	}

	std::string Playlist::Play_song(int n){
		//the string that will be printed by the driver in response to input
		std::string response;

		if(0 >= n || size < n || p_list[n-1].name == "\0"){
			response = "Can not play ";
			response += std::to_string(n);
		}else{
			response = "Played  " + std::to_string(n) + ' ' + p_list[n-1].name + ";" + p_list[n-1].artist;
		}
		return response;
	}

	std::string Playlist::Add_song(const std::string  song, const std::string artist){
		//the string that will be printed by the driver in response to input
		std::string response;

		//condional value that changes if the song and artist are in the list already
		bool exists = false;

		//loop through playlist to make sure its not there already
		for(int i {0}; i < size; ++i){
			if(Insensitivestrcompare(song, p_list[i].name) && Insensitivestrcompare(artist, p_list[i].artist)){
				exists = true;
				break;
			}
		}

		if(size == capacity-1 || exists){
			response = "can not insert " + song + ';' + artist;
		}else{
			p_list[size].name = song;
			p_list[size].artist = artist;
			response = "success";
			size++;

            ;
		}
		return response;

	}

	std::string Playlist::Remove_song(int n){
			//the string that will be printed by the driver in response to input
			std::string response;

			if(0 >= n || size < n || p_list[n-1].name == "\0"){
				response = "Can not erase ";
				response += std::to_string(n);
			}else if(n == size){
				// clear the entry
				p_list[n-1].name ="\0";
				p_list[n-1].artist ="\0";
				--size;
				response = "success";
			}else{
				// clear the entry
				p_list[n-1].name ="\0";
				p_list[n-1].artist ="\0";

				// move empty entry out
				for(int i){

				}
			}
	}


