#ifndef HEAPMAXARRAY_H
#define HEAPMAXARRAY_H

template <class HeapType>
class HeapMaxArray {
    private:
        HeapType* items;
        int itemCount;
        int maxCount;
        bool swap(int, int);
        bool heapRebuild(int, HeapType*);
    
    public:
        HeapMaxArray();
        HeapMaxArray(int);
        bool isEmpty(void);
        HeapType peekTop(void);
        bool add(const HeapType&);
        bool remove(void);
};

#endif