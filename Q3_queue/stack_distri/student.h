#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "stack.h"

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
  CP::stack<T> tmp_st;
  for(int j=(int)mSize-1 ; j>=0 ; j--)
  {
    tmp_st.push(mData[j]);
  }

  size_t m1 = mSize / k;
  size_t m2 = mSize % k;
  
  std::vector<std::vector<T>> ans;
  
  for(size_t i=0 ; i<mSize ; i+=m1)
  {
    std::vector<T> tmp;
    for(size_t j=i ; j<i+m1 ; j++)
    {
      tmp.push_back(tmp_st.mData[j]);
    }

    if(m2 != 0)
    {
      tmp.push_back(tmp_st.mData[i + m1]);
      m2--; i++;
    }

    ans.push_back(tmp);
  }
  
  return ans;
}
#endif
