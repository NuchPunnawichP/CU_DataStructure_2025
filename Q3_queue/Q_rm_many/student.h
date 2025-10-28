#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  T *nData = new T[mCap]();

  std::vector<bool> pos_rm(mCap, false);
  for(size_t p : pos)
  {
    pos_rm[p] = true;
  }

  size_t i = 0, j = 0;
  int k = 0;

  while(j<mSize)
  {
    if(!pos_rm[j])
    {
      mData[ (mFront + i) % mCap ] = mData[ (mFront + j) % mCap ];
      i++;
    }
    j++;
  }
  mSize -= pos.size();
}

#endif
