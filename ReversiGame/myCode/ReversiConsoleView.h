/**
 * @file ReversiConsoleView.h
 * @brief Implements the ReversiConsoleView class methods for the Reversi game display
 * Created on: 20-Nov-2023
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

/**
 * @class ReversiConsoleView
 * @brief This class serves as the console view for the Reversi game
 */
class ReversiConsoleView
{
private:
	/**Size of the Reversi board */
	static const int SIZE = 8;

	/**Pointer to the ReversiBoard object */
	const ReversiBoard *rboard;

public:
	/**
	 * @brief Parameterized Constructor for initializing
	 * ReversiConsoleView with a ReversiBoard
	 *
	 * @param rB : [IN] Pointer to a ReversiBoard object
	 */
	ReversiConsoleView(const ReversiBoard *rB);

	/**
	 * @brief Prints the current state of the Reversi board to the console
	 */
	void printBoard() const;

	/**
	 * @brief Destructor
	 */
	~ReversiConsoleView();
};

#endif /* REVERSICONSOLEVIEW_H_ */

