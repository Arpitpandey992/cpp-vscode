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

        ll l, r, g;
        cin >> l >> r >> g;
        if (l <= g)
            cout << (r / g) << endl;
        else if(l%g==0)
        {
            if(l!=g)
                cout<<(r / g - l / g) << endl;
            else
                cout<<(r / g - l / g)+1 << endl;
            
        }
        else if( (r / g - l / g)==1&&(r / g - l / g)!=g)
        {
            cout << 0 << endl;
        }
        else
        {
            cout<<(r / g - l / g) << endl;
        }
    }
}