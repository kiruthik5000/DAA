#include <bits/stdc++.h>
using namespace std;

void calculate(int plate, char sor, char des, char aux)
{
    if (plate == 1)
    {
        cout << "plate " << plate << " move from " << sor << " to " << des << endl;
        return;
    }
    calculate(plate - 1, sor, aux, des);
    cout << "plate " << plate << " move from " << sor << " to " << des << endl;
    calculate(plate - 1, aux, des, sor);
}
int main()
{
    int paltes;
    cin >> paltes;
    int cnt = 0;
    calculate(paltes, 'S', 'D', 'A');
    cout << cnt;
}
