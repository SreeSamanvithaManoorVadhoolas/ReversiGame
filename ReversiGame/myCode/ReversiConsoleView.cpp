/**
 * @file ReversiConsoleView.cpp
 * @brief Declares the ReversiConsoleView class for displaying the Reversi game board
 * Created on: 20-Nov-2023
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#include "ReversiConsoleView.h"
#include<iostream>

/**
 * @brief Parameterized Constructor for initializing
 * ReversiConsoleView with a ReversiBoard
 *
 * @param rB : [IN] Pointer to a ReversiBoard object
 */
ReversiConsoleView::ReversiConsoleView(const ReversiBoard *rB)
{
	rboard = rB;
}

/**
 * @brief Prints the current state of the Reversi board to the console
 */
void ReversiConsoleView::printBoard() const
{
	char output;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			switch (rboard->queryState(i, j))
			{
			case ReversiBoard::Empty:
				output = '*';
				break;
			case ReversiBoard::Player1:
				output = 'X';
				break;
			case ReversiBoard::Player2:
				output = 'O';
				break;
			default:
				output = '*';
				break;
			}

			std::cout << output << " ";
		}
		std::cout << std::endl;
	}
}

/**
 * @brief Destructor
 */
ReversiConsoleView::~ReversiConsoleView()
{
}
