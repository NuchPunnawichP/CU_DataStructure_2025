#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  if(pos.empty())
    return;

  CP::vector<T> newData = *this;

  int idexPOS = 0, indexNewData = 0;
  for(int i=0 ; i<mSize ; i++)
  {
    if(idexPOS < pos.size() && i == pos[idexPOS])
    {
      idexPOS++;
    }
    else
    {
      this->mData[indexNewData] = newData[i];
      indexNewData++;
    }
  }
  mSize = mSize - pos.size();
}

#endif

/*
a 10 0 1 2 3 4 5 6 7 8 9
p
e 1 1
p
e 5 0 2 3 4 6
p
a 3 100 200 300
p
q
*/