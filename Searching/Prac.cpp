#include<bits/stdc++.h>
using namespace std;
void merge(int* arr,int* leftarray, int* rightarray, int s1, int s2) {
    int i=0,j=0,k=0;
    while(i < s1 && j < s2) {
        if(leftarray[i] < rightarray[j]) arr[k++] = leftarray[i++];
        else arr[k++] = rightarray[j++];
    }
    while(i < s1) arr[k++] = leftarray[i++];
    while(j < s2) arr[k++] = rightarray[j++];
}
void selection(int *arr,int a){
   if(a == 1) return;
   int mid = a / 2;
   int* leftarray = new int[mid];
   int* rightarray = new int[a - mid];
    int k=0;
   for(int i=0;i<mid; i++) leftarray[i]= arr[i];
   for(int j=mid; j<a; j++) rightarray[k++] = arr[j];

   selection(leftarray,mid);
   selection(rightarray,a - mid);
   merge(arr,leftarray,rightarray,mid,a - mid);
   return ;
}
int main(){
    int a; cin >> a;
    int arr[a];
    for(int i=0; i<a; cin >> arr[i++]) ;
    
    selection(arr,a);
    for(int i=0; i<a; cout << arr[i++] << " ") ;
}