#include <iostream>
using namespace std;

void rot(int *a, int k, int n) {
    int *temp = new int[k];
    for (int i = 0; i < k; i++)
        temp[i] = a[i];
    int i = 0, j = k;
    while (j < n)
        a[i++] = a[j++];
    i = n - k, j = 0;
    while (j < k)
        a[i++] = temp[j++];
}

int main() {
    int n;
    cout << "Enter The number of elements in array - ";
    cin >> n;
    int *a = new int[n];
    cout << "Enter " << n << " Elements One by One\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    int k;
    cout << "Rotate Array Left By how many numbers? - ";
    cin >> k;
    k %= n;  //only remainder matters.
    cout << "Original array is\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    rot(a, k, n);
    cout << "Array after Rotation \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
