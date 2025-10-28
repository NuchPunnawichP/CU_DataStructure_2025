#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>
#include "queue.h"
#include <vector>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here

    std::map<T, int> mp;
    for(size_t i=0 ; i<mSize ; i++)
    {
        mp[mData[ (mFront + i) % mCap ]]++;
    }

    std::vector<std::pair<T,size_t>> ans;
    for(auto x : k)
    {
        ans.push_back({x, mp[x]});
    }

    return ans;
}

#endif
