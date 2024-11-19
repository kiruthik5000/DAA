#include<bits/stdc++.h>         
using namespace std;
struct process {
    int pro;
    int BT; 
    int TAT;
    int WT;
};
bool comp (process a, process b) {
    return a.BT < b.BT;
}
void display(vector<process>& sjf, int n) {
    cout << "Process \t BurstTime \t TurnAroundTime \t WaitingTime \n";
    double AvgWT = 0.0;
    double AvgTAT = 0.0;
    for(int i=0; i<n; i++) {
        AvgWT += sjf[i].WT;
        AvgTAT += sjf[i].TAT;
        cout << sjf[i].pro << "\t" << sjf[i].BT<<"\t" << sjf[i].TAT <<"\t" <<sjf[i].WT<<endl;
    }

    cout << endl<<"Average WaitingTime = " <<AvgWT / n<<endl;
    cout << "Average TurnAroundTime = " <<AvgTAT / n;
}
void calcProcess(vector<process>& sjf, int n) {

    int timeperiod = 0;

    sort(sjf.begin(), sjf.end(), comp);

    for(int i=0; i<n; i++) {
        sjf[i].WT = timeperiod;
        timeperiod += sjf[i].BT;
        sjf[i].TAT = timeperiod;
    }
    display(sjf, n);
}
int main() {
    int n; cin >> n;

    vector<process> sjf(n);

    for(int i=0; i<n; i++) {
        sjf[i].pro = i+1;
        cin  >> sjf[i].BT;
    }
    calcProcess(sjf, n);
}
/*
2         
1        
8        
4       
5
*/