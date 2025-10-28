#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::find(T k) const {
  //your code here
  for(size_t i=0 ; i<mSize ; i++)
  {
    if(k == mData[i])
      return true;
  }
  return false;
}

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::find_level(T k) const {
  //your code here

  int pos = 0, mem = -1;
  for(size_t i=0 ; i<mSize ; i++)
  {
    if(k == mData[i])
    {
      mem = pos;
    }
    pos++;
  }
  if(mem != -1)
    pos = mem;

  if(pos == mSize)
    return -1;

  int level = 0;

  pos += 1;
  while(pos > 1)
  {
    pos /= 2;
    level++;
  }
  return level;
}

#endif

/*
a 10
a 10
a 10
a 10
a 20
f 10
l 10
f 20
l 9000
f 9000
d
l 10
q
*/