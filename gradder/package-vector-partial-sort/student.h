#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything
#include "vector.h"
#include <bits/stdc++.h>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT  comp) {
  // Write code here
  // you can compare two data A and B of type T by calling comp(A,B)
  // which return true when A is less than B

  if(pos.empty())
    return;

  CP::vector<size_t> sortPos(pos.size());
  CP::vector<T> sortVal(pos.size());
  for(size_t i=0 ; i<pos.size() ; i++)
  {
    sortPos[i] = pos[i] - begin();
    sortVal[i] = *pos[i];
  }

  std::sort(sortPos.begin(), sortPos.end());
  std::sort(sortVal.begin(), sortVal.end(), comp);

  int idxPos = 0;
  T *newData = new T[mSize]();
  for(size_t i=0 ; i<mSize ; i++)
  {
    if(idxPos < mSize && sortPos[idxPos] == i)
    {
      newData[i] = sortVal[idxPos];
      idxPos++;
    }
    else
    {
      newData[i] = mData[i];
    }
  }
  delete [] mData;
  mData = newData;
}

#endif
