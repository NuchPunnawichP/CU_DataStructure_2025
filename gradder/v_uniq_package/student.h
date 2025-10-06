#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure

#include "vector.h"
#include <bits/stdc++.h>

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  T *newData = new T[mSize]();
  std::map<T, bool> mem;
  int ch = 0;

  for(size_t i=0 ; i<mSize ; i++)
  {
    if(!mem.count(mData[i]))
    {
      mem[mData[i]] = true;
      newData[ch] = mData[i];
      ch++;
    }
  }

  delete [] mData;
  mData = newData;
  mSize = ch;
}

#endif
