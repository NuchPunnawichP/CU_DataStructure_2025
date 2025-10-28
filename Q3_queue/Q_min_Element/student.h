#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

#include "queue.h"

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  T a, b;
  bool ch = true;
  for(size_t i=0 ; i<pos.size() ; i++)
  {
    if(pos[i] >= mSize)
      continue;
    
    if(ch)
    {
      a = mData[ (mFront + pos[i]) % mCap ];
      ch = false;
      continue;
    }

    b = mData[ (mFront + pos[i]) % mCap ];

    if(!comp(a, b))
    {
      a = b;
    }
  }

  //should return something
  return a;
}

#endif
