#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include "list.h"

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  //write your code here
  if (a == b) return a;
  
  iterator temp = b;
  --temp;
  if (a == temp) return a;
  
  node* xp = a.ptr->prev;
  node* xa = a.ptr;
  node* xl = (--b).ptr;
  node* xb = b.ptr->next;
  
  node* curr = xa;
  node* prev_node = xp;
  
  while(curr != xb)
  {
    node* next_node = curr->next;
    curr->next = curr->prev;
    curr->prev = next_node;
    curr = next_node;
  }
  
  xp->next = xl;
  xl->prev = xp;
  xa->next = xb;
  xb->prev = xa;
  
  return iterator(xl);
}
#endif