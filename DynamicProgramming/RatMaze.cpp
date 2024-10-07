#include<bits/stdc++.h>
using namespace std;

bool check(int row, int col,int n,vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
    return (row>=0 && row<n && col>=0 && col<n && matrix[row][col] == 1 && !visited[row][col]);
}

void calc(int row, int col, int n, vector<vector<int>>& matrix, vector<vector<bool>>& visited, string res, vector<string>& ans) {
    
    if(row == n-1 && col == n-1) {
        ans.push_back(res);
        return ;
    }

    visited[row][col] = true;

    // Down
    if(check(row+1,col,n,matrix,visited)) {
        calc(row+1, col, n, matrix, visited, res+"D", ans);
    }

    // Up
     if(check(row-1,col,n,matrix,visited)) {
        calc(row-1, col, n, matrix, visited, res+"U", ans);
    }

    //Right
     if(check(row,col+1,n,matrix,visited)) {
        calc(row, col+1, n, matrix, visited, res+"R", ans);
    }

    //Left
     if(check(row,col-1,n,matrix,visited)) {
        calc(row, col-1, n, matrix, visited, res+"L", ans);
    }
    
    visited[row][col] = false;
}

int main() {
    int a; cin >>a;
    
    vector<vector<int>> matrix(a, vector<int> (a, 0));
    vector<vector<bool>> visited(a, vector<bool> (a, false));
    vector<string> ans;
    
    for(int i=0; i<a; i++) {
        for(int j=0; j<a; j++) {
            cin >> matrix[i][j];
        }
    }
    
    calc(0, 0, a, matrix, visited, "", ans);
    
    for(string i : ans) {
        cout << i << endl;
    }
    
}