#include <bits/stdc++.h>
using namespace std;
bool finder(vector<int>& q, int val) {
    for (int i : q) {
        if (i == val) return true;
    }
    return false;
}
void printer(vector<int>& frames) {
    for (int i : frames) {
        if (i == -1)
            cout << "-\t\t";
        else
            cout << i << "\t\t";
    }
    cout << endl;
}

void fifoPageReplacement(int pages[], int n, int capacity) {
    cout << "Incoming\tFrame1\t\tFrame2\t\tFrame3\n";
    vector<int> frames(capacity, -1); 
    int faults = 0;
    int index = 0; 
    for (int i = 0; i < n; i++) {
        cout << pages[i] << "\t\t";
        if (!finder(frames, pages[i])) {
            faults++;
            frames[index] = pages[i];
            index = (index + 1) % capacity; 
        }
        printer(frames);
    }

    cout << "\nTotal Page Faults: " << faults << endl;
}

int main() {
    int n = 5, capacity = 3;
    int pages[] = {4, 1, 2, 4, 5};

    fifoPageReplacement(pages, n, capacity);

    return 0;
}
