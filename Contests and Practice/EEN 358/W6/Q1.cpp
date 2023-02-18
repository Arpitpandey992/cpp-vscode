#include <bits/stdc++.h>
using namespace std;

long double memory;

void InsertionSort(int *a, int &n) {
    memory += 2;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
            else
                break;
        }
    }
}

void SelectionSort(int *a, int &n) {
    int i, j, min_idx;
    memory += 5;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;
        swap(a[min_idx], a[i]);
    }
}

void BubbleSort(int *a, int &n) {
    memory += 2;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j + 1 < n - i; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}
//Quick Sort start
int part(int *a, int l, int r) {
    memory += 5;
    int piv = a[l];
    int k = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < piv) {
            swap(a[i], a[++k]);
        }
    }
    swap(a[k], a[l]);
    return k;
}
void qsort(int *a, int l, int r) {
    memory += 3;
    if (l > r) return;
    int par = part(a, l, r);
    qsort(a, l, par - 1);
    qsort(a, par + 1, r);
}
void QuickSort(int *a, int n) {
    qsort(a, 0, n - 1);
}
//QuickSort End
//MergeSort Starts
void msort(int *a, int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    memory++;
    msort(a, l, mid);
    msort(a, mid + 1, r);
    int siz = r - l + 1;
    memory++;
    int *b = new int[siz];
    memory += siz;
    int i = 0, j = l, k = mid + 1;
    memory += 3;
    while (i < siz) {
        if (j <= mid && k <= r) {
            if (a[j] < a[k])
                b[i++] = a[j++];
            else
                b[i++] = a[k++];
        } else if (j <= mid)
            b[i++] = a[j++];
        else
            b[i++] = a[k++];
    }
    for (j = l, i = 0; j <= r; j++, i++) {
        a[j] = b[i];
    }
}
void MergeSort(int *a, int n) {
    msort(a, 0, n - 1);
}
//MergeSort Ends
//HeapSort Starts
void Maxheapify(int *a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        Maxheapify(a, n, largest);
    }
}
int delete_root(int *a, int &n) {
    memory++;
    int temp = a[0];
    swap(a[0], a[n - 1]);
    n--;
    Maxheapify(a, n, 0);
    return temp;
}
void HeapSort(int *a, int n) {
    memory += 2;
    for (int i = n - 1; i >= 0; i--) {
        Maxheapify(a, n, i);
    }
    while (n)
        delete_root(a, n);
}
//HeapSort Ends

void print(int *a, int &n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void eq(int *a, int *b, int n) {
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

int main() {
    srand(time(0));
    cout << "Testing whether The algorithms are working as intended for a small data:\n\n";
    int n = 20;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++) {
        int x = rand() % 100;
        a[i] = x;
        b[i] = x;
    }

    cout << "Original Array :       ";
    print(a, n);
    cout << "After Insertion sort : ";
    InsertionSort(b, n);
    print(b, n);
    eq(a, b, n);
    cout << "After Selection sort : ";
    SelectionSort(b, n);
    print(b, n);
    eq(a, b, n);
    cout << "After Bubble sort :    ";
    BubbleSort(b, n);
    print(b, n);
    eq(a, b, n);
    cout << "After Quick sort :     ";
    QuickSort(b, n);
    print(b, n);
    eq(a, b, n);
    cout << "After Merge sort :     ";
    MergeSort(b, n);
    print(b, n);
    eq(a, b, n);
    cout << "After Heap sort :      ";
    HeapSort(b, n);
    print(b, n);
    eq(a, b, n);

    cout << "\n\nTesting for large data (100000 Elements)\n";
    n = 100000;
    a = new int[n];
    b = new int[n];
    for (int i = 0; i < n; i++) {
        int x = rand() % 10000;
        a[i] = x;
        b[i] = x;
    }

    clock_t start, end;
    double time_taken;
    memory = 0;
    start = clock();
    cout << "\nInsertion Sort" << endl;
    InsertionSort(b, n);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time Taken :  ";
    cout << fixed << setprecision(6) << time_taken << " Seconds" << endl;
    memory = (memory * 4);
    cout << "Memory Used : " << memory << " Bytes" << endl;
    eq(a, b, n);

    memory = 0;
    start = clock();
    cout << "\nSelection Sort" << endl;
    SelectionSort(b, n);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time Taken :  ";
    cout << fixed << setprecision(6) << time_taken << " Seconds" << endl;
    memory = (memory * 4);
    cout << "Memory Used : " << memory << " Bytes" << endl;
    eq(a, b, n);

    memory = 0;
    start = clock();
    cout << "\nBubble Sort" << endl;
    BubbleSort(b, n);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time Taken :  ";
    cout << fixed << setprecision(6) << time_taken << " Seconds" << endl;
    memory = (memory * 4);
    cout << "Memory Used : " << memory << " Bytes" << endl;
    eq(a, b, n);

    memory = 0;
    start = clock();
    cout << "\nQuick Sort" << endl;
    QuickSort(b, n);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time Taken :  ";
    cout << fixed << setprecision(6) << time_taken << " Seconds" << endl;
    memory = (memory * 4);
    cout << "Memory Used : " << memory << " Bytes" << endl;
    eq(a, b, n);

    memory = 0;
    start = clock();
    cout << "\nMerge Sort" << endl;
    MergeSort(b, n);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time Taken :  ";
    cout << fixed << setprecision(6) << time_taken << " Seconds" << endl;
    memory = (memory * 4);
    cout << "Memory Used : " << memory << " Bytes" << endl;
    eq(a, b, n);

    memory = 0;
    start = clock();
    cout << "\nHeap Sort" << endl;
    HeapSort(b, n);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time Taken :  ";
    cout << fixed << setprecision(6) << time_taken << " Seconds" << endl;
    memory = (memory * 4);
    cout << "Memory Used : " << memory << " Bytes" << endl;
}