#include <vector>
#include <string>
#include <map>
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
ull fib(ull n)
{
	ull f[n];
	f[0] = 0;
	f[1] = 1;
	for (ull i = 2; i < n;i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= 10;
	}
	return f[n-1];
}
int main()
{
	ui t;
	cin >> t;
	while (t--)
	{
		ull n, i, temp;
		cin >> n;
		if (n == 1)
		{
			temp = 1;
		}
		else
		{
			for (i = 0; i <= n; i++)
			{
				temp = pow(2, i);
				if (temp > n)
				{
					temp = pow(2, i - 1);
					break;
				}
			}
		}
		cout << fib(temp)<<endl;
	}
}