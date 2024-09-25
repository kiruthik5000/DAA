#include<bits/stdc++.h>
using namespace std;
    void permutation(string str, int st, int end) {
        if(st == end) {
        cout <<str<<endl;
            return;
        }
        for(int i=st; i<end; i++) {
            swap(str[i],str[st]);
            permutation(str, st+1, end);
        }
    } 
int main(){
    string str; 
    getline(cin, str);
    cout << "----"<<endl;
    permutation(str, 0, str.length());
}