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
    int n, q;
    cin >> n >> q;
    int s[n]={0};
    int chk, rl, ru;
    fo(i,q)
    {
        cin >> chk >> rl >> ru;
        if(chk)
        {
            int temp=0;
            for (j = rl; j <= ru;j++)
            {
                if(s[j]%3==0)
                {
                    temp++;
                }
            }
            cout << temp << endl;
        }
        else
        {
            for (j = rl; j <= ru;j++)
            {
                s[j]++;
            }
        }
        
    }

}