#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 100;
    vector<bool> door(n, false);

    for(int i=1; i<=n; i++) {
        int sq = sqrt(i);
        if(i % sq == 0){
           door[i-1] = !door[i-1];
        }
    }
    
    int cnt = 0;
    for(bool i : door) {
        cnt++;
        if(i){
        cout << cnt << endl;
        }
    }
}