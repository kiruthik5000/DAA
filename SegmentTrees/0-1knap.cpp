#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) {
    vector<int> dp(W + 1);
    for (int i = 0; i < n; i++)
        for (int w = W; w >= wt[i]; w--)
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
    return dp[W];
}

int main() {
    int profit[] = {2, 4, 6, 8}, weight[] = {1, 2, 3, 4}, W = 5;
    int n = 4;
    cout << knapSack(W, weight, profit, n);
    return 0;
}
