#ifndef _CP_PAIR_INCLUDED_
#define _CP_PAIR_INCLUDED_

#include <iostream>

namespace CP
{
    template <typename T1,typename T2>

    class pair
    {
        public:
            T1 first;
            T2 second;
            
            // default constructor
            pair() : first(), second() {}

            // custom constructor
            pair(const T1 &a,const T2 &b) : first(a), second(b) { }

            // equality operator
            bool operator==(const pair<T1,T2> &other) const
            {
                return (first == other.first && second == other.second);
            }

            // comparison operator <
            bool operator<(const pair<T1,T2>& other) const
            {
                return ((first < other.first) || (first == other.first && second < other.second));
            }

            // comparison operator >
            bool operator > (const pair<T1, T2>& other) const
            {
                return other < *this;
            }

            // operator >=
            bool operator>=(const pair<T1, T2> &other) const
            {
                return ( *this > other || *this == other);
            }

            // operator !=
            bool operator!=(const pair<T1, T2> &other) const
            {
                return !(*this == other);
            }
    };
}

#endif