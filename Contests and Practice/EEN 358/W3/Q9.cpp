#include <bits/stdc++.h>
using namespace std;

void Tower_NR(int n) {
    for (int x = 1; x < (1 << n); x++)
        cout << "Move from Rod " << 1 + ((x & (x - 1)) % 3) << " to Rod " << 1 + ((((x | (x - 1)) + 1) % 3)) << "\n";
}
int main() {
    cout << "Enter the Number of Disks : ";
    int m;
    cin >> m;
    Tower_NR(m);
}
