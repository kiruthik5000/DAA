
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cin >> n;
    if (n <= 0 || n > 10) {
        cout << "Invalid input";
        return 0;
    }

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].profit >> jobs[i].deadline;
        if (jobs[i].deadline <= 0 || jobs[i].deadline > 1000 || jobs[i].profit <= 0 || jobs[i].profit > 1000) {
            cout << "Invalid input";
            return 0;
        }
    }

    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    vector<int> slot(maxDeadline + 1, -1);
    int countJobs = 0, maxProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline); j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                countJobs++;
                maxProfit += jobs[i].profit;
            }
        }
    }

    cout << maxProfit;
}
