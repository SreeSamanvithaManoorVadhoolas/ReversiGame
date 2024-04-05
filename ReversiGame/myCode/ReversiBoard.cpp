/**
 * @file ReversiBoard.cpp
 * @brief Implements the ReversiBoard class methods for the Reversi game operation
 * Created on: 20-Nov-2023
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#include "ReversiBoard.h"
#include <iostream>

/**
 * @brief Default constructor which does the initial board setup
 *
 * @attention The constructor assigns all the elements of board
 * to empty state and sets the initial two pieces for each player
 */
ReversiBoard::ReversiBoard()
{
	count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j] = ReversiState::Empty;
		}
	}
	board[3][3] = board[4][4] = ReversiState::Player1;  // Player 1
	board[3][4] = board[4][3] = ReversiState::Player2;  // Player 2
}

/**
 * @brief To update the given inputState for the given coordinates
 *
 * @param int inputX					: [IN] the input X Coordinate
 * @param int inputY					: [IN] the input Y Coordinate
 * @param ReversiState inputState		: [IN] input player state
 */
void ReversiBoard::updateCoordinate(int inputX, int inputY,
		ReversiState inputState)
{
	board[inputX][inputY] = inputState;
}

/**
 * @brief To return opponent player of the given state
 *
 * @param ReversiState inputState		: [IN] input player state
 *
 * @return opponent of the inputState
 */
ReversiBoard::ReversiState ReversiBoard::getOpponent(ReversiState state) const
{
	return (state == Player1) ? Player2 : Player1;
}

/**
 * @brief To check if direction is valid for given coordinates and state
 *
 * @param int inputX					: [IN] input X Coordinate
 * @param int inputY					: [IN] input Y Coordinate
 * @param ReversiState inputPlayerState	: [IN] input player state
 *
 * @return true if direction is valid or false
 *
 * @attention This function also updates flippedCoordinates[][]
 * with the co-ordinates to be flipped with respect to inputPlayerState
 */
bool ReversiBoard::isDirectionValid(int inputX, int inputY,
		ReversiState inputPlayerState)
{
	count = 0;
	for (int i = 0; i < SIZE * SIZE; i++)
	{
		flippedCoordinates[i][0] = 0;
		flippedCoordinates[i][1] = 0;
	}

	if (inputX < 0 || inputX >= SIZE || inputY < 0 || inputY >= SIZE
			|| board[inputX][inputY] != ReversiState::Empty)
	{
		return false;
	}

	const int coordinates[8][2] =
	{
	{ -1, -1 },
	{ -1, 0 },
	{ -1, 1 },
	{ 0, -1 },
	{ 0, 1 },
	{ 1, -1 },
	{ 1, 0 },
	{ 1, 1 } };

	for (int i = 0; i < SIZE; i++)
	{
		int directionX = coordinates[i][0];
		int directionY = coordinates[i][1];

		int r = inputX + directionX;
		int c = inputY + directionY;

		if (r < 0 || r >= SIZE || c < 0 || c >= SIZE
				|| board[r][c] == getOpponent(inputPlayerState))
		{
			int whileCount = 0;
			while (r >= 0 && r < SIZE && c >= 0 && c < SIZE)
			{
				whileCount++;
				if (board[r][c] == Empty)
				{
					whileCount--;
					break;
				}
				else if (board[r][c] == inputPlayerState)
				{

					int tempR = r - directionX;
					int tempC = c - directionY;
					do
					{
						flippedCoordinates[count][0] = tempR;
						flippedCoordinates[count][1] = tempC;
						count++;
						whileCount--;
						tempR = tempR - directionX;
						tempC = tempC - directionY;
					} while (whileCount > 1);
					break;
				}
				r += directionX;
				c += directionY;
			}

		}
	}

	return count > 0;
}

/**
 * @brief Returns the state of the cell at the specified coordinates
 *
 * @param int x 				: [IN] The X Coordinate
 * @param int y  				: [IN] The Y Coordinate
 *
 * @return The state of the cell at the specified coordinates
 */
ReversiBoard::ReversiState ReversiBoard::queryState(int x, int y) const
{
	return board[x][y];
}

/**
 * @brief Sets the state for the input coordinates if the move is valid
 *
 * @param int inputX  						: [IN] The input X Coordinate
 * @param int inputY  						: [IN] The input Y Coordinate
 * @param ReversiState inputPlayerState  	: [IN] The input player state
 *
 * @return True if the state setting is complete else false
 */
bool ReversiBoard::setState(int inputX, int inputY,
		ReversiState inputPlayerState)
{
	if (isDirectionValid(inputX, inputY, inputPlayerState))
	{

		updateCoordinate(inputX, inputY, inputPlayerState);
		for (int i = 0; i < count; i++)
		{
			updateCoordinate(flippedCoordinates[i][0], flippedCoordinates[i][1],
					inputPlayerState);
		}

		return true;
	}
	else
	{
		return false;
	}

	return false;
}

/**
 * @brief Prints suggestions for valid moves for given player
 *
 * @param ReversiState inputState:[IN]State of the player
 */
void ReversiBoard::printSuggestions(ReversiState inputState)
{
	std::cout << "Suggestions:";
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (isDirectionValid(i, j, inputState))
			{
				std::cout << "(" << i << "," << j << ")" << " ";
			}
		}
	}

	std::cout << "\n";
}

/**
 * @brief Checks if there are any valid moves available for the given player
 *
 * @param inputState :  The player for which moves are checked
 *
 * @return True if there are valid moves available else false
 */
bool ReversiBoard::checkIfMovesAvail(ReversiState inputState)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (isDirectionValid(i, j, inputState))
			{
				return true;
			}
		}
	}
	return false;
}

/**
 * @brief Destructor
 */
ReversiBoard::~ReversiBoard()
{
}
