#include <bits/stdc++.h>
using namespace std;

int getNextVertex(vector<int>& dist, vector<bool>& inMST) {
    int minVal = INT_MAX;
    int vertex = -1;

    for (int i = 0; i < dist.size(); i++) {
        if (!inMST[i] && dist[i] < minVal) {
            vertex = i;
            minVal = dist[i];
        }
    }
    return vertex;
}

int getShortestDistance(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> inMST(n, false);
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    for (int i = 0; i < n; i++) {
        int vertex = getNextVertex(dist, inMST);
        inMST[vertex] = true;

        for (int j = 0; j < adj[vertex].size(); j++) {
            if (!inMST[j] && adj[vertex][j] != -1) {
                dist[j] = min(dist[j], adj[vertex][j]);
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += dist[i];
    }
    return sum;
}

int main() {
    int V, e;
    cin >> V >> e;
    vector<vector<int>> adj(V, vector<int>(V, -1));
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    cout << getShortestDistance(adj) << endl;
}