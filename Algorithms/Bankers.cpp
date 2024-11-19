#include<bits/stdc++.h>
using namespace std;
int p = 5; 
int r = 3; 
void findDead(vector<vector<int>> alloc, vector<vector<int>> need, vector<int> avail) {
    vector<bool> finish(p, false);
    vector<int> safe;
    
    bool done;
    while (true) {
        done = true;
        for (int i = 0; i < p; i++) {
            if (!finish[i]) {
                bool canfinish = true;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j])
                        canfinish = false;
                }
                if (canfinish) {
                    for (int j = 0; j < r; j++){
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = true;
                    safe.push_back(i);
                    done = false;
                }
            }
        }
        if (done) break;
    }
    for (int i = 0; i < p; i++) {
        if (!finish[i]) {
            cout << "Deadlock detected in Process " << i << endl;
            return ;
        }
    }
    cout << "No deadlock detected" << endl;
    for(int i=0; i<p; i++){
        if(i< p -1)
        cout << "p"<<i<<" -> ";
        else
        cout <<"p"<<i;
    }
}
int main() {
    vector<vector<int>> allocated(p, vector<int>(r)); 
    vector<vector<int>> need(p, vector<int>(r));      
    vector<int> available(r);                         
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            cin >> allocated[i][j];
        }
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            cin >> need[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        cin >> available[i];
    }
    findDead(allocated, need, available);
    return 0;
}
/*
0 1 0
2 0 0 
3 0 2
2 1 2
0 0 2

7 4 3
1 2 2 
6 0 0 
0 1 0
4 3 1
3 3 2
// */