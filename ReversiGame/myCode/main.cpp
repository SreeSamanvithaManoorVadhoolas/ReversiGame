/**
 * @file main.cpp
 * @brief Main program for an 8x8 Reversi game
 * Created on: 20-Nov-2023
 * Author: Sree Samanvitha Manoor Vadhoolas
 *
 * Initializes the game board and console view. Players take turns making moves,
 * and the game continues until no valid moves are available for both players.
 * Displays the current state of the board and suggests moves for each turn.
 * Supports two players and a simple console interface.
 *
 * @return 0 upon successful completion
 */
// Standard (system) header files
#include <iostream>
#include <cstdlib>

using namespace std;

// Add your project's header files here
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"



// Main program
int main()
{
	cout << "REVERSI!!" << endl;

	ReversiBoard rObj;
	ReversiConsoleView view(&rObj);

	int inputX, inputY;

	ReversiBoard::ReversiState currentPlayer = ReversiBoard::Player1;
	while (1)
	{
		view.printBoard();
		cout << "Current player = Player" << currentPlayer << endl;

		rObj.printSuggestions(currentPlayer);

		//check if moves are available for the current player
		if (rObj.checkIfMovesAvail(currentPlayer))
		{
			cout << "Enter co-ordinates: ";
			cin >> inputX >> inputY;

			bool operationSuccessful = rObj.setState(inputX, inputY,
					currentPlayer);

			if (operationSuccessful)
			{
				//switch player only if move was successful
				currentPlayer =
						(currentPlayer == ReversiBoard::Player1) ?
								ReversiBoard::Player2 : ReversiBoard::Player1;
			}
			else
			{
				cout << "Invalid co-ordinates. Re-enter!" << endl;
			}
		}
		else
		{
			cout << "No more moves available" << endl;
			break;
		}

	}

	return 0;
}
