#include <bits/stdc++.h>
using namespace std;

int n = 9;

void printboard(vector<vector<int>> &board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j]<< " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> &board, int row, int col, int val)
{
    for (int i = 0; i < n; i++)
    {
        if(board[i][col] == val || board[row][i] == val){
            return false;
        }
        int subrow = 3 * (row / 3) + i / 3;
        int subcol = 3 * (col / 3) + i % 3;
        if(board[subrow][subcol] == val){
            return false;
        }
    }
    return true;
}
bool solver(vector<vector<int>> &board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(board, i, j, val))
                    {
                        board[i][j] = val;
                        if (solver(board))
                        {
                            return true;
                        }
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    if (solver(board))
    {
        printboard(board);
    }
    else
    {
        cout << "No Solution";
    }
}

/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

*/