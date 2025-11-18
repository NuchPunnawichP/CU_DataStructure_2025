#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  //write your code here
  node* curr = mHeader->next;

  while(curr != mHeader)
  {
    node* tmp = curr->next;

    if(curr->data == value)
    {
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;

      delete curr;
      mSize--;
    }

    curr = tmp;
  }
}

#endif
