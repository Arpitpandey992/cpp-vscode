#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <stack>
#include <list>
#include <queue>
#include <sstream>
using namespace std;
#define M 1000000007
#define nl cout << '\n'
#define us unsigned short
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ld long double
#define ul unsigned long
#define endl '\n'
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define pb push_back
ll i, j, temp;
#define fok(i, k, n) for (i = k; i < n; i++)
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n; i >= 0; i--)
#define Sort(v) sort(v.begin(), v.end())
#define fastio ios_base::sync_with_stdio(false);
//cin.tie(NULL);                    \
//cout.tie(NULL); // to get output after all input is done
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
//----------------------------------------------------------------------------------//
//Include lines And Stuff Above

int chrr(char c1, char c2) // c2>=c1
{
    if (c2 - c1 >= 'z' - c2 + c1 - 'a' + 1)
        return 'z' - c2 + c1 - 'a' + 1;
    else
        return c2 - c1;
}

int main()
{
    int n;
    cin >> n;
    int p;
    cin >> p;
    p--;
    string s;
    cin >> s;
    ll ct = 0;
    if (n == 1)
        cout << 0 << endl;
    else
    {
        if (n & 1) //odd
        {
            int half = n / 2;
            s.erase(half, 1);
            n--;
            if (p > n / 2)
                p--;
            else if (p == n / 2)
                ct++;
        }
        int half = n / 2;
        if (p < half)
        {
            p = n - p - 1;
        }
        int first = p, last = p;
        fok(i, half, p)
        {
            if (s[i] != s[n - i - 1])
            {
                first = i;
                break;
            }
        }
        for (i = n - 1; i > p; i--)
        {
            if (s[i] != s[n - i - 1])
            {
                last = i;
                break;
            }
        }
        if (p-first>=last-p)
        {
            ct += (last - p) * 2;
            ct += p - first;
            fok(i, n / 2, n)
            {
                char c1 = s[i], c2 = s[n - i - 1];
                if (c2 == c1)
                    continue;
                else if (c2 > c1)
                {
                    ct += chrr(c1, c2);
                }
                else
                {
                    ct += chrr(c2, c1);
                }
            }
        }
        else
        {
            ct += (last - p);
            ct += (p - first) * 2;
            fok(i, n / 2, n)
            {
                char c1 = s[i], c2 = s[n - i - 1];
                if (c2 == c1)
                    continue;
                else if (c2 > c1)
                {
                    ct += chrr(c1, c2);
                }
                else
                {
                    ct += chrr(c2, c1);
                }
            }
        }

        cout << ct << endl;
    }
}
