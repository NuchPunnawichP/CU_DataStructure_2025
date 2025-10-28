#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
  int level = 0;
  int pos = mSize;
  
  if(pos == 0)
    return -1;

  while(pos > 1)
  {
    pos /= 2;
    level++;
  }
  return level;
}

#endif

