#include <iostream>
using namespace std;
void rev(string** a, int n) {
    string temp;
    int l = 0, r = n - 1;
    while (l < r) {
        string* temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
    }
}
int main() {
    int n;
    cout << "Enter The number of Strings in array - ";
    cin >> n;
    cin.ignore();  //for ignoring the Enter Key
    string* a = new string[n];
    cout << "Enter " << n << " Strings (one string in one line)\n";
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]);
    }
    //The pointer array pointing to the elements of the above array
    string** ptr = new string*[n];
    for (int i = 0; i < n; i++)
        ptr[i] = &a[i];
    rev(ptr, n);
    cout << "\nAfter Reversing\n";
    cout << "\nOriginal array Stored as array of strings - a is:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    cout << "\nReversed array pointers stored as array of pointers to strings\n";
    for (int i = 0; i < n; i++) {
        cout << *ptr[i] << endl;
    }
}
