#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void drawMatrix(int matrixArray[3][3]);
void drawBoard();
int main()
{

	int scores[3][3] = {0};

	drawMatrix(scores);
	
	bool winner = false;
	int player = 0;
	while(!winner)
	{
		cout << endl;

		if(player % 2 == 0)
			cout << "Player 1, ";
		else
			cout << "Player 2, ";
		
		cout << "enter row and column: " << endl;	

		int row, column;
		cin >> row >> column;
		
		
		if(player % 2 == 0)
			scores[row - 1][column - 1] = 1;
		else
			scores[row - 1][column - 1] = 2;
		
		drawMatrix(scores);

		++player;
	}
	
	return 0;
}

void drawMatrix(int matrixArray[3][3])
{
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			cout << matrixArray[i][j] << " ";	
		}	

		cout << endl;
	}
}
void drawSmallboard()
{
	cout << endl;
	for(int i = 0; i < 2; ++i)
		cout << " |";
}

void drawBoard()
{
	cout << endl;
	//vertical lines
	for(int i = 0; i < 2; ++i)
		cout << "\t|\t|\t" << endl;
	
	//horizontal lines
	for(int i = 0; i < 25; ++i)
		cout << "-";
	cout << endl;
	
	//vertical lines
	for(int i = 0; i < 2; ++i)
		cout << "\t|\t|\t" << endl;
	
	//horizontal lines
	for(int i = 0; i < 25; ++i)
		cout << "-";
	cout << endl;

	//vertical lines
	for(int i = 0; i < 2; ++i)
		cout << "\t|\t|\t" << endl;

	cout << endl;
}
