#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
  //write your code here
  
  for(size_t i=0 ; i<mSize ; i++)
  {
    if(it == &mData[i])
      return true;
  }
  return false;
}

#endif
