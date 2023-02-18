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

int main()
{
    fastio;
    test
    {
        ll n, a, b, ca = 0, cb = 0,cc=0, tmp;
        bool chance = 1; //1-bob, 0 - alice
        cin >> n >> b >> a;
        fo(i, n)
        {
            cin >> tmp;
            if(tmp%a==0&&tmp%b==0)
                cc++;
            else if (tmp % a == 0)
                ca++;
            else if (tmp % b == 0)
                cb++;
        }
        if(cc!=0)
            chance = 0;
        while (1)
        {
            if (chance)
            {
                cb--;
                chance = 0;
            }
            else
            {
                ca--;
                chance = 1;
            }
            if (cb == -1)
            {
                cout << "ALICE\n";
                break;
            }
            if (ca == -1)
            {
                cout << "BOB\n";
                break;
            }
        }
    }
}