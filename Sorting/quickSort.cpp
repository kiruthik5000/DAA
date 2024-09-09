#include <bits/stdc++.h>
using namespace std;

int *quickSort(int *arr, int low, int high)
{

    if (low > high)
        return arr;

    int f = low;
    int l = high;
    int mid = (f + l) / 2;
    int pivot = arr[mid];

    while (f <= l)
    {
        while (arr[f] < pivot)
            f++;
        while (arr[l] > pivot)
            l--;

        if (f <= l)
            swap(arr[f++], arr[l--]);
    }

    quickSort(arr, low, l);
    quickSort(arr, f, high);

    return arr;
}
int main()
{
    int a;
    cin >> a;
    int arr[a];

    for (int i = 0; i < a; cin >> arr[i++]);

    quickSort(arr, 0, a - 1);

    for (int i = 0; i < a; cout << arr[i++] << " ");
}
