#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    if(this->mCap - this->mSize > other.mCap - other.mSize)
        return 1;
    if(this->mCap - this->mSize == other.mCap - other.mSize)
        return 0;
    if(this->mCap - this->mSize < other.mCap - other.mSize)
        return -1;
}

#endif
