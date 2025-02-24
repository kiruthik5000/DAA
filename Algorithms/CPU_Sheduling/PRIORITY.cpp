#include<bits/stdc++.h>         
using namespace std;
struct process {
    int pro;
    int pri;
    int BT;
    int TAT;
    int WT;
};
bool comp (process a, process b) {
    return a.pri < b.pri;
}
void display(vector<process>& priority, int n) {
 cout << "Process BurstTime TurnAroundTime WaitingTime \n";    double AvgWT = 0.0;
    double AvgTAT = 0.0;
    for(int i=0; i<n; i++) {
        AvgWT += priority[i].WT;
        AvgTAT += priority[i].TAT;
        cout << priority[i].pro << "\t" << priority[i].BT<<"\t"<<priority[i].pri<<"\t"<< priority[i].TAT <<"\t" <<priority[i].WT<<endl;
    }

    cout << endl<<"Average WaitingTime = " <<AvgWT / n<<endl;
    cout << "Average TurnAroundTime = " <<AvgTAT / n;
}
void calcProcess(vector<process>& priority, int n) {

    int timeperiod = 0;
    sort(priority.begin(), priority.end(), comp);
    for(int i=0; i<n; i++) {
        priority[i].WT = timeperiod;
        timeperiod += priority[i].BT;
        priority[i].TAT = timeperiod;
    }
    display(priority, n);
}
int main() {
    int n; cin >> n;

    vector<process> priority(n);

    for(int i=0; i<n; i++) {
        priority[i].pro = i+1;
        cin  >> priority[i].BT >> priority[i].pri;
    }
    calcProcess(priority, n);
}
/*
2       
2
1
1
8
5
4 
4
5
3 
*/
       
       