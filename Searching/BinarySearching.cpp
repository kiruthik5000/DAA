#include<bits/stdc++.h>
using namespace std;
int main(){
    int a; cin >> a;
    int arr[a];

    for(int i=0; i<a; cin >> arr[i++]);

    int f = 0, l = a - 1;
    int target; cin >> target;
    int res = -1; 
    while(f <= l) {
        int mid = (f + l) / 2;
        if (arr[mid] == target) {
            res = mid;
            l = mid - 1;
        }
        if (arr[mid] < target) f = mid + 1;
        if (arr[mid] > target) l = mid - 1;
    }
    if(res == -1){
    cout << "Not found";
    }else{
        cout << res;
    }
}