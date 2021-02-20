/**
    ECE250
    playlist.cpp
    Purpose: Class to represent a song playlist with many entries
    Provides services to play, add & remove songs from/to the playlist.

    Author Albert Ndur-Osei
    Version 1.0  - 26/01/2021
*/

#include <string>

class Entry{
    private:
        std::string name,artist;
    public:
        friend class Playlist;
};

class Playlist{
    private:
        int capacity;
        int size;
        Entry * p_list;

    public:

        Playlist(int n);
        ~Playlist();

        std::string Add_song(const std::string  song, const std::string  artist);
        std::string Play_song(const int n);
        std::string Remove_song(const int n);

};


