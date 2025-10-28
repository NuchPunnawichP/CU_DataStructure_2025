#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> r;
  int ll = (1 << (int)k) - 1;

  if(k == 0)
  {
    r.push_back(mData[0]);
    return r;
  }

  for(int i=ll ; i<ll + (1 << (int)k) && i < (int)mSize ; i++)
  {
    
    r.push_back(mData[i]);
  }

  std::sort(r.rbegin(), r.rend(), mLess);
  
  return r;
}

#endif

