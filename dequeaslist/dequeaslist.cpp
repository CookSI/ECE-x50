/**
    ECE250
    dequeaslist.cpp
    Purpose: Class to represent a browser history dequlist with many URL entries
    Provides services to play, add & remove songs from/to the playlist.

    Author Albert Ndur-Osei
    Version 1.0  - 04/02/2021
*/

#include <iostream>
#include <string>
using std::string;

#include "dequeaslist.h"

bool strcompare(std::string a, std::string b){

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

URL::URL(URL * next, URL * prev,  const string n, const string l){
    this->p_nxt = next;
    this->p_pre = prev;
    this->name = n;
    this->link = l;
}


Browser_historyDQ::Browser_historyDQ(){
    p_head = nullptr;
    p_tail = nullptr;
    len = 0;
}

Browser_historyDQ::~Browser_historyDQ(){
    URL * p_temp = p_head;
    while(p_temp != 0){
        p_temp = p_head->p_nxt;
        delete p_head;
        p_head = p_temp;
        len--;
    }
    p_temp = nullptr;
    p_head = nullptr;
    p_tail = nullptr;
}

string Browser_historyDQ::Push_front(const string name, const string link){

    if(len == 0){ //If the DQ is empty
        URL * p_temp = new URL( nullptr, nullptr, name, link);
        p_head = p_temp;
        p_tail = p_temp;
        p_temp = nullptr;
    }else{ //If the DQ not empty
        URL * nav = p_head;
        URL * p_temp = new URL(nav, nullptr, name, link);
        p_head = p_temp;
        nav->p_pre = p_temp;
        nav = nullptr;
        p_temp= nullptr;
    }
    len++;
    return "success";
}

string Browser_historyDQ::Push_back(const string name, const string link){

    if(IsEmpty()){
        URL * p_temp = new URL( nullptr, nullptr, name, link);
        p_head = p_temp;
        p_tail = p_temp;
        p_temp = nullptr;
    }else{
        URL * nav = p_tail;
        URL * p_temp = new URL(nullptr, nav, name, link);
        p_tail = p_temp;
        nav->p_nxt = p_temp;
        p_temp = nullptr;
        nav = nullptr;
    }
    len++;
    return "success";
}

string Browser_historyDQ::Print(){
    string name_str;
    string url_str;
    string return_str;
    URL * nav = p_tail;

    if(len == 1){
        name_str = nav->name;
        url_str = nav->link;
        return_str =  name_str + ' ' + url_str + '\n';
        nav = nullptr;
    }else{
        while(nav !=0) {
            name_str = nav->name;
            url_str = nav->link;
            return_str +=  name_str + ' ' + url_str + '\n';
            nav = nav->p_pre;
        }
        nav = nullptr;
    }
    return return_str;
}
bool Browser_historyDQ::Pop_front(){
    if(IsEmpty()){ // If the lst is empty we will print fail
        return 0;
    }else{
        if(len == 1){ //single url case
            delete p_head;
            p_head = nullptr;
            p_tail = nullptr;
            --len;
            return 1;
        }else{
            URL *old = p_head;
            p_head = old->p_nxt;
            p_head->p_pre = nullptr;
            delete old;
            old = nullptr;
            --len;
            return 1;
        }
    }
}

bool Browser_historyDQ::Pop_back(){
    if(IsEmpty()){ // If the lst is empty we will print fail
        return 0;
    }else{
        if(len == 1){ //single url case
            delete p_head;
            p_head = nullptr;
            p_tail = nullptr;
            --len;
            return 1;
        }else{
            URL *old = p_tail;
            p_tail = old->p_pre;
            p_tail->p_nxt = nullptr;
            delete old;
            old = nullptr;
            --len;
            return 1;
        }
    }
}


string Browser_historyDQ::Front(){
    return p_head->name + ' ' + p_head->link; //Print the name and url of front url
}

string Browser_historyDQ::Back(){
    return p_tail->name + ' ' + p_tail->link; // Print the name and url at back url
}


bool Browser_historyDQ::IsEmpty(){
    //the length will be 0 if empty
    return (len == 0);
}

int Browser_historyDQ::Size() const{
    //return length of BHDQ
    return len;
}

bool  Browser_historyDQ::Clear(){
    if(IsEmpty()){
        return 0;
    }else{
        URL * p_temp = p_head;;
        while(p_temp != nullptr){
            p_temp = p_head->p_nxt;
            delete p_head;
            p_head = p_temp;
            len--;
        }
        p_temp = nullptr;
        p_head = nullptr;
        p_tail = nullptr;
        return 1;
    }

}

string Browser_historyDQ::Find(const string name){
    if(this->IsEmpty()){
        return "not found " + name;
    }
    URL * nav = p_head;
    while (nav != 0){
        string maybe =nav->name;
        if(strcompare(name,maybe)){
            return "found " + nav->name + ' ' + nav->link;
        }
        nav = nav->p_nxt;
    }
    return "not found " + name;
}