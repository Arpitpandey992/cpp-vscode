#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#define nl cout << '\n'
#define us unsigned short
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ul unsigned long
#define endl '\n'
ll i, j, temp;
#define fok(i, k, n) for (i = k; i < n; i++)
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n; i >= 0; i--)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    //cin.tie(NULL);                    \
    //cout.tie(NULL); // to get output after all input is done
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
string knght(string s, int n)
{
}
int main()
{
    fastio;
    string s;
    int t;
    cin >> t;
    getline(cin, s);
    while (t--)
    {

        getline(cin, s);
        int n = s.size();
        if (n > 5 || s[2] != '-')
            cout << "Error";
        else
        {
            if (s[0] >= 'a' && s[0] <= 'h' && s[3] >= 'a' && s[3] <= 'h' && s[1] >= '1' && s[1] <= '8' && s[4] >= '1' && s[4] <= '8')
            {
                if ((s[0] == s[3] && s[1] == s[4]))
                    cout << "NO";
                else
                {
                    int dx, dy;
                    dx = abs(s[3] - s[0]);
                    dy = abs(s[4] - s[1]);
                    //cout << diffx << " " << diffy;
                    if (((dx == 2) && (dy == 1)) || ((dx == 1) && (dy == 2)))
                        cout << "YES";
                    else
                        cout << "NO";
                }
            }
            else
            {
                cout << "Error";
            }
        }
        //cout << s[2] << " ";
        cout << endl;
    }
}