#include<bits/stdc++.h>
using namespace std;

void slider(vector<int>& arr, int n) {
    for(int i=0; i<=arr.size() - n; i++) {
        int sum = INT_MIN;
        for(int j=i; j<i + n; j++) {
            sum = max(sum, arr[j]);
        }
        cout << sum << endl;
    }
}

int main() {
    int a; cin >> a; 
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    slider(arr, a) ;
}