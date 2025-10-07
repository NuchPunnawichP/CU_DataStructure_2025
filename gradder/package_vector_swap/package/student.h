#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include "vector.h"

template <typename T>
void CP::vector<T>::swap(CP::vector<T> &other) {
    
    std::swap(mData, other.mData);
    std::swap(mSize, other.mSize);
    std::swap(mCap, other.mCap);
}

#endif 