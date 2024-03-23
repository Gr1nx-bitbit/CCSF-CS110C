#include <iostream>
using namespace std;

int insertionSort(int theArray[], int n)
{
    int bigO = 0;
   // unsorted = first index of the unsorted region,
   // loc = index of insertion in the sorted region,
   // nextItem = next item in the unsorted region.
   //
   // Initially, sorted region is theArray[0],
   // unsorted region is theArray[1..n-1].
   // In general, sorted region is theArray[0..unsorted-1],
   // unsorted region theArray[unsorted..n-1]
   for (int unsorted = 1; unsorted < n; unsorted++)
   {
      // At this point, theArray[0..unsorted-1] is sorted.
      // Find the right position (loc) in theArray[0..unsorted]
      // for theArray[unsorted], which is the first entry in the
      // unsorted region; shift, as necessary, to make room
      int nextItem = theArray[unsorted];
      bigO += 1;
      int loc = unsorted;
      while ((loc > 0) && (theArray[loc - 1] < nextItem))
      {
         // Shift theArray[loc - 1] to the right
         theArray[loc] = theArray[loc - 1];
         bigO += 3;
         loc--;
        } // end while
      // At this point, theArray[loc] is where nextItem belongs
theArray[loc] = nextItem; // Insert nextItem into sorted region
bigO += 1; 
    } //endfor
    return bigO;
}  // end insertionSort

int main(void) {
    int yes[3] = {0, 1, 2};
    int no[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int maybe[5] = {0, 1, 2, 3, 4};
    int so[4] = {0, 1, 2, 3};
    int cool[6] = {0, 1, 2, 3, 4, 5};
    int lame[7] = {0, 1, 2, 3, 4, 5, 6};
    int aw[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int nice[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int num = insertionSort(no, 10);
    int num1 = insertionSort(yes, 3);
    int num2 = insertionSort(maybe, 5);
    int num3 = insertionSort(so, 4);
    int num6 = insertionSort(cool, 6);
    int num7 = insertionSort(lame, 7);
    int num8 = insertionSort(aw, 8);
    int num9 = insertionSort(nice, 9);
    for (int i = 0; i < 10; i++)
    {
        if (i < 3)
        {
            //cout << "Yes: " << yes[i] << endl;
            cout << "No: "  << no[i]  << endl;
        }
        else 
        {
            cout << "No: "  << no[i]  << endl;
        }
    }
    cout << "\nArray Accesses: " << num1 << " for array of length: 3" << endl;
    cout << "\nArray Accesses: " << num3 << " for array of length: 4" << endl;
    cout << "\nArray Accesses: " << num2 << " for array of length: 5" << endl;
    cout << "\nArray Accesses: " << num6 << " for array of length: 6" << endl;
    cout << "\nArray Accesses: " << num7 << " for array of length: 7" << endl;
    cout << "\nArray Accesses: " << num8 << " for array of length: 8" << endl;
    cout << "\nArray Accesses: " << num9 << " for array of length: 9" << endl;
    cout << "\nArray Accesses: " << num << " for array of length: 10" << endl;
    return 0;
}