/**
* [Suha Cho]
* [ChessBoard.h]
**/

#include<iostream>
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

using namespace std;

class ChessBoard
{
  private:
    //pointer to a 2-dimensional character array on the heap which stores the board.
    char** boardPtr;

    //Tracks the size of the board. Valid sizes are 4 through 12.
    int boardSize;

    /**
    * placeQueens finds placements for the queens on the board.
    * @param column is the indicated column.
    * @Return true if a queen is successfully placed in column and
    * all columns to the right of column.
    * @pre it begins the search for a valid placement of a queen
    * at the indicated column in row 0.
    */
    bool placeQueens(int column);


  public:
    //Default constructor which sets the default board size to 8.
    ChessBoard();

    //Constructor which sets the board size to the given int.
    ChessBoard(int);

    //Destructor
    ~ChessBoard();

    /**
    * checkingRow is a function that checks if queens are in the same row.
    * @return true if queens are not in the same row. Otherwise, return false.
    * @pre Once checkingRow() is finished, it must return true
    * if queens are not found in the same row, and must return false
    * if queens are found.
    */
    bool checkingRow(int row, int col);

    /**
    * checkingUp is a function that checks
    * if queens are in the diagonal position upper left of board.
    * @return true if queens are not found in the postion.
    * If it's found return false.
    */
    bool checkingUp(int row, int col);

    /**
    * checkingDown is a function that checks
    * if queens are in the diagonal position bottom left of board.
    * @return true if queens are not found in the postion.
    * If it's found return false.
    */
    bool checkingDown(int row, int col);

    /**
    * setSize deletes the existing board and resets the board to be the size given.
    * @param n is the size given.
    * @pre If setSize(n) is called, the ChessBoard object must contain an n x n board.
    If the int n is less than 4, it must set the size to 4,
    if the int n is greater than 12 it must set the size to 12.
    */
    void setSize(int n);

    /**
    * getSize returns the current size of the board.
    * @return boardSize.
    * @pre  If the board is 10 x 10, getSize() must return 10.
    */
    int getSize();

    /**
    * solve is a non-recursive function that calls the recursive placeQueens().
    * @return true if the board was solved successfully.
    * @pre Once solve() is finished, if a solution was successfully found,
    the 2- dimensional array pointed to by boardPtr must contain the solution.
    */
    bool solve();

    /**
    * displayBoard displays the board to the screen.
    * @pre Queens should be displayed as a 'Q'
    * and individual squares on the board display with 1 space between them.
    * Blank squares on the board should be displayed as a single *.
    */
    void displayBoard();
};

#endif
