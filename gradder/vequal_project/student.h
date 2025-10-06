#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
bool CP::vector<T>::operator==(const vector<T> &other) const {
  //write your code only in this function
  if(this->mSize != other.mSize)
    return false;
  
  for(int i=0 ; i<this->mSize ; i++)
  {
    if(this->mData[i] != other.mData[i])
      return false;
  }
  return true;
}

#endif
