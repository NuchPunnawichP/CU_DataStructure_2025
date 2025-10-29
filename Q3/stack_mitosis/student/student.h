#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    CP::stack<T> st;
    int original_mSize = mSize;
    for (int i = original_mSize - 1; i >= original_mSize - 1 - b; i--)
    {
        st.push(this->top());
        if (original_mSize - 1 - i >= a && original_mSize - 1 - i <= b)
        {
            st.push(this->top());
        }
        this->pop();
    }
    while (!st.empty())
    {
        this->push(st.top());
        st.pop();
    }
}

#endif