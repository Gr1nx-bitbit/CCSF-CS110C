#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

template<class ItemType>
class Box
{
  private:
    ItemType item;
  public:
    void setItem(const ItemType& yes)
    { item = yes; }
    ItemType getItem(void)
    { return item; }
};

template<class ItemType>
Box<ItemType> findBox(Box<ItemType> boxes[], int size, Box<ItemType> target)
{
  if (target.getItem() < 0)
  {
    throw invalid_argument("The SSN you search for must be a positive number!");
  }
  int index = 0;
  bool found = false;
  while (index < size && !found)
  {
    if (boxes[index].getItem() == target.getItem())
    {
      found = true;
    }
    else
    {
      index++;
    }
  }
  if (!found)
  {
    throw logic_error("Element not found in the array!");
  }
  return boxes[index];
}


int main(void)
{
  Box<int> xob[3];
  Box<int> target, resultBox;
  int ssn;

  xob[0].setItem(111224444);
  xob[1].setItem(123457698);
  xob[2].setItem(987452361);

  cout << "Type in the SSN you'd like to search for: ";
  cin >> ssn;
  target.setItem(ssn);

  try
  {
    resultBox = findBox(xob, 3, target);
    cout << "SSN " << resultBox.getItem() << " found!" << endl;
  }
  catch (invalid_argument ia)
  {
    cout << ia.what() << endl;
  }
  catch (logic_error le)
  {
    cout << le.what() << endl;
  }
  return 0;
}

/*
*************
SAMPLE OUTPUT
*************
➜  gradedDiscussion ./a.out           
Type in the SSN you'd like to search for: 111224444
SSN 111224444 found!
➜  gradedDiscussion ./a.out
Type in the SSN you'd like to search for: -3451
The SSN you search for must be a positive number!
➜  gradedDiscussion ./a.out
Type in the SSN you'd like to search for: 12345
Element not found in the array!
*************
SAMPLE OUTPUT
*************
*/
