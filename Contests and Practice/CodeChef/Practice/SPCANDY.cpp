#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#define us unsigned short
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ul unsigned long
#define fori for (i = 0; i < n; i++)
#define forj for (j = 0; j < n; j++)
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
int main()
{
    test
    {
        ull n, k;
        cin >> n >> k;
        if (n == 0)
        {
            cout << "0 0";
        }
        else if (k == 0)
            cout << "0 " << n;
        else
        {
            cout << n / k << " " << n % k;
        }
        cout << endl;
    }
}