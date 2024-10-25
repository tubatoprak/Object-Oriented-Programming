#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Player
{
	public:
	virtual int getGuess() = 0;
	int guess;
};

class HumanPlayer : public Player
{
	public:
		HumanPlayer() : Player()
		{

		}
		int getGuess() 
		{
			cout << "Please enter your guess: ";
			cin >> guess;
			return guess;
		}
};

class ComputerPlayer : public Player
{
	public:
		ComputerPlayer() : Player()
		{

		}
		int getGuess()
		{
			return rand() % 100 + 1;
		}
};

bool checkForWin(int guess, int answer)
{
	if (answer == guess)
	{
		cout << "You're right! You win!" << endl;
		return true;
	}
	else if (answer < guess)
		cout << "Your guess is too high." << endl;
	else
		cout << "Your guess is too low." << endl;
	return false;
}

void play(Player &player1, Player &player2)
{
	int answer = 0, guess = 0;
	answer = rand() % 100;
	bool win = false;

	while (!win)
	{
		cout << "Player 1's turn to guess." << endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win)
			return;

		cout << "Player 2's turn to guess." << endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
	}
}

int main()
{
	srand(time(NULL));
	HumanPlayer humanPlayer1;
	HumanPlayer humanPlayer2;
	ComputerPlayer computerPlayer1;
	ComputerPlayer computerPlayer2;

	cout << "---------Human vs Human---------\n";
	play(humanPlayer1, humanPlayer2);

	cout << "---------Human vs Computer-------\n";
	play(humanPlayer1, computerPlayer1);

	cout << "-------Computer vs Computer-------\n";
	play(computerPlayer1, computerPlayer2);

    return 0;
}