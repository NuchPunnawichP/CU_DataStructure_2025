#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  CP::stack<T> tmp;
  size_t idx = 0;

  bool ch = true;

  while(!empty())
  {
    if(idx >= pos)
    {
      ch = false;
      tmp.push(value);
      break;
    }
    tmp.push(top());
    pop();

    idx++;
  }
  
  if(ch)
    if(pos >= mSize)
      push(value);

  while(!tmp.empty())
  {
    push(tmp.top());
    tmp.pop();
  }
}
#endif

/*
u 1
u 2
u 3
u 4
p
d 0 10
d 5 11
p
o
o
p
q
*/