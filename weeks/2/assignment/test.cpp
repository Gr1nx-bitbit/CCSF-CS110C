#include <iostream>
using namespace std;
int main(void)
{
  int a[4];
  int* start = a;
  for (int i = 0; i < 4; i++)
  {
    start[i] = i;
    cout << start[i] << endl;
  }
  start += new int[3];
  cout << "Length: " << sizeof(a)/sizeof(int) << endl;
  for (int i = 0; i < (sizeof(a)/sizeof(int)); i++)
  {
    cout << "Hello!" << endl;
    start[i] = i*i;
    cout << start[i] << endl;
  }
  return 0;
}
