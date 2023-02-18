#include <iostream>
using namespace std;
void ToLower(string &s) {
    int n = s.size();
    int del = 'a' - 'A';  //difference between different cases
    for (int i = 0; i < n; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + del;
}
int main() {
    string s;
    cout << "Enter a string :\n";
    getline(cin, s);
    ToLower(s);
    cout << "Converted String from Upper to Lower Case Characters\n"
         << s << endl;
}
