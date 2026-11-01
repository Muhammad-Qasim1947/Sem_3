#include <iostream>
using namespace std;

bool issafe(char **board, int rows, int cols, char dig)
{
    // horizontal
    for (int j = 0; j < 9; j++)
    {
        if (board[rows][j] == dig)
        {
            return false;
        }
    }

    // vertical
    for (int i = 0; i < 9; i++)
    {
        if (board[i][cols] == dig)
        {
            return false;
        }
    }

    // grid
    int st_row = (rows / 3) * 3;
    int st_col = (cols / 3) * 3;

    for (int i = st_row; i <= st_row + 2; i++)
    {
        for (int j = st_col; j <= st_col + 2; j++)
        {
            if (board[rows][cols] == dig)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudoku(char **board, int rows, int cols)
{
    if (rows == 9)
    {
        return true;
    }

    int nextrow = rows;
    int nextcol = cols + 1;

    if (nextcol == 9)
    {
        nextrow = rows + 1;
        nextcol = 0;
    }

    if (board[rows][cols] != '.')
    {
        return sudoku(board, nextrow, nextcol);
    }

    for (char dig = '1'; dig <= '9'; dig++)
    {
        if (issafe(board, rows, cols, dig))
        {
            board[rows][cols] = dig;
            if (sudoku(board, nextrow, nextcol))
            {
                return true;
            }
            board[rows][cols] = '.';
        }
    }
    return false;
}

int main()
{
    char **board = new char *[9];

    char temp[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    for (int i = 0; i < 9; i++)
    {
        board[i] = new char[9];

        for (int j = 0; j < 9; j++)
        {
            board[i][j] = temp[i][j];
        }
    }

    if (sudoku(board, 0, 0))
    {
        cout << "Solved Sudoku:\n";

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution!";
    }

    for (int i = 0; i < 9; i++)
    {
        delete[] board[i];
    }

    delete[] board;

    return 0;
}