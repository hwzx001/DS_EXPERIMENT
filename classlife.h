#include<iostream>
using namespace std;
const int maxrow = 20, maxcol = 60;
class Life
{
private:
	int grid[maxrow + 2][maxcol + 2];
	int neighbor_count(int row, int col);
public:
	void initialize();
	void print();
	void update();
};
int Life::neighbor_count(int row,int col)
{
	int i, j;
	int count=0;
	for (i = row - 1;i <= row + 1;i++)
		for (j = col - 1;j <= col + 1;j++)
			count += grid[i][j];
	count -= grid[row][col];
	return count;
}
void Life::initialize()
{
	int row, col;
	for (row = 0;row <= maxrow + 1;row++)
		for (col = 0;col <= maxcol + 1;col++)
			grid[row][col] = 0;
	cin>> row >> col;
	while (row != -1 && col != -1)
	{
		if (row >= 1 && row <= maxrow && col >= 1 && col <= maxcol)
			grid[row][col] = 1;
		else
			cout << "Out of range";
		cin >> row >> col;
	}
}
void Life::print()
{
	int row, col;
	cout << "\nThe current life configuration is:" << endl;
	for (row = 1;row <= maxrow;row++)
	{
		for (col = 1;col <= maxcol;col++)
		{
			if (grid[row][col] == 1)
				cout << "*";
			else
				cout << "-";
		}
		cout << endl;
	}
	cout << endl;
}
void Life::update()
{
	int row, col;
	int new_grid[maxrow + 2][maxcol + 2];
	for (row=1;row<maxrow;row++)
	    for(col=1;col<maxcol;col++)
			switch (neighbor_count(row, col))
			{
			case 2:
				new_grid[row][col] = grid[row][col];
				break;
			case 3:
				new_grid[row][col] = 1;
				break;
			default:
				new_grid[row][col] = 0;
			}
	for (row = 1;row < maxrow;row++)
		for (col = 1;col < maxcol;col++)
			grid[row][col] = new_grid[row][col];
}
bool user_say_yes()
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
	return (c=='y'||c=='Y');
}