// Array-based List Class for Playlists
// Victor Kozel
// This program implements functions pretaining to a musical playlist
// some of which are: inserting songs, removing them, and renaming them

#include <cassert>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;


template<class ItemType>
class List
{
private:
    static const int CHUNK_SIZE=4;
    ItemType* list;
    int numItems;
    int maxItems;
    int chunks;
public:
    // default constructor and destructor
    List() { numItems = 0; maxItems = CHUNK_SIZE;
        list = new ItemType[CHUNK_SIZE]; chunks = 1; }
    ~List() { delete [] list; }

    // list member functions
    bool isEmpty()  const { return numItems==0; }
    int getLength() const { return numItems; }
    bool insert(int pos, const ItemType& item);
    bool remove(int pos);

    // clear the list
    // clear can simply set numItems to zero.  The array list may still contain
    // items already inserted into the list, but since numItems is zero, there
    // isn't any way to get at them using getEntry() or setEntry()
    void clear() { numItems = 0; chunks = 0; }

    // return entry at postion pos
    // throw invalid_argument if pos<1 or pos>getLength()
    ItemType getEntry(int pos) const;

    // set entry at postion pos to item
    // throw invalid_argument if pos<1 or pos>getLength()
    void setEntry(int pos, const ItemType& item);
};


template<class ItemType>
bool List<ItemType>::remove(int pos)
{
  int max = getLength();
  if (pos < 1 || pos > max)
  {
    string message = "Invalid index! You must choose a position between 1 and " + to_string(getLength());
    throw invalid_argument(message);
  }
  for (int i = pos; i <= max; i++)
  {
    list[i-1] = list[i];
  }
  numItems -= 1;
  return true;
}


template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
    bool canAdd;
    canAdd = ((pos > 0) && (pos <= numItems + 1) && (numItems < maxItems));
    if (canAdd)
    {
        // first, we have to move everything after our insertion point over one
        // position to make room for our new item.  start at the back of the list.
        // don't forget arrays start at postion zero and our list ADT starts at
        // position 1.
        for(int i=numItems; i>=pos; i--)
            list[i] = list[i-1];

        // now put our item at position pos-1
        list[pos-1] = item;

        numItems++;
    }
    else
    {
      ItemType* tmp = new ItemType[(chunks+1)*(CHUNK_SIZE)];
      maxItems += CHUNK_SIZE;
      for (int i = 0; i < getLength(); i++)
      {
        tmp[i] = list[i];
      }
      delete [] list;
      list = tmp;
      numItems++;
      list[pos-1] = item;
    }

    return canAdd;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const
{
    if(pos<1 || pos>getLength()) {
        throw invalid_argument("ERROR: getEntry() using invalid position");
    }
    return list[pos-1];
}

// TODO: add implementations for setEntry() and remove() functions
template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item)
{
  if (pos < 1 || pos > getLength())
  {
    string message = "Invalid index! You must choose a position between 1 and " + to_string(getLength());
    throw invalid_argument(message);
  }
  list[pos-1] = item;
}

// Utility function to input a track number with some input checking
// to make sure it's a number
int getTrack(string first, string second)
{
    if (first.empty())
    {
      first = "track number";
    }
    if (second.empty())
    {
      second = "view";
    }
    bool inputCheck;
    int trackNumber;

    do
    {
        inputCheck = true;
        cout << "Please enter the " << first << " you'd like to " << second << ": ";
        if (!(cin >> trackNumber))
        {
            cout << "Please enter numbers only.\n";
            cin.clear();
            cin.ignore(10000,'\n');
            inputCheck = false;
        }
    } while (!inputCheck);
    return trackNumber;
}


int main()
{
    List<string>* songs = new List<string>;
    char goAgain = 'y';
    int trackNumber;
    string trackName;

    // Insert some songs into our list
    songs->insert(1, "One More Saturday Night");
    songs->insert(1, "Friday I'm in Love");
    songs->insert(3, "Sunday Morning Coming Down");
    songs->insert(1, "California Love");
    //cout << "HELLO!!!! " << songs->getLength() << endl;

    cout << "Welcome!  There are " << songs->getLength() << " tracks.\n";
    while (goAgain!='n')
    {
        for (int song = 0; song < songs->getLength(); song++)
        {
          cout << songs->getEntry(song+1) << endl;
        }
        trackNumber = getTrack("", "");
        try
        {
            trackName = songs->getEntry(trackNumber);
        }
        catch (invalid_argument arg)
        {
            cout << arg.what() << endl;
            trackName = "No Track";
        }
        cout << "Your track name is " << trackName << endl;
        trackNumber = getTrack("", "rename");
        cout << "What would you like to set the track to? ";
        cin.clear();
        cin.ignore(10000,'\n');
        getline(cin, trackName, '\n');
        try
        {
          songs->setEntry(trackNumber, trackName);
        }
        catch (invalid_argument ia)
        {
          cout << ia.what() << endl;
          bool halt = false;
          assert(halt);
        }
        /*
        songs->getEntry(trackNumber);
        trackNumber = getTrack("", "remove");
        try
        {
          bool cool = songs->remove(trackNumber);
        }
        catch (invalid_argument ia)
        {
          cout << ia.what() << endl;
        }
        */

        cout << "What song would you like to add? ";
        cin.clear();
        //cin.ignore(10000,'\n');
        getline(cin, trackName, '\n');
        songs->insert(5, trackName);
        cout << "Go again? (y/n) ";
        cin >> goAgain;
    }

    cout << "Rock on!\n";
    return 0;
}

/*
*************
SAMPLE OUTPUT
*************
assignment ./a.out
Welcome!  There are 4 tracks.
California Love
Friday I'm in Love
One More Saturday Night
Sunday Morning Coming Down
Please enter the track number you'd like to view: 2
Your track name is Friday I'm in Love
Please enter the track number you'd like to rename: 1
What would you like to set the track to? Lavage
What song would you like to add? Footsie sock
Go again? (y/n) y
Lavage
Friday I'm in Love
One More Saturday Night
Sunday Morning Coming Down
Footsie sock
Please enter the track number you'd like to view: 3
Your track name is One More Saturday Night
Please enter the track number you'd like to rename: 5
What would you like to set the track to? A dinner wasted, a life saved
What song would you like to add? No eating until tomorrow
Go again? (y/n) y
Lavage
Friday I'm in Love
One More Saturday Night
Sunday Morning Coming Down
No eating until tomorrow
A dinner wasted, a life saved
Please enter the track number you'd like to view: 2
Your track name is Friday I'm in Love
Please enter the track number you'd like to rename: 2
What would you like to set the track to? Friday
What song would you like to add? Im in Love
Go again? (y/n) n
Rock on!
*************
SAMPLE OUTPUT
*************
*/
