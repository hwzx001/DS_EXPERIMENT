#pragma once
#include<iostream>
#include<stack>
using namespace std;

char get_command()
{
	char command;
	bool waiting = true;
	cout << "select command and press<Enter>";
	while (waiting)
	{
		cin >> command;
		command = tolower(command);
		if (command == '?' || command == '+' || command == '-' || command == '*' || command == '/' || command == 'q' || command == '=')
			waiting = false;
		else
		{
			cout << "please enter a valid command:" << endl;
		}
	}
	return command;
}

bool do_command(char command, stack<int> &numbers)
{

}