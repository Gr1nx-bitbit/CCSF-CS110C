//Victor Kozel
//This Program Analyzes the efficencies of different algorithms

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

//Part 1:
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

//End Part 1

//Part 2
//Implement merge or quick sort 

const int MAX_SIZE = 1000;

void merge(int theArray[], int first, int mid, int last, int* bigO) 
{
    int tempArray[MAX_SIZE]; // Temporary array
    // Initialize the local indices to indicate the subarrays
    int first1 = first; 
    int last1 = mid;
    int first2 = mid + 1; 
    int last2 = last;
    // Beginning of first subarray // End of first subarray
    // Beginning of second subarray // End of second subarray
    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1; // Next available location in tempArray 
    while ((first1 <= last1) && (first2 <= last2))
    {
    // At this point, tempArray[first..index-1] is in order
        if (theArray[first1] <= theArray[first2]) 
        {
            tempArray[index] = theArray[first1];
            first1++; 
            *bigO += 4;
        }
        else
        {
            tempArray[index] = theArray[first2]; 
            first2++;
            *bigO += 2;
        } // end if
        index++;
    } // end while
    // Finish off the first subarray, if necessary
    while (first1 <= last1) 
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1]; 
        *bigO += 2;
        first1++;
        index++;
    } // end while
    
    // Finish off the second subarray, if necessary
    while (first2 <= last2) 
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        *bigO += 2; 
        first2++;
        index++;
    } // end for
    // Copy the result back into the original array
    for (index = first; index <= last; index++)
    {
        theArray[index] = tempArray[index];
        *bigO += 2;
    } 
        
} // end merge

/*
Although this sort HAS to sort through the entire array eventually (linear left array to right array comparison)
it saves on assignment operations because it compares smaller arrays' elements
*/
void mergeSort(int theArray[], int first, int last, int* bigO) {
    if (first < last) 
    {
        // Sort each half
        int mid = first + (last - first) / 2; // Sort left half theArray[first..mid]
        mergeSort(theArray, first, mid, bigO);
        /*
        this goes all the way down to 1 element then calls merge on the left half...
        wouldn't mid be really small then? -> yes but last would be all the way at
        end. but then it calls mergesort left again. jeez this is confusing 
        */
        // Index of midpoint
        // Sort right half theArray[mid+1..last]
        mergeSort(theArray, mid + 1, last, bigO);
        // Merge the two halves
        merge(theArray, first, mid, last, bigO); 
    } // end if
} // end mergeSort

//End Part 2

//Part 3
//Implement Counting Sort

void countSort(int theArray[], int length, int* bigO)
{
    int temp[length];
    *bigO += 1;
    for (int i = 0; i < length; i++)
    {
        //temp is initially assigned a whole bunch of garbage values:
        //if you use them as an index, you get a lot of segmentation faults :)
        temp[i] = 0;
        *bigO += 1;
    }
    //*bigO += 2;
    for (int i = 0; i < length; i++)
    {
        temp[theArray[i]-1] += 1;
        //compare, iterate, access, assign
        *bigO += 1;
    }

    int index = 0;
    *bigO += 2;
    for (int i = 0; i < length; i++)
    {
        //compare, iterate, asiggn j = 0
        //*bigO += 3;
        for (int j = 0; j < temp[i]; j++)
        {
            theArray[index] = i + 1;
            index++;
            *bigO += 2;
        }
    }

}
//In big O notation, what is the expected efficiency? From the data I got, the efficiency seems to lie between O(n) and O(n^2)
//Why is counting sort impractical as a general sorting algorithm? When you don't know the range of your numbers it can be hassle because
//you'd have to do some sorting so you can sort the array further which defeats the purpose of the algorithm. It seems to really efficient, however,
//since to sort it only has to go through an array once to pick up how many of each number there are, then print them out. It has a nested loop though 
//so it seems like count would be O(n^2)
//End Part 3

int main(void) {

    int num = 8;
    srand(time(0));
    
    for (int j = 0; j < 3; j++)
    {
        int yes[num];
        int no[num];
        int maybe[num];
        for (int i = (num-1); i >= 0; i--)
        {
            yes[i] = rand() % num + 1;
            no[i]  = rand() % num + 1;
            maybe[i]  = rand() % num + 1;
        }
        int bigO = 0;
        cout << "Array size: " << num << endl;
        mergeSort(yes, 0, (num-1), &bigO);
        cout << "Steps taken for merge: " << bigO << endl;
        int insertionSteps = insertionSort(no, num);
        cout << "Steps taken for insertion: " << insertionSteps << endl;
        bigO = 0;
        countSort(maybe, num, &bigO);
        cout << "Steps taken for count: " << bigO << endl << endl;
        num *= 4;
    }
    return 0;
}

/*
*************
SAMPLE OUTPUT
*************
[vkozel2@hills sortEfficiency]$ ./a.out 
Array size: 8
Steps taken for merge: 116
Steps taken for insertion: 35
Steps taken for count: 35

Array size: 32
Steps taken for merge: 776
Steps taken for insertion: 926
Steps taken for count: 131

Array size: 128
Steps taken for merge: 4328
Steps taken for insertion: 12125
Steps taken for count: 515

[vkozel2@hills sortEfficiency]$ ./a.out 
Array size: 8
Steps taken for merge: 110
Steps taken for insertion: 38
Steps taken for count: 35

Array size: 32
Steps taken for merge: 772
Steps taken for insertion: 782
Steps taken for count: 131

Array size: 128
Steps taken for merge: 4310
Steps taken for insertion: 12938
Steps taken for count: 515

[vkozel2@hills sortEfficiency]$ ./a.out 
Array size: 8
Steps taken for merge: 114
Steps taken for insertion: 50
Steps taken for count: 35

Array size: 32
Steps taken for merge: 764
Steps taken for insertion: 833
Steps taken for count: 131

Array size: 128
Steps taken for merge: 4328
Steps taken for insertion: 12035
Steps taken for count: 515

[vkozel2@hills sortEfficiency]$
*************
SAMPLE OUTPUT
*************
*****
TABLE
*****
Insertion; array len: 8; pass 1: 35; pass 2: 38; pass 3: 50; average: 41 |
Insertion; array len: 32; pass 1: 926; pass 2: 782; pass 3: 833; average: 847 |
Insertion; array len: 128; pass 1: 12125; pass 2: 12938; pass 3: 12035; average: 12366 |

Merge; array len: 8; pass 1: 116; pass 2: 110; pass 3: 114; average: 113 |
Merge; array len: 32; pass 1: 776; pass 2: 772; pass 3: 764; average: 770 |
Merge; array len: 128; pass 1: 4328; pass 2: 4310; pass 3: 4328; average: 4322 |

Count; array len: 8; pass 1: 35; pass 2: 35; pass 3: 35; average: 35 |
Count; array len: 32; pass 1: 131; pass 2: 131; pass 3: 131; average: 131 |
Count; array len: 128; pass 1: 515; pass 2: 515; pass 3: 515; average: 515 |
*****
TABLE
*****
*/