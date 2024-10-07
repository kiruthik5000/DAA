#include<bits/stdc++.h>
using namespace std;
int main() {
    int a; cin>>a;
    int arr[a];
    for(int i=0; i<a; cin>>arr[i++]);

    vector<int> dp(a, 1);

    for(int j=1; j<a; j++) {
        for(int i=0; i<j; i++) {
            if(arr[j] > arr[i]){ 
                dp[j] = dp[i]+1;
            }
        } 
    }
    cout << dp[a-1];
}