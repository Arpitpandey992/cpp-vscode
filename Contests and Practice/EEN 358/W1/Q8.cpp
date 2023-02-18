#include <iostream>
using namespace std;
bool isPalin(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r)
        if (s[l++] != s[r--])
            return false;
    return true;
}
void chk(string s) {
    if (isPalin(s))
        cout << s << " is a palindrome" << endl;
    else
        cout << s << " is not a palindrome" << endl;
}
int main() {
    chk("abcdcba");
    chk("abcdccb");
    chk("1?##?1");
}
