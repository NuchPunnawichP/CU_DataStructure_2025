#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "unordered_map.h"

namespace CP {

template <typename KeyT,
          typename MappedT,
          typename HasherT,
          typename EqualT>
size_t CP::unordered_map<KeyT, MappedT, HasherT, EqualT>::next_cost(iterator iter) {
    size_t cost = 0;

    if(iter == end())
        return 0;

    size_t it_bucket = hash_to_bucket(iter->first);
    ValueIterator it = find_in_bucket(mBuckets[it_bucket], iter->first);

    it++;

    if(it != mBuckets[it_bucket].end())
    {
        return 1;
    }

    ++cost;

    for(size_t k=it_bucket + 1 ; k < mBuckets.size(); k++)
    {
        ++cost;
        if(!this->mBuckets[k].empty())
            return cost;
    }
    ++cost;

    return cost;
}

}

#endif
