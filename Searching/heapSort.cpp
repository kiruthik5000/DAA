#include<bits/stdc++.h>
using namespace std;

class heapSort
{
private:
   vector<int> arr;
public:
   void create(int num) {arr.push_back(num);}
   void heapsort(){
      make_heap(arr.begin(), arr.end());
      sort_heap(arr.begin(), arr.end());

      for(int i: arr){
         cout << i << ' ';
      }
   }
};

int main() {
   int a;cin >> a;
   heapSort o;
   for(int i=0; i<a; i++){
   int num; cin >> num;
      o.create(num);
   }
   o.heapsort();
}