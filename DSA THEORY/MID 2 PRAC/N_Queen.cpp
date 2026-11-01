#include <iostream>
using namespace std;

bool issafe(int **board, int rows, int cols, int n)
{
    // checking cols
    for (int i = 0; i < rows; i++)
    {
        if (board[i][cols] == 1)
        {
            return false;
        }
    }

    // checking rows
    for (int i = 0; i < cols; i++)
    {
        if (board[rows][i] == 1)
        {
            return false;
        }
    }

    // left diagonal
    for (int i = rows, j = cols; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // right diagonal
    for (int i = rows, j = cols; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool solvequeen(int **board, int row, int n)
{
    if (row == n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (issafe(board, row, col, n))
        {
            board[row][col] = 1;
            if (solvequeen(board, row + 1, n))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                cout << " Q ";
            }
            else
            {
                cout << " . ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter board size: ";
    cin >> n;

    int **board = new int*[n];

    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if (solvequeen(board, 0, n))
    {
        cout << "\nSolution found:\n";
        printBoard(board, n);
    }
    else
    {
        cout << "No solution exists!";
    }

    // Memory deallocation
    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }

    delete[] board;

    return 0;
}