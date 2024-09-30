#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter the number of Rows";
    int n;
    cin >> n;

    vector<vector<int>> pascal(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        pascal[i][0] = 1;

        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }

        for (int j = 0; j <= i; j++)
        {
            cout << pascal[i][j] << " ";
        }
        cout << endl;
    }
}