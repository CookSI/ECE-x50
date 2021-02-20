/**
    ECE250
    dequeaslist.h
    Purpose: Class to represent a browser history dequlist with many URL entries
    Provides services to play, add & remove songs from/to the playlist.

    Author Albert Ndur-Osei
    Version 1.0  - 04/02/2021
*/

#include <string>
#ifndef DEQUEASLIST_H
#define DEQUEASLIST_H
using std::string;

class URL{
private:
    URL * p_nxt;
    URL * p_pre;
    string name;
    string link;
    friend class Browser_historyDQ;
public:
    URL(URL * next, URL * prev,  const string n, const string l);
};

class Browser_historyDQ{
private:
    URL * p_head;
    URL * p_tail;
    int len;
    friend class URL;
public:
    Browser_historyDQ();
    ~Browser_historyDQ();
    string Push_front(string name, string link);
    bool Pop_front();
    string Push_back( string name,  string link);
    bool  Pop_back();
    int Size() const;
    string Front();
    string Back();
    bool IsEmpty();
    bool  Clear();
    string Find(const string name);
    string Print();

};
#endif