#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

#include "queue.h"

template <typename T>
void CP::queue<T>::back_to_front() {
  //write your code here
  if(mSize == 0)
    return;
  
  if(mFront != 0)
    mFront--;
  else
    mFront = mCap - 1;

  mData[mFront] = mData[ (mFront + mSize) % mCap ];
}

#endif
