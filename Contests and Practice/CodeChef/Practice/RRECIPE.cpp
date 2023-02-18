#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#define nl cout << '\n'
#define mod 1000000007
#define us unsigned short
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ul unsigned long
#define endl '\n'
ll i, j, temp;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n - 1; i >= 0; i--)
#define fok(i, k, n) for (i = k; i < n; i++)
#define forj for (j = 0; j < n; j++)
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
int main()
{
    ios_base::sync_with_stdio(false); // just speeds up execution time
    //cin.tie(NULL);                    // to get output after all input is done
    test
    {
        string s;
        ll k = 0;
        int mod2 = 10000009;
        cin >> s;
        ll ans = 1;
        cin.ignore();
        ull n = s.size();
        ui re[(n / 2) + 1];
        if (n == 1 && s[0] == '?')
        {
            cout << "26\n";
            goto start;
        }
        else if (n == 1 && s[0] != '?')
        {
            cout << "1\n";
            goto start;
        }
        else
        {
            for (i = 0, j = n - 1; i < n / 2; i++, j--)
            {
                if ((s[i] != s[j]) && (s[i] != '?' && s[j] != '?'))
                {
                    cout << "0\n";
                    goto start;
                }
                if (s[i] == '?' && s[j] == '?')
                {
                    re[k++] = 26;
                }
            }
            if(n%2!=0&&s[n/2]=='?')
            {
                re[k++] = 26;
            }
            for (i = 0; i < k; i++)
            {
                ans = ans * (re[i] % mod2);
                ans %= mod2;
            }
            cout << ans << endl;
        }
    start:
        int dummy;
    }
}
