#include<bits/stdc++.h>
using namespace std;
int main() {
    int val; cin >> val;
    int n; cin >> n;
    vector<int> coins(n);
    
    for(int i=0; i<n; i++)
        cin >> coins[i];
    
    sort(coins.rbegin(), coins.rend());

    int cnt  = 0;
    for(int c : coins) {
        if(c <= val) {
            cnt += val / c;
            val %= c;
        }
    }

    cout << cnt;
}