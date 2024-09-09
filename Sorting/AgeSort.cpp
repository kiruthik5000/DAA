#include<bits/stdc++.h>  //3
using namespace std;     //22 5.6
struct Person           //20 6.13

{                      // 30  5.9
    int age;
    float height;
};

int main(){
    int a; cin >>a;
    Person arr[a];
    for(int i=0; i<a; i++) {
        cin >> arr[i].age;
        cin >> arr[i].height;
    }
    int x; cin >> x;
    if(x == 1){

    for(int i=0;i<a;i++){
        int min = i;
    for(int j=i+1; j<a; j++) {
        if(arr[min].age > arr[j].age) min = j;
    }
    swap(arr[min],arr[i]);
    }

    }else if (x == 2) {

 for(int i=0;i<a;i++){
        int min = i;
    for(int j=i+1; j<a; j++) {
        if(arr[min].height > arr[j].height) min = j;
    }
    swap(arr[min],arr[i]);
    }

    }
    for (int i = 0; i < a; i++)
    {
      cout<<arr[i].age<<" ";
      cout<<arr[i].height<<endl;
    }
    
}