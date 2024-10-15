#include<bits/stdc++.h>
using namespace std;
int main() {
    int val; cin >> val;
    int n; cin >> n;
    int coins[n];
    
    for(int i=0; i<n; i++)
        cin >> coins[i];
    
    vector<int> dp(val+1, INT_MAX);
    
    dp[0] = 0;
    
    for(int i=1; i<=val; i++) 
        for(int j=0; j<n; j++)
            if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
        
    cout << (dp[val] != INT_MAX ? dp[val] : -1);
}