#include <bits/stdc++.h>
using namespace std;

void Tower(int n, string from_rod, string to_rod, string aux_rod) {
    if (n == 1) {
        cout << "Move disk 1 from " << from_rod << " to " << to_rod << endl;
        return;
    }
    Tower(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from " << from_rod << " to " << to_rod << endl;
    Tower(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    cout << "Enter the Number of Disks\n";
    int n;
    string a = "Rod 1", b = "Rod 2", c = "Rod 3";
    cin >> n;
    Tower(n, a, b, c);
}
