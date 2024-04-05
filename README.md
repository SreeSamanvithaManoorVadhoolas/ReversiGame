# Reversi Console Game

This repository contains a simple implementation of the classic board game Reversi (also known as Othello) designed to be played in a console environment. Players take turns placing pieces on an 8x8 grid, attempting to capture their opponent's pieces by surrounding them with their own. (https://en.wikipedia.org/wiki/Reversi).
Link for the online game: https://cardgames.io/reversi/

## Files Included

# 1. ReversiBoard.h, ReversiBoard.cpp:
- Declares and implements the ReversiBoard class, which represents the state of the game board.
- Provides methods for querying and setting the state of individual cells on the board.
- Implements game logic for checking the validity of moves and updating the board accordingly.

# 2. ReversiConsoleView.h, ReversiConsoleView.cpp:
- Declares and implements the ReversiConsoleView class, responsible for displaying the game board on the console.
- Utilizes the ReversiBoard class to obtain the state of the board and generate the appropriate console output.

# 3. main.cpp:
- Contains the main program for playing the Reversi game.
- Initializes the game board and console view.
- Implements a loop where players take turns making moves until no valid moves are available for either player.

## How to Play:
1. Compile the provided source files (https://github.com/sreesamanvitha07/ReversiGame/tree/master/ReversiGame/myCode) using a C++ compiler.
2. Run the compiled executable.
3. Follow the on-screen instructions to make moves on the board.
The game continues until no valid moves are available for either player.
