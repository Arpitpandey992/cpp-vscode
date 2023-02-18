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
        ui k, n, i, temp;
        ul sum = 0,w1=0;
        cin >> n >> k;
        if (k > n / 2)
            k = (n - k);
        multiset<int> w;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            sum += temp;
            w.insert(temp);
        }
        auto it = w.begin();
        for (i = 0; i < k;i++)
        {
            w1 += *it;
            it++;
        }
        cout << (sum - 2 * w1) << endl;
    }
}