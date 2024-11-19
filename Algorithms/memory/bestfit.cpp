#include <bits/stdc++.h>
using namespace std;

void bestfit(vector<int>& blocks, vector<int>& process, int n, int m) {
    cout << "Process\tSize\tBlock No\tBlockSize\tRemaining\n";
    vector<int> remain(n, 0);
    vector<int> blockno(m, -1);  
    for (int i = 0; i < m; i++) { 
        int idx = -1; 
        for (int j = 0; j < n; j++) { 
            if (blocks[j] >= process[i]) { 
                if (idx == -1 || blocks[j] <= blocks[idx]) {
                    idx = j; 
                }
            }
        }
        
        if(idx != -1){
            remain[idx] = blocks[idx] - process[i];
            blockno[i] = idx;
            cout <<i+1<<"\t\t"<<process[i] <<"\t\t"<<blockno[i]+1<<"\t\t"<<blocks[idx]<<"\t\t"<<remain[idx]<<endl;
            blocks[idx] -= process[i];
        }
        else{
            cout << i+1 <<"\t\t"<<process[i] <<"\t\tnot allocated";
        }
    }
}

int main() {
    int n = 5, m = 4; 
    vector<int> blocks = {100, 500, 200, 300, 600}; 
    vector<int> process = {212, 417, 112, 426};
    
    bestfit(blocks, process, n, m);

    return 0;
}
