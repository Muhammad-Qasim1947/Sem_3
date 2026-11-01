#include <iostream>
using namespace std;

bool issafe(int **arr, int x, int y, int n, bool **visited)
{
    if (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] != 1 && !visited[x][y])
    {
        return true;
    }
    return false;
}

bool ratinmaze(int **arr, int x, int y, int n, int **solarr, bool **visited)
{
    if (x == n - 1 && y == n - 1 && arr[x][y] == 1)
    {
        solarr[x][y] = 1;
        return true;
    }

    if (issafe(arr, x, y, n, visited))
    {
        solarr[x][y] = 1;
        visited[x][y] = true;

        // Move Down
        if (ratinmaze(arr, x + 1, y, n, solarr, visited))
        {
            return true;
        }

        // Move Up
        if (ratinmaze(arr, x - 1, y, n, solarr, visited))
        {
            return true;
        }

        // Move Right
        if (ratinmaze(arr, x, y + 1, n, solarr, visited))
        {
            return true;
        }

        // Move Left
        if (ratinmaze(arr, x, y - 1, n, solarr, visited))
        {
            return true;
        }

        cout << "[BACKTRACK] Dead end at (" << x << ", " << y << "). Undoing step." << endl;
        solarr[x][y] = 0;
        visited[x][y] = false;
        return false;
    }
    return false;
}

void printSolution(int **solArr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solArr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 4;

    int **arr = new int *[n];
    int **solArr = new int *[n];
    bool **visited = new bool *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        solArr[i] = new int[n];
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
            visited[i][j] = false;
        }
    }

    int maze[4][4] = {
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {1, 0, 1, 1}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = maze[i][j];
        }
    }

    cout << "=== RUNNING 4-DIRECTIONAL MAZE ===" << endl;
    if (ratinmaze(arr, 0, 0, n, solArr, visited))
    {
        cout << "\nPath found!" << endl;
        printSolution(solArr, n);
    }
    else
    {
        cout << "\nNo path exists." << endl;
    }

    return 0;
}