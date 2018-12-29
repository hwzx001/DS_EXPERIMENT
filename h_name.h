#pragma once
#pragma once
using namespace std;
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
#include<stack>
#include<string>
#include<cstring>
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
enum Error_code {
	success, fail, range_error, underflow, overflow, fatal, not_present, duplicate_error,
	entry_inserted, entry_found, internal_error
};