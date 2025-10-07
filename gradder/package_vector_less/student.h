#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)

  size_t thisSize = this->mSize;
  size_t otherSize = other.mSize;
  size_t thisIndex = 0;
  size_t otherIndex = 0;
 
  while(true)
  {
    if(thisSize == 0 && otherSize > 0)
      return true;

    if(thisSize > 0 && otherSize > 0 && this->mData[thisIndex] < other.mData[otherIndex])
      return true;

    if(thisSize > 0 && otherSize > 0 && this->mData[thisIndex] > other.mData[otherIndex])
      return false;

    if(otherSize == 0)
      break;
  
    thisIndex++;
    otherIndex++;
    thisSize--;
    otherSize--;
 }
 return false;
}

#endif
