#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void buildHeap(int a[], int n) {
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
        heapify(a, n, i);
}
void inorder(int a[], int i, int n) {
    if (i >= n) return;
    inorder(a, 2 * i + 1, n);
    cout << a[i] << " ";
    inorder(a, 2 * i + 2, n);
}
void print(int a[], int n) {
    cout << "array after heapification\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Inorder traversal of the heap\n";
    inorder(a, 0, n);
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
    buildHeap(a, n);
    print(a, n);
}