/**
 * @file ReversiBoard.h
 * @brief Declares the ReversiBoard class for the Reversi game
 * Created on: 20-Nov-2023
 * Author: Sree Samanvitha Manoor Vadhoolas
 */
#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/**
 * @class ReversiBoard
 *
 * @brief This class represents the Reversi game board and its operations
 */
class ReversiBoard
{
public:
	/**
	 * @enum ReversiState
	 *
	 * @brief Enum representing the possible states of a cell on the board
	 */
	typedef enum
	{
		Empty = 0, Player1 = 1, Player2 = 2
	} ReversiState;

private:
	/** Size of the Reversi board */
	static const int SIZE = 8;

	/** 2D array of ReversiState type representing the Reversi game board */
	ReversiState board[SIZE][SIZE];

	/** Counter variable for the total number of
	 * coordinates for flippedCoordinates[][] array */
	int count;

	/** Array to store coordinates for flipping */
	int flippedCoordinates[SIZE * SIZE][2];

	/**
	 * @brief To return opponent player of the given state
	 *
	 * @param ReversiState inputState		: [IN] input player state
	 *
	 * @return opponent of the inputState
	 */
	ReversiState getOpponent(ReversiState inputState) const;

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
	bool isDirectionValid(int inputX, int inputY,
			ReversiState inputPlayerState);

	/**
	 * @brief To update the given inputState for the given coordinates
	 *
	 * @param int inputX					: [IN] the input X Coordinate
	 * @param int inputY					: [IN] the input Y Coordinate
	 * @param ReversiState inputState		: [IN] input player state
	 */
	void updateCoordinate(int inputX, int inputY,
			ReversiState inputPlayerState);

public:
	/**
	 * @brief Default constructor which does the initial board setup
	 *
	 * @attention The constructor assigns all the elements of board
	 * to empty state and sets the initial two pieces for each player
	 */
	ReversiBoard();

	/**
	 * @brief Returns the state of the cell at the specified coordinates
	 *
	 * @param int x 				: [IN] The X Coordinate
	 * @param int y  				: [IN] The Y Coordinate
	 *
	 * @return The state of the cell at the specified coordinates
	 */
	ReversiState queryState(int x, int y) const;

	/**
	 * @brief Sets the state for the input coordinates if the move is valid
	 *
	 * @param int inputX  						: [IN] The input X Coordinate
	 * @param int inputY  						: [IN] The input Y Coordinate
	 * @param ReversiState inputPlayerState  	: [IN] The input player state
	 *
	 * @return True if the state setting is complete else false
	 */
	bool setState(int inputX, int inputY, ReversiState inputPlayer);

	/**
	 * @brief Prints suggestions for valid moves for given player
	 *
	 * @param ReversiState inputState:[IN]State of the player
	 */
	void printSuggestions(ReversiState inputState);

	/**
	 * @brief Checks if there are any valid moves available for the given player
	 *
	 * @param inputState :  The player for which moves are checked
	 *
	 * @return True if there are valid moves available else false
	 */
	bool checkIfMovesAvail(ReversiState inputState);

	/**
	 * @brief Destructor
	 */
	~ReversiBoard();
};

#endif /* REVERSIBOARD_H_ */
