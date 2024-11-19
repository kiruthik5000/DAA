#include<bits/stdc++.h>    
using namespace std;
struct process {
    int pro;
    int BT;
    int TAT;
    int WT;
};
void display(vector<process>& fcfs, int n) {
    cout << "Process BurstTime TurnAroundTime WaitingTime \n";
    double AvgWT = 0.0;
    double AvgTAT = 0.0;

    for(int i=0; i<n; i++) {
        AvgTAT += fcfs[i].TAT;
        AvgWT += fcfs[i].WT;
        
        cout << fcfs[i].pro<<"\t"<<fcfs[i].BT<<"\t"<<fcfs[i].TAT<<"\t"<<fcfs[i].WT <<endl;
    }

    cout << endl<<"Average WaitingTime = " <<AvgWT / n<<endl;
    cout << "Average TurnAroundTime = " <<AvgTAT / n;
}
void calcProcess(vector<process>& fcfs, int n) {

    int timeperiod = 0;
    for(int i=0; i<n; i++) {
        fcfs[i].WT = timeperiod;
        timeperiod += fcfs[i].BT;
        fcfs[i].TAT = timeperiod;
    }
    display(fcfs, n);
}
int main() {
    int n; cin >> n;

    vector<process> fcfs(n);

    for(int i=0; i<n; i++) {
        fcfs[i].pro = i+1;
        cin  >> fcfs[i].BT;
    }

    calcProcess(fcfs, n);
}
/*
2         
1        
8        
4       
5
*/
       