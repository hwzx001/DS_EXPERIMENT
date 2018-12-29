#include<iostream>
#include"classlife.h"

Life configuration;
int main()
{
	configuration.initialize();
	configuration.print();
	while (user_say_yes()) {
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations?";
	}
}


