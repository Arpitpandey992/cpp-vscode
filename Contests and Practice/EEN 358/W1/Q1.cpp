#include <iostream>
using namespace std;
void insert(int *a, int n, int *x) {
    int *p = a;
    int temp;
    while (*p <= *x)  //Finding the position
        p++;
    //if the element x is largest among all in the list,
    //insert it at the end
    if (p == (a + n)) {
        *p = *x;
        return;
    }
    //insert the element at this position and
    //right shift the rest of the elements
    while (p <= a + n) {
        temp = *p;
        *p = *x;
        p++;
        *x = temp;
    }
}

int main() {
    int n;
    cout << "How many Elements in the array? - ";
    cin >> n;
    int *a = new int[n];
    cout << "Enter " << n << " Sorted Integers:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int *x = new int;
    cout << "Enter the element you wish to insert in the array\n";
    cin >> *x;
    insert(a, n, x);
    cout << "Array after insertion is: " << endl;
    for (int i = 0; i < n + 1; i++)
        cout << a[i] << " ";
}
