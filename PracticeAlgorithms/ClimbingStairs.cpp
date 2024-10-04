#include<bits/stdc++.h>
using namespace std;
int main() {
    int steps; cin >> steps;

    if(steps <= 1){
        cout << 1;
        return 0;
    }

    int val1 = 1;
    int val2 = 2;

    for(int i=3; i<= steps; i++) {
        int total = val1 + val2;
        val1 = val2;
        val2 = total;
    }

    cout << val2;
}