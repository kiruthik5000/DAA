#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int>& differ) {
    int cur = 0;
    int tot = INT_MIN;
    for(int diff : differ) {
        cur = max(diff, cur + diff);
        tot = max(cur, tot);
    }
    return tot;
}
int main() {
    int n;
    cin >> n;
    if (n < 1) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<int> differences(n);
    for (int i = 0; i < n; i++) {
        cin >> differences[i];
        if (differences[i] < -10000 || differences[i] > 10000) {
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    int maxProfit = maxSubarraySum(differences);
    cout << maxProfit << endl;

    return 0;
}
