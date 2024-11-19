#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void printer(vector<int>& q) {
    for (int i : q) {
        if (i == -1)
        
            cout << "-\t\t";
        else
            cout << i << "\t\t";
    }
    cout << endl;
}

int main() {
    int n = 10, f = 4, pageFaults = 0;
    vector<int> pages = {7,5,9,4,3,7,9,6,2,1};    
    vector<int> frames(f, -1);     
    vector<int> counter(f, -1);    
    cout << "Incoming\tFrame1\t\tFrame2\t\tFrame3\t\tFrame4\n";

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool found = false;
        for (int j = 0; j < f; j++) {
            if (frames[j] == page) {
                found = true;
                counter[j] = i; 
                break;
            }
        }
        if (!found) {
            int lru = 0;
            for (int j = 1; j < f; j++) {
                if (counter[j] < counter[lru]) {
                    lru = j;
                }
            }
            frames[lru] = page;      
            counter[lru] = i;     
            pageFaults++;
        }
            cout << page << "\t";
            printer(frames);
    }
    cout << "\nTotal Page Faults: " << pageFaults << endl;
    return 0;
}