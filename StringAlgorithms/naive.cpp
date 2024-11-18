#include<bits/stdc++.h>
using namespace std;
int main() {
    string str1, str2; cin >> str1 >> str2;

    int n = str1.length();
    int m = str2.length();

    bool find = false;
    for(int i=0; i<=n - m; i++) {
        int j;
        for(j=0; j<m; j++) {
            if(str1[i+j] != str2[j]){
                break;
            }
        }
        if(j == m) {
            find = true;
            cout << i << " ";
        }
    }
    if(!find){
        cout << "no pattern";
        return 0;
    }
    
}