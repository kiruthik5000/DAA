#include <iostream>
using namespace std;

void merge(int* arr,int *left,int *right,int s1,int s2){
   
    int i=0,j=0,k=0;

    while(i<s1 && j<s2){
        if(left[i]>right[j]) arr[k++]=right[j++];
        else arr[k++]=left[i++];
    }
    
    while(i<s1)
        arr[k++] = left[i++];
    while(j<s2)
        arr[k++] = right[j++];
     
}

void divideArray(int *arr,int size){
    if(size==1){
        return ;
    }  
    int mid=size/2,ind,j=0;

    int *leftArray=new int[mid];
    int *rightArray=new int [size-mid];

    for(ind=0;ind<mid;ind++){
        leftArray[ind]=arr[ind];
    }
    for(ind=mid;ind<size;ind++){
        rightArray[j++] = arr[ind];
    }

     divideArray(leftArray,mid);
     divideArray(rightArray,size-mid);

     merge(arr,leftArray,rightArray,mid,size-mid);
}
int main() {
    int size,ind;
    cin>>size;
    int arr[size];
    for(ind=0;ind<size;ind++)
        cin>>arr[ind];

    divideArray(arr,size);

    for(ind=0;ind<size;ind++){
        cout<<arr[ind]<<" ";
    }
    return 0;
}