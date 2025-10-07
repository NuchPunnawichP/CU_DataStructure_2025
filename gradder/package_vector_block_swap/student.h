#pragma GCC optimize("O3")

#include <algorithm>
#include "vector.h"

template <typename T>


bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if (m <= 0 || a == b || b > a && a + m - 1 >= b || a > b && b + m - 1 >= a || a < begin() || b < begin())
  {
    return false;
  }

  if (a + m <= end() && b + m <= end())
  {
    auto abeg = a;
    auto bbeg = b;

    while (abeg < a + m)
    {
      std::swap(*(abeg++), *(bbeg++));
    }
    return true;
  }
  return false;
}