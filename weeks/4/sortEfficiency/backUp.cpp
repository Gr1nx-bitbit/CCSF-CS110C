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
   bigO++;
   for (int unsorted = 1; unsorted < n; unsorted++)
   {
      bigO += 2;
      // At this point, theArray[0..unsorted-1] is sorted.
      // Find the right position (loc) in theArray[0..unsorted]
      // for theArray[unsorted], which is the first entry in the
      // unsorted region; shift, as necessary, to make room
      int nextItem = theArray[unsorted];
      bigO += 2;
      int loc = unsorted;
      bigO += 1;
      while ((loc > 0) && (theArray[loc - 1] < nextItem))
      {
        bigO += 3;
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
    *bigO += 4;
    // Beginning of first subarray // End of first subarray
    // Beginning of second subarray // End of second subarray
    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1; // Next available location in tempArray 
    *bigO += 1;
    while ((first1 <= last1) && (first2 <= last2))
    {
        *bigO += 2;
    // At this point, tempArray[first..index-1] is in order
        if (theArray[first1] <= theArray[first2]) 
        {
            tempArray[index] = theArray[first1];
            first1++; 
            *bigO += 6;
        }
        else
        {
            tempArray[index] = theArray[first2]; 
            first2++;
            *bigO += 3;
        } // end if
        index++;
        *bigO += 1;
    } // end while
    // Finish off the first subarray, if necessary
    while (first1 <= last1) 
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1]; 
        *bigO += 3;
        first1++;
        index++;
        *bigO += 2;
    } // end while
    
    // Finish off the second subarray, if necessary
    while (first2 <= last2) 
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        *bigO += 3; 
        first2++;
        index++;
        *bigO += 2;
    } // end for
    // Copy the result back into the original array
    *bigO += 1;
    for (index = first; index <= last; index++)
    {
        theArray[index] = tempArray[index];
        *bigO += 4;
    } 
        
} // end merge

/*
Although this sort HAS to sort through the entire array eventually (linear left array to right array comparison)
it saves on assignment operations because it compares smaller arrays' elements
*/
void mergeSort(int theArray[], int first, int last, int* bigO) {
    if (first < last) 
    {
        *bigO += 1;
        // Sort each half
        int mid = first + (last - first) / 2; // Sort left half theArray[first..mid]
        *bigO += 1;
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
    // for (int i = 0; i < length; i++)
    // {
    //     cout << theArray[i] << ". ";
    // }
    // cout << endl;

    int temp[length];
    *bigO += 2;
    for (int i = 0; i < length; i++)
    {
        //temp is initially assigned a whole bunch of garbage values:
        //if you use them as an index, you get a lot of segmentation faults :)
        temp[i] = 0;
        *bigO += 3;
    }
    *bigO += 2;
    for (int i = 0; i < length; i++)
    {
        temp[theArray[i]-1] += 1;
        //compare, iterate, access, assign
        *bigO += 4;
    }

    int index = 0;
    *bigO += 2;
    for (int i = 0; i < length; i++)
    {
        //compare, iterate, asiggn j = 0
        *bigO += 3;
        for (int j = 0; j < temp[i]; j++)
        {
            theArray[index] = i + 1;
            index++;
            *bigO += 4;
        }
    }

    // for (int i = 0; i < length; i++)
    // {
    //     cout << theArray[i] << ". ";
    // }
    // cout << endl;

}
//In big O notation, what is the expected efficiency? From the data I got, the efficiency seems to lie between 
//Why is counting sort impractical as a general sorting algorithm?
//End Part 3

int main(void) {

    int num = 8;
    srand(time(0));
    // int yes[num];
    // for (int i = (num-1); i >= 0; i--)
    //     {
    //         yes[i] = rand() % num + 1;
    //         //no[i]  = rand() % num + 1;
    //         //cout << yes[i] << ", ";
    //     }
    // int bigO = 0;
    // cout << "Array size: " << num << endl;
    // countSort(yes, num, &bigO);
    // cout << "Steps taken for count: " << bigO << endl;
    
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

