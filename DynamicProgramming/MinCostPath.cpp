#include<bits/stdc++.h>
using namespace std;
int main() {
    int a; cin >> a;

    int mat[a][a];

    for(int i=0; i<a; i++)
        for(int j=0; j<a; j++)
            cin >> mat[i][j];
            
    for(int i=1; i<a; i++) {
        mat[i][0] += mat[i-1][0];
    }
    for(int i=1; i<a; i++) {
        mat[0][i] += mat[0][i-1];
    }
    for(int i=1; i<a; i++)
        for(int j=1; j<a; j++) 
            mat[i][j] += min({mat[i-1][j-1], mat[i-1][j], mat[i][j-1]});

    cout << mat[a-1][a-1];
}
