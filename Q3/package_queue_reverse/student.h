#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse(int a, int b) {
  //your code here
  // this is queue reverse function
  // input: 5 2 4
  // input: 5 4 3 2 1
  // output: 5 4 1 2 3
  assert(a >= 0 && b < (int)size() && a <= b);
  a = (mFront + a) % mCap;
  b = (mFront + b) % mCap;
  
  while (a != b && (a + mCap - 1) % mCap != b)
  {
    T temp = mData[a];
    mData[a] = mData[b];
    mData[b] = temp;
    
    a = (a + 1) % mCap;
    b = (b + mCap - 1) % mCap;
  }
}

#endif
