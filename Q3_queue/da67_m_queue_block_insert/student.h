#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	// write your code here
	ensureCapacity(mSize + m);

	size_t elementsAfterP = mSize - p;
    
    if (elementsAfterP < p)
	{
        for(size_t i = mSize; i > p; i--)
		{
            mData[(mFront + i + m - 1) % mCap] = mData[(mFront + i - 1) % mCap];
        }
    }
	else
	{
        size_t newFront = (mFront + mCap - m) % mCap;
        for(size_t i = 0; i < p; i++)
		{
            mData[(newFront + i) % mCap] = mData[(mFront + i) % mCap];
        }
        mFront = newFront;
    }

	for(size_t i = p ; i <= p + m - 1 ; i++)
	{
		mData[ (mFront + i) % mCap ] = element;
	}
	mSize += m;
}

#endif
