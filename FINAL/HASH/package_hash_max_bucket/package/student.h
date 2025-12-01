#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include "unordered_map.h"

template <typename KeyT,
          typename MappedT,
          typename HasherT,
          typename EqualT>
size_t CP::unordered_map<KeyT,MappedT,HasherT,EqualT>::max_bucket_length() {
    // your code here
    size_t m = mBuckets.size();
    size_t mx = -1e9;

    for(size_t i=0 ; i<m ; i++)
    {
        if(mBuckets[i].size() > mx)
        {
            mx = mBuckets[i].size();
        }
    }
    return mx;
}

#endif
