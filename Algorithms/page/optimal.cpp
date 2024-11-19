#include <bits/stdc++.h>
using namespace std;

int findPageToReplace(vector<int>&frames, int capacity, int pages[], int currentIndex, int n) {
    int farthest = -1, replaceIndex = -1;

    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = currentIndex + 1; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return (replaceIndex == -1) ? 0 : replaceIndex;
}
void printer(vector<int>& q) {
    for (int i : q) {
        if (i == -1)
            cout << "-\t\t";
        else
            cout << i << "\t\t";
    }
    cout << endl;
}

void optimalPageReplacement(int pages[], int n, int capacity) {
    vector<int> frames(capacity, -1);     
    int faults = 0;

    for (int i = 0; i < n; i++) {
        cout << pages[i] << "\t\t";

        bool found = false;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            faults++;
            int replaceIndex = -1;

            for (int j = 0; j < capacity; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            if (replaceIndex == -1) {
                replaceIndex = findPageToReplace(frames, capacity, pages, i, n);
            }
            frames[replaceIndex] = pages[i];
        }
        printer(frames);
    }
    cout << "Total Page Faults: " << faults << endl;
}

int main() {
    int pages[] = {1,2,3,4,3,2,1,1,4,3};
    int n = 10;
    int capacity = 3;

    cout << "Incoming\tFrame1\t\tFrame2\t\tFrame3\n";
    optimalPageReplacement(pages, n, capacity);

    return 0;
}
