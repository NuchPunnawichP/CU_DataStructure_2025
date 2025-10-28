#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        stack<T> tmp1;
        while(!s.empty())
        {
            tmp1.push(s.top());
            s.pop();
        }

        ensureCapacity(mCap + tmp1.size());
        mSize += tmp1.size();
        for(int i=mSize - 1 ; i>=tmp1.size() ; i--)
        {
            mData[i] = mData[i - tmp1.size()];
        }
        int ln = tmp1.size();
        for(int i=0 ; i<ln ; i++)
        {
            if(!tmp1.empty())
            {
                mData[i] = tmp1.top();
                tmp1.pop();
            }
        }
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        stack<T> tmp1;
        while(!q.empty())
        {
            tmp1.push(q.front());
            q.pop();
        }

        ensureCapacity(mCap + tmp1.size());
        mSize += tmp1.size();
        for(int i=mSize - 1 ; i>=tmp1.size() ; i--)
        {
            mData[i] = mData[i - tmp1.size()];
        }
        int ln = tmp1.size();
        for(int i=0 ; i<ln ; i++)
        {
            if(!tmp1.empty())
            {
                mData[i] = tmp1.top();
                tmp1.pop();
            }
        }
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        while (!s.empty())
        {
            push(s.top());
            s.pop();
        }
        
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while(!q.empty())
        {
            push(q.front());
            q.pop();
        }
    }
}
