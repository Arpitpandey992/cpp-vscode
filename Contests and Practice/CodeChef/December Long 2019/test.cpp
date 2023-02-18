#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ul unsigned long
#define fori for (i = 0; i < n; i++)
#define forj for (j = 0; j < n; j++)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
int c2i(char c)
{
    return (int(c) - '0');
}
char i2c(int n)
{
    return (n + '0');
}


int main()
{
    int* multipli(int a[], int b[], int n, int m);
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int x[n], y[m];
    for (int i = 0; i < n; i++)
        x[i] = int(a[i] - '0');
    for (int i = 0; i < m; i++)
        y[i] = int(b[i] - '0');
        multipli((n>m ? x : y), (n<m ? x : y), (n>m ? n : m), (n<m ? n : m));
}
int* multipli(int a[], int b[], int n, int m)
{
    int mul[n+2][m]={0};
    for (int i = m-1; i >=0;i--)
    {
        int carry = 0;
        for (int j = n-1; j >=0; j--)
        {
            int M = (((b[i]) * (a[j]))+carry);
            carry = M % 10;
            if(j==0&&M>9)
            {
                mul[m-1-i][j+1] = ((M / 10));
                mul[m - 1 - i][j] = M % 10;
            }
            else
            {
                mul[m-1-i][j+1] = ((M / 10));
            }
            
        }
        for (int i = 0; i <= n;i++)
            cout << mul[0][i];
        cout << endl;
    }
}
