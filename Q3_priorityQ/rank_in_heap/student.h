#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;

#include "priority_queue.h"

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  //write your code here
  size_t rank = 0;
  Comp comp;

  for(size_t i=0 ; i<mSize ; i++)
  {
    if(comp(mData[pos], mData[i]))
      rank++;
  }

  return rank;
}

#endif
