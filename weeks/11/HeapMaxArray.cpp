#include "HeapMaxArray.h"
#include "Patient.h"
#include <iostream>

template <class HeapType>
bool HeapMaxArray<HeapType>::swap(int source, int destination) {
    HeapType tmp = items[source];
    items[source] = items[destination];
    items[destination] = tmp;
    return true;
}

template <class HeapType>
bool HeapMaxArray<HeapType>::heapRebuild(int index, HeapType* heap) {
    if ((index * 2) > itemCount || (index * 2) > maxCount) {
        return true;
    } else {
        int leftChildIndex = (index * 2) + 1;
        if ((items[leftChildIndex] > items[leftChildIndex + 1]) || items[leftChildIndex] == items[leftChildIndex + 1]) {
            swap(index, leftChildIndex);
            heapRebuild(leftChildIndex, items);
        } else {
            swap(index, (leftChildIndex + 1));
            heapRebuild((leftChildIndex + 1), items);
        }
    }

    return true;
}

template <class HeapType>
HeapMaxArray<HeapType>::HeapMaxArray() {
    items = new HeapType[10]; 
    itemCount = 0; 
    maxCount = 10;
}

template <class HeapType>
HeapMaxArray<HeapType>::HeapMaxArray(int max) {
    items = new HeapType[max];
    itemCount = 0;
    maxCount = max;
}

template <class HeapType>
bool HeapMaxArray<HeapType>::isEmpty(void) {
    if (itemCount == 0) {
        return true;
    } else {
        return false;
    }
}

template <class HeapType>
HeapType HeapMaxArray<HeapType>::peekTop() {
    if (isEmpty()) {
        std::cout << "Nothing in the heap!" << std::endl;
    } else {
        return items[0];
    }
}

template <class HeapType>
bool HeapMaxArray<HeapType>::add(const HeapType& input) {
    items[itemCount] = input;
    int newDataIndex = itemCount++;
    bool inPlace = false;
    while((newDataIndex >= 0) && !inPlace) {
        int parentIndex = ((newDataIndex - 1) / 2);
        if (items[newDataIndex] < items[parentIndex] || items[newDataIndex] == items[parentIndex]) {
            inPlace = true;
        } else {
            swap(newDataIndex, parentIndex);
            newDataIndex = parentIndex;
        }
    }
    return true;
}

template <class HeapType>
bool HeapMaxArray<HeapType>::remove(void) {
    if (isEmpty()) {
        return false;
    } else {
        items[0] = items[itemCount - 1];
        itemCount--;
        heapRebuild(0, items);
    }
    return true;
}

template class HeapMaxArray<Patient>;