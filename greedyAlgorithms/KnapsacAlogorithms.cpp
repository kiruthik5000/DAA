#include<bits/stdc++.h>
using namespace std;
int main(){
    int a; cin >> a;
    int amount; cin >> amount;
    int weight[a], value[a];
    
    for(int i=0; i<a; i++) {
        cin >> weight[i] >> value[i];
    }
    
    for(int i=0; i<a-1; i++) {
        for(int j=0; j<a-i-1; j++) {
            if( (weight[j] / value[j]) > (weight[j+1] / value[j+1])){
                swap(weight[j], weight[j+1]);
                swap(value[j], value[j+1]);
            }
        }
    }
    
    if(amount < value[0]){
        cout << "Invalid input";
        return 0;
    }
    double tot = 0.0;
    for(int i=0; i<a; i++) {
        if(amount >= value[i]){
            tot += weight[i];
            amount -= value[i];
        }else{
            tot += ((double) weight[i] / value[i]) * amount;
            amount = 0;
        }
    }
    
    cout << fixed<<setprecision(2)<<tot <<endl<<amount;
}