#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;

  if(pos >= mSize)
    return result;
  
  node* mem = it.ptr->prev;

  result.mHeader->next = it.ptr;
  result.mHeader->prev = mHeader->prev;
  it.ptr->prev = result.mHeader;
  mHeader->prev->next = result.mHeader;

  mem->next = mHeader;
  mHeader->prev = mem;

  result.mSize = mSize - pos;
  mSize = pos;

  return result;
}

#endif
