#include <iostream>
using namespace std;

void TestRealloc() {
    int* a = (int*)malloc(sizeof(int));
    int i = 0;
    cout << "Testing realloc(), insert an integer that will be inserted in a dynamically resizable array\n";
    do {
        cout << "Enter a number\n";
        cin >> a[i++];
        cout << "Want to Enter More? enter 1 otherwise 0\n";
        int k;
        cin >> k;
        if (k != 1) break;
        int* before = a;
        a = (int*)realloc(a, (i + 1) * sizeof(int));
        int* after = a;
        //Checking if the memory address of array was changed because of reallocation of memory.
        if (before != after)
            cout << "address changed from " << before << " To " << after << endl;
    } while (1);
    cout << "DATA Entered is:\n";
    for (int j = 0; j < i; j++) {
        cout << a[j] << " ";
    }
}
int main() {
    int *a, *b, n;
    cout << "Enter the number of integers to allocate memory for: ";
    cin >> n;
    //malloc() allocates memory with garbage value.
    cout << "Allocating Memory for " << n << " Integers using malloc():\n";
    a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    //calloc() allocates memory with 0 value for integers.
    cout << "\nAllocating Memory for " << n << " Integers using Calloc():\n";
    b = (int*)calloc(n, n * sizeof(int));
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << "\n\n";
    TestRealloc();
}