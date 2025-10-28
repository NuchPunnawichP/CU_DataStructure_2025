#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything

  int xx = 0;
  if(k == 1)
    xx = 1;
  else if(k == 2)
    xx = std::min((int)3, (int)mSize);
  else if(k == 3)
    xx = std::min((int)7, (int)mSize);

  std::vector<T> vec(xx);
  for(int i=0 ; i<xx ; i++)
  {
    vec[i] = mData[i];
  }
  std::sort(vec.begin(), vec.end(), mLess);
  
  return vec[(int)mSize - k];
}

#endif
