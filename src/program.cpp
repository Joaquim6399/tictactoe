#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void drawMatrix(int matrixArray[3][3]);
void drawBoard();
bool checkWinner(int matrixArray[3][3]);
bool checkGameStatus(int matrixArray[3][3]);

int main()
{

	int scores[3][3] = {0};

	drawMatrix(scores);
	
	bool winner = false;
	bool isGameOver = false;

	int player = 0;
	while(!winner && !isGameOver)
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
			scores[row - 1][column - 1] = -1;
		
		drawMatrix(scores);
		
		winner = checkWinner(scores);
		isGameOver = checkGameStatus(scores);
		if(isGameOver)
		{
			cout << "Game is over, no winner" << endl;
		}
		++player;
	}
	
	return 0;
}


bool checkWinner(int matrixArray[3][3])
{

		int sum = 0;
		//Check rows
		for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < 3; ++j)
			{
				sum += matrixArray[i][j];
			}


			if(sum == 3)
			{
				cout << "Player 1 winner, congratulations!" << endl;
				return true;
			} else if(sum == -3)
			{
					
				cout << "Player 2 winner, congratulations!" << endl;
				return true;
			}
		}
		
		sum = 0;
		for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < 3; ++j)
			{
				sum += matrixArray[j][i];
			}
			


			if(sum == 3)
			{
				cout << "Player 1 winner, congratulations!" << endl;
				return true;	
			} else if(sum == -3)
			{
					
				cout << "Player 2 winner, congratulations!" << endl;
				return true;	
			}
		}
		
		sum = 0;
		//Check diagonally
		for(int i = 0; i < 3; ++i)
		{
			sum += matrixArray[i][i];		
		}

		
		if(sum == 3)
		{
			cout << "Player 1 winner, congratulations!" << endl;
			return true;
		} else if(sum == -3)
		{
				
			cout << "Player 2 winner, congratulations!" << endl;
			return true;	
		}
		
		sum = 0;	
		for(int i = 2; i >= 0; --i)
		{
			sum += matrixArray[i][abs(i - 2)];
		}

		if(sum == 3)
		{
			cout << "Player 1 winner, congratulations!" << endl;
			return true;
		} else if(sum == -3)
		{
				
			cout << "Player 2 winner, congratulations!" << endl;
			return true;	
		}
		
		return false;
}

bool checkGameStatus(int matrixArray[3][3])
{
	bool isGameOver = true;

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(matrixArray[i][j] == 0)
			{
				
				isGameOver = false;
				break;
			}	
		}	
	}
	

	return isGameOver;
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
