#include <iostream>
using namespace std;
void CaseSwap(string &s) {
    int n = s.size();
    int del1 = 'A' - 'a', del2 = 'a' - 'A';  //difference between different cases
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + del2;
        else if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] + del1;
    }
}
int main() {
    string s;
    cout << "Enter a string :\n";
    getline(cin, s);
    CaseSwap(s);
    cout << "Converted String from Lower to Upper and Upper to Lower Case Characters\n"
         << s << endl;
}
