#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
template <typename T>
void CP::queue<T>::block_remove(size_t from, size_t to) {
    // Write your code here

    size_t x = from, y = mSize - to;

    if(y < x)
    {
        size_t i = from, j = to + 1;
        while(j < mSize)
        {
            mData[ (mFront + i) % mCap ] = mData[ (mFront + j) % mCap ];
            i++;
            j++;
        }
    }
    else
    {
        size_t shift = to - from + 1;
        size_t i = from;
        while (i > 0)
        {
            i--;
            size_t srcIdx = (mFront + i) % mCap;
            size_t dstIdx = (mFront + i + shift) % mCap;
            mData[dstIdx] = mData[srcIdx];
        }
        mFront = (mFront + shift) % mCap;
    }
    mSize -= (to - from + 1);
    
    return;
}
#endif