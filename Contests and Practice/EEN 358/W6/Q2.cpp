#include <cmath>
#include <iostream>
using namespace std;
int SequentialSearch(int a[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (a[i] == val) {
            return i;
        }
    }
    return -1;
}
int IndexedSequentialSearch(int a[], int n, int val) {
    int m = sqrt(n), m1 = 0;
    int Groupval[m + 5];
    for (int i = 0, j = 0; i < n; i += m, j++) {
        m1++;
        Groupval[j] = a[i];
    }
    int p = 0;
    while (p < m1 && Groupval[p] <= val)
        p++;
    if (p > 0)
        p--;
    for (int i = m * p; i < min(n, m * (p + 1)); i++)
        if (a[i] == val)
            return i;
    return -1;
}
int BinarySearch(int a[], int n, int val) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < val)
            l = mid + 1;
        else
            r = mid;
    }
    if (a[l] == val)
        return l;
    return -1;
}
void searchall(int a[], int n, int val) {
    cout << "Searching for " << val << "...\n";
    int i = SequentialSearch(a, n, val);
    cout << "Sequential Search         : ";
    if (i != -1) {
        cout << "Element Present at Index(s) ";
        while (i < n && a[i] == val) {
            cout << i;
            if (i + 1 < n && a[i + 1] == val)
                cout << ", ";
            else
                cout << endl;
            i++;
        }
    } else
        cout << "Element Not Present\n";

    i = BinarySearch(a, n, val);
    cout << "Binary Search             : ";
    if (i != -1) {
        cout << "Element Present at Index(s) ";
        while (i < n && a[i] == val) {
            cout << i;
            if (i + 1 < n && a[i + 1] == val)
                cout << ", ";
            else
                cout << endl;
            i++;
        }
    } else
        cout << "Element Not Present\n";

    i = IndexedSequentialSearch(a, n, val);
    cout << "Indexed Sequential Search : ";
    if (i != -1) {
        cout << "Element Present at Index(s) ";
        while (i < n && a[i] == val) {
            cout << i;
            if (i + 1 < n && a[i + 1] == val)
                cout << ", ";
            else
                cout << endl;
            i++;
        }
    } else
        cout << "Element Not Present\n";
    cout << endl;
}
int main() {
    int a[] = {1, 2, 3, 3, 4, 5, 6, 6, 6, 7, 9, 12, 12, 15, 21, 23, 23, 26, 27, 37, 41, 42, 43, 48, 102, 106, 195, 302, 356, 357, 909, 1002, 1002};
    int n = sizeof(a) / sizeof(int);
    searchall(a, n, 3);
    searchall(a, n, 7);
    searchall(a, n, 41);
    searchall(a, n, 6);
    searchall(a, n, 67);
    searchall(a, n, 699);
    searchall(a, n, 1);
    searchall(a, n, 1002);
}