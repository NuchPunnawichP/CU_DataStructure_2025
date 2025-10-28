#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
  // your code here
  size_t m1 = mSize / k;
  size_t m2 = mSize % k;

  size_t idx = 0;

  for(size_t i=0 ; i<k ; i++)
  {
    std::queue<T> tmp;
    for(size_t j=0 ; j<m1 ; j++)
    {
      tmp.push(mData[ (mFront + idx) % mCap ]);
      idx++;
    }
    if(m2 != 0)
    {
      tmp.push(mData[ (mFront + idx) % mCap ]);
      idx++;
      m2--;
    }
    output.push_back(tmp);
  }
}

#endif
