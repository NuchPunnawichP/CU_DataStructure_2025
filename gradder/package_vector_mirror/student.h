#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  ensureCapacity(2 * mSize);

  T *newData = new T[2 * mSize]();

  for(size_t i=0 ; i<mSize ; i++)
  {
    newData[i] = mData[i];
  }

  for(size_t i=0 ; i<mSize ; i++)
  {
    newData[mSize + i] = mData[mSize - i - 1];
  }

  delete [] mData;
  mData = newData;
  mSize = 2 * mSize;
}

#endif
