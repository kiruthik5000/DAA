#include<bits/stdc++.h>
using namespace std;
int main() {
    int a; cin>>a;
    int arr[a];
    for(int i=0; i<a; cin>>arr[i++]);

    vector<int> dp(a, 1);

    for(int i=1; i<a; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}