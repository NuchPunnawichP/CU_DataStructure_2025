  #ifndef _STUDENT_H_INCLUDE_
  #define _STUDENT_H_INCLUDE_

  #include "stack.h"

  // aux1 for undo
  // aux2 for redo

  template<typename T>
  void CP::stack<T>::push(const T &value) {
    //You can write your code below here
    while(!aux_stack_2.empty())
      aux_stack_2.pop();

    ensureCapacity(mSize + 1);
    mData[mSize] = value;
    mSize = mSize + 1;

    aux_stack_1.push({1, value});

    return ;
  } 

  template <typename T>
  void CP::stack<T>::pop() {
    //Do not modify this line
    if (size() == 0) throw std::out_of_range("index of out range") ;
    //You can write your code below here
    while(!aux_stack_2.empty())
      aux_stack_2.pop();

    mSize--;

    aux_stack_1.push({-1, mData[mSize]});

    return ;
  }

  template <typename T>
  void CP::stack<T>::undo() {
    //You can write your code below here
    if(!aux_stack_1.empty())
    {
      int st = aux_stack_1.top().first;
      T val = aux_stack_1.top().second;

      aux_stack_1.pop();

      if(st == 1) // push -> then pop
      {
        mSize--;
      }
      else if(st == -1) // pop -> then push
      {
        mSize++;
        mData[mSize - 1] = val;
      }
      aux_stack_2.push({st, val});
    }
    return ;
  };

  template <typename T>
  void CP::stack<T>::redo() {
    //You can write your code below here
    if(!aux_stack_2.empty())
    {
      int st = aux_stack_2.top().first;
      T val = aux_stack_2.top().second;

      aux_stack_2.pop();

      if(st == 1)
      {
        ensureCapacity(mSize + 1);
        mData[mSize] = val;
        mSize++;
        aux_stack_1.push({st, val});
      }
      else if(st == -1)
      {
        if (size() == 0) throw std::out_of_range("index of out range") ;
        mSize--;
        aux_stack_1.push({st, mData[mSize]});
      }
      
    }
    return ;
  }

  #endif