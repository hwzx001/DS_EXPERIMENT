#pragma once
#include <iostream>
#include <limits>
#include <cmath>
#include<cstdlib>
#include<cstddef>
#include<fstream>
#include<sstream>
#include<cctype>
#include<ctime>
#include<vector>
using namespace std;
bool user_says_yes()
{
	{
		bool initial_response = true;
		int c;
		do {
			if (initial_response)
				cout << "(y,n)?" << flush;
			else
				cout << "Respond with either y or n:" << flush;
			do {
				c = cin.get();
			} while (c == '\n' || c == ' ' || c == '\t');
			initial_response = false;
		} while (c != 'y'&&c != 'Y'&&c != 'n'&&c != 'N');
		return (c == 'y' || c == 'Y');
	}
}
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
enum Error_code {
	success, fail, range_error, underflow, overflow, fatal, not_present, duplicate_error,
	entry_inserted, entry_found, internal_error
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
	if (count == 0) outcome = underflow;
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

char get_command()
{
	char command;
	bool waiting = true;
	while (waiting) {
		cin >> command;
		command = tolower(command);
		if (command == '?' || command == '=' || command == '+' || command == '-' || command == '*' || command == '/' || command == 'q')
			waiting = false;
		else
		{
			cout << "Please enter a valid command" << endl;
		}
	}
	return command;
}
bool do_command(char command, Stack &numbers)
{
	double p;
	double q;
	switch (command)
	{
	case'?':
		cout << "Enter a real number:" << flush;
		cin >> p;
		if (numbers.push(p) == overflow)
			cout << "Stack full" << endl;
		break;
	case'=':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else
			cout << p << endl;
		break;
	case'+':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else
		{
			numbers.pop();
			if (numbers.top(q) == underflow)
			{
				cout << "Stack has just one entry" << endl;
			}
			else
			{
				numbers.pop();
				if (numbers.push(p + q) == overflow)
					cout << "Warning:Stack full,lost result" << endl;

			}
		}
		break;
	case'-':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else
		{
			numbers.pop();
			if (numbers.top(q) == underflow)
			{
				cout << "Stack has just one entry" << endl;
			}
			else
			{
				numbers.pop();
				if (numbers.push(p - q) == overflow)
					cout << "Warning:Stack full,lost result" << endl;

			}
		}
		break;
	case'*':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else
		{
			numbers.pop();
			if (numbers.top(q) == underflow)
			{
				cout << "Stack has just one entry" << endl;
			}
			else
			{
				numbers.pop();
				if (numbers.push(p * q) == overflow)
					cout << "Warning:Stack full,lost result" << endl;

			}
		}
		break;
	case'/':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else
		{
			numbers.pop();
			if (numbers.top(q) == underflow)
			{
				cout << "Stack has just one entry" << endl;
			}
			else
			{
				numbers.pop();
				if (numbers.push(q / p) == overflow)
					cout << "Warning:Stack full,lost result" << endl;

			}
		}
		break;
	case'q':
		cout << "Calculation finished.\n";
		return false;
	}
	return true;
}
int main()
{
	Stack stored_numbers;
	while (do_command(get_command(), stored_numbers));
}