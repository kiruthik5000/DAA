#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to calculate the total seek time for FCFS
int FCFS(const vector<int>& requests, int head) {
    int totalSeek = 0;
    int currentHead = head;
    for (int request : requests) {
        totalSeek += abs(request - currentHead);
        currentHead = request;
    }
    return totalSeek;
}

// Function to calculate the total seek time for SSTF
int SSTF(vector<int> requests, int head) {
    int totalSeek = 0;
    int currentHead = head;
    while (!requests.empty()) {
        auto closest = min_element(requests.begin(), requests.end(),
            [currentHead](int a, int b) { return abs(a - currentHead) < abs(b - currentHead); });
        totalSeek += abs(*closest - currentHead);
        currentHead = *closest;
        requests.erase(closest);
    }
    return totalSeek;
}

// Function to calculate the total seek time for SCAN
int SCAN(vector<int> requests, int head, int diskSize) {
    int totalSeek = 0;
    int currentHead = head;
    requests.push_back(0);  // Add 0 (start of the disk)
    requests.push_back(diskSize - 1); // Add end of the disk
    sort(requests.begin(), requests.end());
    auto pos = find(requests.begin(), requests.end(), head);

    // Move towards the end first
    for (auto it = pos; it != requests.end(); ++it) {
        totalSeek += abs(*it - currentHead);
        currentHead = *it;
    }
    // Move towards the start
    for (auto it = pos - 1; it >= requests.begin(); --it) {
        totalSeek += abs(*it - currentHead);
        currentHead = *it;
    }
    return totalSeek;
}

// Function to calculate the total seek time for C-SCAN
int CSCAN(vector<int> requests, int head, int diskSize) {
    int totalSeek = 0;
    int currentHead = head;
    requests.push_back(0);  // Add 0 (start of the disk)
    requests.push_back(diskSize - 1); // Add end of the disk
    sort(requests.begin(), requests.end());
    auto pos = find(requests.begin(), requests.end(), head);

    // Move towards the end first
    for (auto it = pos; it != requests.end(); ++it) {
        totalSeek += abs(*it - currentHead);
        currentHead = *it;
    }
    // Jump to the start
    totalSeek += abs(diskSize - 1 - 0);
    currentHead = 0;
    // Move towards the head
    for (auto it = requests.begin(); it < pos; ++it) {
        totalSeek += abs(*it - currentHead);
        currentHead = *it;
    }
    return totalSeek;
}

int main() {
    
    vector<int>requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    int diskSize = 200;

    cout << "FCFS Total Seek Time: " << FCFS(requests, head) << endl;
    cout << "SSTF Total Seek Time: " << SSTF(requests, head) << endl;
    cout << "SCAN Total Seek Time: " << SCAN(requests, head, diskSize) << endl;
    cout << "C-SCAN Total Seek Time: " << CSCAN(requests, head, diskSize) << endl;

    return 0;
}
