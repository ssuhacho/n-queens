/**
* [Suha Cho]
* [ChessBoard.cpp]
**/

#include <iostream>
#include "ChessBoard.h"

using namespace std;

//Default constructor
ChessBoard::ChessBoard()
{
    boardSize = 8; //sets the default board size to 8.

    boardPtr = new char* [boardSize];

    //creating 2D array
    for (int i = 0; i < boardSize; i++)
    {
        boardPtr[i] = new char [boardSize];
    }

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            boardPtr[i][j] = '*';
        }
    }
 }

//Constructor that sets the board size to the given int size.
ChessBoard::ChessBoard(int size)
  {
    if (size < 4)
    {
        boardSize = 4; //sets the sise to 4.
    }
    else if (size > 12)
    {
        boardSize = 12; //sets the size to 12.
    }
    else
        boardSize = size; //sets the board size to the given int.


    boardPtr = new char* [boardSize];

      //creating 2D array
    for (int i = 0; i < boardSize; i++)
    {
        boardPtr[i] = new char[boardSize];
    }

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            boardPtr[i][j] = '*';
        }
    }

  }

ChessBoard::~ChessBoard() //destructor
{
    for (int i = 0; i < boardSize; i++)
    {
        delete boardPtr[i];
    }

    delete[] boardPtr;
}


bool ChessBoard::placeQueens (int column)
{
  int row = 0; //set the row index to 0.

  if (column >= boardSize)
    {
      return true; //if the board is filled, return true.
    }

  else
  {
    while (row < boardSize)//unconsidered rows exist in column.
    {
        //Starting with row, find the next square in column
        //that is not under attack by a queen placed in any
        //previous column.

        //if unattacked square exists in column
      if (checkingRow(row,column) && checkingUp(row,column) && checkingDown(row,column))
      {
        //place a queen in the un-attecked square.
        boardPtr[row][column] = 'Q';

        //Do a recursive call to try and place queens
        //in subsequent columns:
        if (!placeQueens(column + 1))
        {
          //no solution could be found. Remove the last queen placed.
            boardPtr[row][column] = '*';
            row++; //Increment row so search can continue in next iteration.
        }
        else
        //recursive calls were able to place queens in all columns to
        //the right of column, return true.
          return true;
      }

      else if (row < boardSize)
      {
          row++; //search continues in next iteration
      }

      else
        return false; //backtrack by returning false.
    }
    return false;
  }
}

//checks if queens are in the same row.
bool ChessBoard::checkingRow (int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (boardPtr[row][i] == 'Q')
        {
            return false; //return false if it's found.
        }
    }
    return true;
}

//checks if queens are in the diagonal position upper left of board.
bool ChessBoard::checkingUp(int row, int col)
{
    int r = row;
    int c = col;
    while (r >= 0 && c >= 0)
    {
        if (boardPtr[r][c] == 'Q')
        {
            return false; //return false if it's found.
        }
        //upper left of the board
        r = r - 1;
        c = c - 1;
    }
    return true;
}

//checks if queens are in the diagonal position bottom left of board.
bool ChessBoard::checkingDown(int row, int col)
{
    int r = row;
    int c = col;
    while (r < boardSize && c >= 0) //because r is incresing and c is decreasing in this loop
    {
        if (boardPtr[r][c] == 'Q')
        {
            return false; //return false if it's found.
        }
        //bottom left of the board
        r = r + 1;
        c = c - 1;
    }
    return true;
}


void ChessBoard::setSize(int n)
{
    //Deletes the existing board
    for (int i = 0; i < boardSize; i++)
    {
        delete boardPtr[i];
    }
    delete[] boardPtr;

  if (n < 4) //if the int n is less than 4
  {
    boardSize = 4; //sets the sise to 4.
  }
  else if (n > 12) //if n is greather than 12
  {
    boardSize = 12; //sets the size to 12.
  }
  else
    boardSize = n; //resets the board to be the size given.


   boardPtr = new char* [boardSize];

   for (int i = 0; i < boardSize; i++)
   {
       boardPtr[i] = new char[boardSize];
   }

   for (int i = 0; i < boardSize; i++)
   {
       for (int j = 0; j < boardSize; j++)
       {
           boardPtr[i][j] = '*';
       }
   }

}


int ChessBoard::getSize()
{
  return boardSize; //Returns the current size of the board.
}


bool ChessBoard::solve()
{
  return placeQueens(0); //calls the recursive placeQueens().
}


void ChessBoard::displayBoard() //Displays the board to the screen.
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
          //Individual squares on the board display with 1 space between them
            cout << " " << boardPtr[i][j];
        }
        cout << endl;
    }
}
