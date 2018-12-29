#include"h_name.h"
#include"maze.h"


int main()
{
	maze test(0);
	test.print_map();
	cout << "******************"<<endl;
	test.get_node();
	cout << "*******************" << endl;
	test.print_result();
	system("pause");
}