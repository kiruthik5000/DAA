#include<bits/stdc++.h>
using namespace std;
int fun(vector<int>& arr, int l, int r) {
    int min = arr[l];
    for(int i=l+1; i<r; i++) {
        if(min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}
int main() { 
    int n, opt, l, r;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; cin >>arr[i++]);

    int q; cin >> q;
    while(q-->0)
    {
        cin >> opt>> l >> r;
        if(opt == 1) {
            cout << fun(arr, l, r) << endl;
        }
        else if(opt == 2) {
            arr[l] = r;
        }
    }
    
}