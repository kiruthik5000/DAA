#include <bits/stdc++.h>
using namespace std;

int lis(int arr[], int n) {
    vector<int> dp(n, 1);  
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    sort(dp.begin(), dp.end());
    return dp[n-1];
}

int main() {
    int a;
    cin >> a;
    int arr[a];
    for (int i = 0; i < a; i++)
        cin >> arr[i];

    cout << lis(arr, a);
}
