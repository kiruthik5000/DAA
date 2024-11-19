#include <bits/stdc++.h>
using namespace std;

int near(vector<int>& requests, int head, vector<bool>& visited, int n) {
    int mindst = INT_MAX;
    int idx = -1;

    for (int i = 0; i <n; i++) {
        if (!visited[i]) { 
            int dst = abs(requests[i] - head);
            if (dst < mindst) {
                mindst = dst;
                idx = i;
            }
        }
    }
    return idx;
}

void sstfDiskScheduling(vector<int>& requests, int head, int n) {
    vector<bool> visited(n, false); 
    int total = 0;

    for (int i = 0; i <n; i++) {
        int idx = near(requests, head, visited, n);
        visited[idx] = true; 
        total += abs(requests[idx] - head);
        head = requests[idx];
    }
    cout << "\nTotal Head Movement: " << total << endl;
}

int main() {
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    int n = 8;
    sstfDiskScheduling(requests, head, n);
}
