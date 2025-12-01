#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include "list.h"

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  // iterate outer list
  for (auto it = ls.begin(); it != ls.end(); ++it) {
    // it is iterator of CP::list<T>
    CP::list<T> &inner = *it;

    // iterate inner list
    for (auto jt = inner.begin(); jt != inner.end(); ++jt) {
      this->push_back(*jt);
    }
  }
}

#endif
