#ifndef __STUDENT_H_
#define __STUDENT_H_

// mCap = amounts of block
// blockSize = amounts of data in one mCap
// T **mData
// T *arr -> for each mData
// mData[mCap][blockSize]

#include "segmented_vector.h"

template <typename T>
CP::SegmentedVector<T>::~SegmentedVector()
{
    // TODO: Write your code here
    for (int i = 0 ; i < mCap ; i++)
    {
        delete [] mData[i];
    }
    delete [] mData;
}
template <typename T>
void CP::SegmentedVector<T>::expand(size_t capacity)
{
    // TODO: Write your code her
    T **nData = new T*[capacity]();

    for(size_t i=0 ; i<capacity ; i++)
    {
        nData[i] = new T[blockSize]();
        
        if(i >= mCap)
            continue;
        
        for(size_t j=0 ; j<blockSize ; j++)
        {
            nData[i][j] = mData[i][j];
        }
    }

    for (int i = 0 ; i < mCap ; i++)
    {
        delete [] mData[i];
    }
    delete [] mData;
    mData = nData;
    mCap = capacity;
}
template <typename T>
void CP::SegmentedVector<T>::insert(int index, const T &element)
{
    // TODO: Write your code here
    ensureCapacity( (mSize + blockSize) / blockSize );
    mSize++;

    for(int i=mSize - 1 ; i >= index + 1 ; i--)
    {
        mData[i / blockSize][i % blockSize] = mData[ (i - 1) / blockSize][ (i - 1) % blockSize ];
    }
    mData[index / blockSize][index % blockSize] = element;
}
template <typename T>
T &CP::SegmentedVector<T>::operator[](int index) const
{
    // TODO: Write your code here
    return mData[index / blockSize][index % blockSize];
}
#endif