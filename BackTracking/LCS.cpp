#include<bits/stdc++.h>
using namespace std;
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    
    int n = str1.length();
    int m = str2.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m];
}