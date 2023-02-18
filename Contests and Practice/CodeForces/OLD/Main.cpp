#include <bits/stdc++.h>
using namespace std;

unsigned long pairs(unsigned long n)
{
    unsigned long i, j, ct = 0;
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
            ct++;
    return ct;
}

int main()
{
    unsigned long n, m;
    cin >> n >> m;
    cout << pairs(1);
    for (;;)
    {
        for (;;)
        {

        }
    }
}