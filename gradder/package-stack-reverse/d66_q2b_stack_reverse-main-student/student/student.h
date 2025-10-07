#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "stack.h"
#include <iostream>

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
    if (first >= last || first >= mSize || last >= mSize)
        return;
	
	if(first < 0)
		first = 0;
	
	if(last < 0)
		last = 0;
    
    size_t arrayFirst = mSize - 1 - first;
    size_t arrayLast = mSize - 1 - last;
    
    T *newData = new T[mSize]();
    
    for(size_t i = 0; i < arrayLast; i++)
	{
        newData[i] = mData[i];
    }
    
    for(size_t i = arrayLast; i <= arrayFirst; i++)
	{
        newData[i] = mData[arrayFirst - (i - arrayLast)];
    }
    
    for(size_t i = arrayFirst + 1; i < mSize; i++)
	{
        newData[i] = mData[i];
    }
    
    delete[] mData;
    mData = newData;
}
#endif