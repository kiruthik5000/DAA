#include <iostream>
using namespace std;
int main(){
    int j;
    string str; cin>>str;
    string tar; cin>>tar;
    
    for(int i=0;i<=str.size()-tar.size();i++){
        for(j=0;j<tar.size();j++){
            if(str[i+j] != tar[j]) {
                break;
            }
        }
        if(j == tar.size())
            cout<<i<<endl;
    }
}