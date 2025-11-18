#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include "list.h"

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here

  auto it = a;
  while(it != b)
  {
    if(it.ptr->data == value)
    {
      node* tmp = it.ptr->next;

      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;

      node* mem = output.mHeader->next;
      output.mHeader->next = it.ptr;
      it.ptr->prev = output.mHeader;
      it.ptr->next = mem;
      mem->prev = it.ptr;

      output.mSize++;
      mSize--;

      it = iterator(tmp);
    }
    else
      ++it;
  }
}

#endif
