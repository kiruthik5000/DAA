#include <iostream>
using namespace std;

int main(){
    int size;
    cin>>size;
    int arr[size];

    for(int i=0;i<size;i++) cin>>arr[i];

    for(int i=0;i<size;i++){
        int min = i;
        for(int j=i+1;j<size;j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }

     for(int i=0;i<size;i++) cout<<arr[i]<<" ";
}