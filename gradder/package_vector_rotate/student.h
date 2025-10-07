#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include "vector.h"

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {

  CP::vector<T> tmp(k);
  int a = 0;

  for (int i = first-begin(); i < first-begin()+k; i++)
  {
    tmp[a] = mData[i];
    a++;
  }

  for (int i = first-begin(); i < last-begin()-k; i++)
  {
    mData[i] = mData[i+k];
  }

  int j = 0;
  for (int i = last-begin()-k; i < last-begin(); i++)
  {
    mData[i] = tmp[j];
    j++;
  }
}

#endif
