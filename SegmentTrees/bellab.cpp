#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

void bellmanFord(const vector<Edge>& arr,int n,int m,int source) {
    vector<int> distance(n,INT_MAX);
    distance[source] = 0;

    for(int i=0;i<n-1;i++) {
        for(auto edge : arr) {
            if(distance[edge.u] != INT_MAX && distance[edge.u] + edge.w < distance[edge.v]) {
                distance[edge.v] = distance[edge.u] + edge.w;
            }
        }
    }

    for(auto edge : arr) {
        if(distance[edge.u] != INT_MAX && distance[edge.u] + edge.w < distance[edge.v]) {
            cout<<"Negative weight cycle detected"<<endl;
            return;
        }
    }

    for(int i=0;i<n;i++) {
        if(distance[i] == INT_MAX) {
            cout<<"Path not found";
        }else{
        cout<<distance[i]<<endl;
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<Edge> arr(m);
    for(int i=0;i<m;i++) {
        if(!(cin>>arr[i].u>>arr[i].v>>arr[i].w)){
            cout<<"Invalid input";
            return 0;
        }
    }
    int source;
    cin>>source;
    bellmanFord(arr,n,m,source);
}

