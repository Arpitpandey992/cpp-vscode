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
int S(ll n)
{
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n /= 10;
        
    }
    return sum;
}
int main()
{
    fastio;
    ll n,lb;
    cin >> n;
    if(n-97<=0)
        lb = 0;
    else
        lb = (n - 97);
    for (i = lb, j = 0; i < n;i++)
    {
        int s = S(i);
        if((i+s+S(s))==n)
        {
            j++;
        }
    }
    cout << j;
}