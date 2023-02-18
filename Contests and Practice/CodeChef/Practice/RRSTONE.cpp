#include <vector>
#include <string>
#include <map>
#include<algorithm>   
#include<cmath>
#include<iostream>
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ul unsigned long
#define fori for (i = 0; i < n; i++)
#define forj for (j = 0; j < n; j++)
#define test  ul t; cin >> t; while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
int main()
{
    ui n;
    ll k;
    cin >> n >> k;
    ll a[n];
    ll max = -2000000000;
    ll min = 2000000000;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]>max)
            max = a[i];
        if(a[i]<min)
            min = a[i];
    }
    if(k==0)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    else if (k % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] - min << " ";
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << max-a[i] << " ";
        }
    }
}