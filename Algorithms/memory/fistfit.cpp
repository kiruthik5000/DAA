#include<bits/stdc++.h>
using namespace std;

void firstfit(vector<int>&blocks, vector<int>& process, int n, int m) {
    cout << "Process\t\tSize\t\tBlock No\tBlockSize\tRemaining\n";
    vector<int>remain(m);
    vector<int>blockno(m, -1);

    for(int i=0; i<m; i++) {
        bool alloc = false;
        for(int j=0; j<n; j++) {
            if(blocks[j] >= process[i]){
                remain[i] = blocks[j] - process[i];
                blockno[i] = j;
                blocks[j] -= process[i];
                alloc = true;
                break;
            }
        }
        if(alloc)
        cout <<i+1<<"\t\t"<<process[i] <<"\t\t"<<blockno[i]+1<<"\t\t"<<remain[i]+process[i]<<"\t\t"<<remain[i]<<endl;
        else
        cout << i+1 <<"\t\t"<<process[i] <<"\t\tnot allocated";
    }
}

int main() {
    int n = 5, m = 4;
    vector<int> blocks(n);
    vector<int> process(m);
    blocks={100, 500, 200, 300, 600};
    process = {212, 417, 112, 426};
    firstfit(blocks, process, n, m);
}