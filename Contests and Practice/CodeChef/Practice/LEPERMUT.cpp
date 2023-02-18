#include <vector>
#include <string>
#include <map>
#include<algorithm>   
#include<cmath>
#include<iostream>
#include<cstring>
#define us unsigned short
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
    test
    {
        us k;
        cin >> k;
        char c[101],ch='a';
        us i;
        for (i = 0; i <= k; i++)
        {
            c[i] = ch;
            if(ch=='z')
            {
                ch = 'ab';
                i++;
            }
                
            else
            {
                ch++;
            }
        }
        for (short j = k; j >= 0;j--)
        {
            cout << c[j];
        }
        cout << endl;
    }
}