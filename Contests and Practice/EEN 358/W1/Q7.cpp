#include <iostream>
using namespace std;

void reverse(string &s) {
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r) {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

int main() {
    cout << "Input String to reverse:\n";
    string s;
    getline(cin, s);
    reverse(s);
    cout << "String after Reversal is :\n"
         << s << endl;
}
