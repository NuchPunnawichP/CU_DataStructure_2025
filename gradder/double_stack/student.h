#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <stack>
#include <vector>

template <typename T>
void balanceStack(std::stack<T> &a, std::stack<T> &b, int ckPop, bool popBottom)
{
	std::vector<T> assignStack(a.size() + b.size());

	int index = 0;

	while(!b.empty())
	{
		assignStack[index] = b.top();
		b.pop();

		index++;
	}

	index = a.size() + b.size() - 1;

	while(!a.empty())
	{
		assignStack[index] = a.top();
		a.pop();

		index--;
	}

	int start = 0;
	int end = assignStack.size() - 1;

	if(popBottom)
	{ 
		start += ckPop;
	}
	else
	{
		end -= ckPop;
	}

	if(start > end)
		return;

	int partition = (end + start + 1) / 2;
	for(int i = partition - 1 ; i >= start ; i--)
	{
		b.push(assignStack[i]);
	}

	for(int i = partition;i <= end;i++)
	{
		a.push(assignStack[i]);
	}
}

template <typename T>
void CP::stack<T>::pop() {
	// modify method here
	// stack_a.pop();
	int ckPop = 1;
	if(stack_a.size() >= 1)
	{
		stack_a.pop();
		ckPop = 0;
	}
	
	if(stack_a.size() == 0)
	{
		balanceStack(stack_a,stack_b,ckPop,false);
	}
}

template <typename T>
const T& CP::stack<T>::top() {
	// modify method here
	// return stack_a.top();
	if(stack_a.empty())
		balanceStack(stack_a,stack_b,0,false);
	return stack_a.top();
}

template <typename T>
const T& CP::stack<T>::bottom() {
	// write your code here
	if(stack_b.size() > 0)
	{
		return stack_b.top();
	}
	else
	{
		balanceStack(stack_a, stack_b, 0, false);

		if(stack_b.size() > 0)
			return stack_b.top();
		else
			return stack_a.top();
	}
}

template <typename T>
void CP::stack<T>::push_bottom(const T& element) {
	// write your code here
	stack_b.push(element);
}

template <typename T>
void CP::stack<T>::pop_bottom() {
	// write your code here
	int ckPop = 1;
	if(stack_b.size() >= 1)
	{
		stack_b.pop();
		ckPop = 0;
	}

	if(stack_b.size() == 0)
	{
		balanceStack(stack_a, stack_b, ckPop, true);
	}
}
#endif