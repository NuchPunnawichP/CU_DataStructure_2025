#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
    if (p > mSize) p = mSize;

    if (m == 0) return;
    
    size_t remainingSize = mSize - p;
    T *arr = new T[m + remainingSize];
    
    for (size_t i = 0; i < m; i++)
	{
        arr[i] = element;
    }
    
    for (size_t i = 0; i < remainingSize; i++)
	{
        arr[m + i] = mData[(mFront + p + i) % mCap];
    }
    
    for (size_t i = 0; i < m + remainingSize; i++)
	{
        if (mSize + 1 > mCap)
		{
            expand(2 * mCap);
        }
        mData[(mFront + p + i) % mCap] = arr[i];
    }
    mSize += m;
    
    delete[] arr;
}

#endif