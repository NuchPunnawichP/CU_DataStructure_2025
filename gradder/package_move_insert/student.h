#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include "stack.h"

template <typename T>
void CP::stack<T>::moveInsert(int k, CP::stack<T> &s2, int m)
{
  // your code here
  k = std::min(k, (int) mSize);

  int moved = std::min(m, (int) s2.mSize);
  int nSize = mSize + moved;

  T *nData = new T[nSize]();

  int pos = 0;
  for (int i = 0; i < mSize; i++)
  {
    if (i == mSize - k)
      for (int j = s2.mSize - moved; j < s2.mSize; j++)
        nData[pos++] = s2.mData[j];

    nData[pos++] = mData[i];
  }

  if (k == 0)
    for (int j = s2.mSize - moved; j < s2.mSize; j++)
      nData[pos++] = s2.mData[j];

  s2.mSize -= moved;
  
  delete[] mData;
  mData = nData;
  mSize = nSize;
  mCap = nSize;
}
#endif