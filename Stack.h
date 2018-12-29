#pragma once
#include "utility.h"
const int maxstack = 10;
typedef double Stack_entry;

class Stack 
{
private:
	int count;
	Stack_entry entry[maxstack];
public:
	Stack();
	bool empty()const;
	Error_code pop();
	Error_code top(Stack_entry &item)const;
	Error_code push(const Stack_entry &item);
	int size()const;

};
Stack::Stack()
{
	count = 0;
}
inline bool Stack::empty() const
{
	bool outcome = true;
	if (count > 0) outcome = false;
	return outcome;
}
 Error_code Stack::pop()
{
	 Error_code outcome = success;
	 if (count == 0)
		 outcome = underflow;
	 else --count;
	return outcome;
}
 Error_code Stack::top(Stack_entry &item)const
 {
	 Error_code outcome = success;
	 if (count ==0) outcome =underflow;
	 else item = entry[count - 1];
	 return outcome;
 }
 Error_code Stack::push(const Stack_entry & item)
 {
	 Error_code outcome = success;
	 if (count >= maxstack) outcome = overflow;
	 else entry[count++] = item;
	 return outcome;
 }
 inline int Stack::size() const
 {
	 return count;
 }
