#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high, bool ORDER) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot && !ORDER) {
            i++;
            swap(arr[i], arr[j]);
        }
        if (arr[j] > pivot && ORDER) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void QUICKSORT(int arr[], int low, int high, bool ORDER) {
    if (low < high) {
        int pi = partition(arr, low, high, ORDER);
        QUICKSORT(arr, low, pi - 1, ORDER);
        QUICKSORT(arr, pi + 1, high, ORDER);
    }
}

int main() {
    cout << "Enter the number of elements in the List : ";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter " << n << " Elements one by one\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool ORDER;
    cout << "Enter Order of sorting (0/1 for ascending/descending)\n";
    cin >> ORDER;
    QUICKSORT(a, 0, n - 1, ORDER);
    cout << "The Sorted array is\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
