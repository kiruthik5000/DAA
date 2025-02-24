#include<bits/stdc++.h>
using namespace std;

void fcfs(vector<int>&request, int n, int inital){
    int total = 0;
    for(int i : request) {
        total += abs(i - inital);
        inital = i;
    }
    cout << "total head Movement is "<<total;
}

int main() {
    int n = 5;
    vector<int>request = {98, 183, 37, 122, 14, 124, 65, 67};
    int intial = 53;

    fcfs(request, n, intial);
}