#include <iostream>
#include <string>
using namespace std;

class Song
{
    private:
        string songName;
        string artist;
    public:
        void setSongName(string n)
        {
            songName =  n;
        }
        void setArtist(string a)
        {
            artist = a;
        }
        string getSongName(void)
        { return songName; }
        string getArtist(void)
        { return artist; }
};

int main(void)
{
    Song cool;
    string input;
    cout << "Enter the name of the artist: ";
    getline(cin, input, '\n');
    cool.setArtist(input);
    
    cout << "Enter the name of the song: ";
    getline(cin, input, '\n');
    cool.setSongName(input);
    cout << "Artist: " << cool.getArtist() << ", Song: " << cool.getSongName() << endl;
    return 0;
}


/*
*************
SAMPLE OUTPUT
*************

[vkozel2@hills week0]$ ./a.out 
Enter the name of the artist: CS110C
Enter the name of the song: Hello World!
Artist: CS110C, Song: Hello World!
[vkozel2@hills week0]$ ./a.out 
Enter the name of the artist: Syncatto
Enter the name of the song: Black Velvet
Artist: Syncatto, Song: Black Velvet
[vkozel2@hills week0]$ ./a.out 
Enter the name of the artist: Bernth, Syncatto
Enter the name of the song: Flow
Artist: Bernth, Syncatto, Song: Flow
[vkozel2@hills week0]$

*************
SAMPLE OUTPUT
*************
*/