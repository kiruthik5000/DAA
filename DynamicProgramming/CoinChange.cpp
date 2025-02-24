#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = {1, 3, 5};
    int amount = 11;

    vector<int> dp(amount + 1, amount + 1);  // Initialize dp array with a large value
    dp[0] = 0;  // Base case: 0 amount needs 0 coins

    for(int i = 1; i <= amount; i++) {
        for(int coin : coins) {
            if(i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << (dp[amount] > amount ? -1 : dp[amount]);
    return 0;
}
