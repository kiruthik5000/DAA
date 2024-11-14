#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>>& board, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << board[i][j] << " ";
        cout<<endl;
    }
}
bool isSafe(vector<vector<char>>& board,int row, int col, int n){
    for(int i=0;i<col;i++)
        if(board[row][i] == 'Q')
        return false;
    for(int i=row, j=col; i>=0 && j>=0; i--,j--)
        if(board[i][j] == 'Q')
        return false;
    for(int i=row, j=col; i<n && j>=0; i++,j--)
        if(board[i][j] == 'Q')
        return false;
    return true;
}
void PlaceQueen(vector<vector<char>>& board,int col, int n, int& cnt){
    if(col >= n){
        printBoard(board, n);
        cout << endl;
        cnt++;
        return ;
    }
    for(int i=0;i<n;i++){  // rows
        if(isSafe(board, i, col, n)){
            board[i][col] = 'Q';
        PlaceQueen(board, col+1, n, cnt);
            board[i][col] = '-';
        }
    }
}
int main(){
    int n; cin >> n;
    vector<vector<char>> board(n, vector<char> (n, '-'));
    int cnt = 0;
    PlaceQueen(board, 0, n, cnt);
    cout << "Total: "<<cnt;
}

