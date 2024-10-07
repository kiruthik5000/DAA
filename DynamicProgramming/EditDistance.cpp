#include<bits/stdc++.h>
using namespace std;
int fmin(int a, int b,int c){
    return min(a, min(b, c));
}
int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

    for(int i=1; i<=m; i++) {
        dp[i][0] = i; 
    }
    for(int i=1; i<=n; i++) {
        dp[0][i] = i;
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(str1[i-1] == str2[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = fmin(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
        }
    }

    cout << dp[m][n];
}