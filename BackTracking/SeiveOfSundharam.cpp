#include <iostream>
using namespace std;

void printPrimes(int n) {
    int nNew = (n - 1) / 2;
    bool arr[nNew + 1];

    for (int i = 1; i <= nNew; i++) {
        for (int j = i; (i + j + 2 * i * j) <= nNew; j++) {
            arr[i + j + 2 * i * j] = true;
        }
    }

    if (nNew >= 2) cout << 2 << ' ';
    for (int i = 1; i <= nNew; i++) {
        if (!arr[i]) cout << 2 * i + 1 << ' ';
    }
}

int main() {
    printPrimes(102);
}