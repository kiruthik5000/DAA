#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    vector<int> arr;
    int pIndexOf(int index)
    {
        return (index - 1) / 2;
    }

public:
    void create(int num)
    {
        int index = arr.size();
        arr.push_back(num);

        while (index > 0 && arr[index] > arr[pIndexOf(index)])
        {
            swap(arr[index], arr[pIndexOf(index)]);
            index = pIndexOf(index);
        }
    }
    void disp()
    {
        for (int i : arr)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    MinHeap o;
    int a;
    cin >> a;
    int num;
    for (int i = 0; i < a; i++)
    {
        cin >> num;
        o.create(num);
    }

    o.disp();
}