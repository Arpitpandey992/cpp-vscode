#include <iostream>
using namespace std;
void ToUpper(string &s) {
    int n = s.size();
    int del = 'A' - 'a';  //difference between different cases
    for (int i = 0; i < n; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] + del;
}
int main() {
    string s;
    cout << "Enter a string :\n";
    getline(cin, s);
    ToUpper(s);
    cout << "Converted String from lower to Upper Case Characters\n"
         << s << endl;
}
