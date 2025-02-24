#include<bits/stdc++.h>
using namespace std;
struct process {
    int pro;
    int BT;
    int TAT;
    int WT;
};

void display(vector<process>& fcfs, int n) {
    double AvgWT = 0.0;
    double AvgTAT = 0.0;

    for(int i=0; i<n; i++) {
        AvgTAT += fcfs[i].TAT;
        AvgWT += fcfs[i].WT;
    }

    cout << endl<<"Average WaitingTime = " <<AvgWT / n<<endl;
    cout << "Average TurnAroundTime = " <<AvgTAT / n;
}

void roundrobin(vector<process>& rr, int qunat, int n) {
    cout << "Process BurstTime TurnAroundTime WaitingTime \n";
    vector<int> remain (n);
    for(int i=0; i<n; i++) {
        remain[i] = rr[i].BT;
    }
    int time = 0;

    while (true) {
        bool done = true;

        for(int i=0; i<n; i++) {
            if(remain[i] > 0) {
                done = false;
                if(remain[i] > qunat) {
                    time += qunat;
                    remain[i] -= qunat;
                }
                else{
                    time += remain[i];
                    rr[i].WT = time - rr[i].BT;
                    rr[i].TAT = time;
                    remain[i] = 0;
                }
            }
        }
        if(done) break;
    }
    for(int i=0; i<n; i++) {
        cout << "p"<<i+1<<"\t"<<rr[i].BT<<"\t"<<rr[i].TAT<<"\t"<<rr[i].WT<<endl;
    }
    display(rr, n);
}
int main() {
    int n = 5;
    vector<process> rr(n);
    for(int i=0; i<n; i++) {
        rr[i].pro = i+1;
        cin >> rr[i].BT;
    }
    roundrobin(rr, 4, n);
}
/*
2         
1        
8        
4       
5
*/
       