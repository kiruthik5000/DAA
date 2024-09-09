#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;        // j = 0 
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];     // arr[1] = arr[0]
            j--;                    // j = -1
        }
        arr[j + 1] = key;           // j = 0  arr[0] = arr[i]
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int N = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, N);

    cout << "Sorted array: ";
    printArray(arr, N);

    return 0;
}