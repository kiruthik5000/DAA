#include <iostream>
#include <iomanip>
using namespace std;

int arrRow[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int arrCol[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool check(int row, int col, int **mat, int n)
{
    return (row >= 0 && row < n && col >= 0 && col < n && mat[row][col] == -1);
}

bool fun(int row, int col, int **mat, int n, int num)
{
    if (num == n * n)
        return true;


    for (int ind = 0; ind < 8; ind++)
    {
        int nextRow = row + arrRow[ind];
        int nextCol = col + arrCol[ind];
        if (check(nextRow, nextCol, mat, n))
        {
            mat[nextRow][nextCol] = num;
            if (fun(nextRow, nextCol, mat, n, num + 1))
                return true;
            mat[nextRow][nextCol] = -1; // Backtrack
        }
    }
    return false;
}

int main()
{
    int n, row, col;
    cin >> n;
    int **mat = new int *[n];

    for (row = 0; row < n; row++)
        mat[row] = new int[n];

    for (row = 0; row < n; row++)
        for (col = 0; col < n; col++)
            mat[row][col] = -1;

    mat[0][0] = 0;

    if (fun(0, 0, mat, n, 1))
    {
        for (row = 0; row < n; row++, cout << endl)
            for (col = 0; col < n; col++)
                cout << setw(2) << mat[row][col] << " ";
    }
    else
        cout << "Not Possible";
    return 0;
}