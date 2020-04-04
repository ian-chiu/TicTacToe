#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

vector<char> square{'1','2','3','4','5','6','7','8','9'};
void board();
int checkWin();

int main()
{
	int player = 1;
	//game loop
	int state{0};
	bool playAgain = true;
	char mark{};
	while(playAgain)
	{
		board();
		while(state == 0)
		{
			mark = (player == 1) ? 'X' : 'O';
			int mark_pos{0};
			
			//check whose turn(if player 1 or 2)
			if(player == 1)
			{
				//choose where to mark 
				cout << "Player 1, enter a number: " << endl;
				cin >> mark_pos;
				if( isalpha(square[mark_pos-1]) || mark_pos / 10 != 0 || mark_pos <= 0)
				{
					cout << "Invalid input, please enter another number!\n";
					continue;
				}
				square[mark_pos-1] = mark;
				//update the board
				board();
				state = checkWin();
				player = 2;
			}
			else //player 2
			{
				//choose where to mark 
				cout << "Player 2, enter a number: " << endl;
				cin >> mark_pos;
				if( isalpha(square[mark_pos-1]) || mark_pos / 10 != 0 || mark_pos <= 0)
				{
					cout << "Invalid input, please enter another number!\n";
					continue;
				}
				square[mark_pos-1] = mark;
				//update the board
				board();
				state = checkWin();
				player = 1;
			}
		}
		
		if(state == 1)
		{
			if(player == 1)
				cout << "player 2 wins!!" << endl;
			else
				cout << "player 1 wins!!" << endl;
		}		
		else if(state == 2)
			cout << "TIE GAME!!" << endl;
		
		cout << "Do you want to play again?(Press any button to continue or Press q to quit)";
		char ans{};
		cin >> ans;
		if(ans == 'q')
			playAgain = false;
		else
		{
			square = {'1','2','3','4','5','6','7','8','9'};
			state = 0;
			player = 1;
		}			
	}	
	return 0;
}

int checkWin()
{
	bool isTie = true;
	for(auto c : square)
		if(isdigit(c))
			isTie = false;
	
	if(isTie)
		return 2;
		
	if(
		(square[0] == square[1] && square[1] == square[2]) ||
		(square[3] == square[4] && square[4] == square[5]) ||
		(square[6] == square[7] && square[7] == square[8]) ||
		(square[0] == square[3] && square[3] == square[6]) ||
		(square[1] == square[4] && square[4] == square[7]) ||
		(square[2] == square[5] && square[5] == square[8]) ||
		(square[0] == square[4] && square[4] == square[8]) ||
		(square[2] == square[4] && square[4] == square[6]))
		return 1;
	else
		return 0;
	
}

void board()
{
	system("cls");
	cout << "\tTic Tac Toe\n" << "Player 1 <X> - Player 2 <O>\n";
	cout << "\t   |   |   \n";
	cout << "\t " << square[0] << " | " << square[1] << " | " << square[2] << endl;
	cout << "\t___|___|___\n";
	cout << "\t   |   |   \n";
	cout << "\t " << square[3] << " | " << square[4] << " | " << square[5] << endl;
	cout << "\t___|___|___\n";
	cout << "\t   |   |   \n";
	cout << "\t " << square[6] << " | " << square[7] << " | " << square[8] << endl;
	cout << "\t   |   |   \n";
}
