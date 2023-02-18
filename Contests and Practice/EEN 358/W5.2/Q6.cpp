#include <iostream>
using namespace std;

void Maxheapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        Maxheapify(a, n, largest);
    }
}
void Minheapify(int a[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    if (l < n && a[l] < a[smallest])
        smallest = l;

    if (r < n && a[r] < a[smallest])
        smallest = r;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        Minheapify(a, n, smallest);
    }
}
int delete_root(int* a, int& n, bool SORT) {
    int temp = a[0];
    swap(a[0], a[n - 1]);
    n--;
    if (SORT == 0)
        Minheapify(a, n, 0);
    else
        Maxheapify(a, n, 0);
    return temp;
}
void HeapSort(int a[], int n, bool SORT) {
    for (int i = n - 1; i >= 0; i--) {
        if (SORT == 0)
            Minheapify(a, n, i);
        else
            Maxheapify(a, n, i);
    }
    while (n)
        delete_root(a, n, SORT);
}

int main() {
    int n;
    cout << "Enter Number of elements : ";
    cin >> n;
    cout << "Enter " << n << " Elements\n";
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter 1/0 for ascending/descending order sort respectively : ";
    int flag;
    cin >> flag;
    HeapSort(a, n, (flag == 1 ? true : false));
    cout << "After Sorting, Array is \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}