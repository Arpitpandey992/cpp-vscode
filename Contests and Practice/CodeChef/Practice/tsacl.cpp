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
bool isPrime2(ull n)
{
	if (n <= 1)
		return false;

	if (n <= 3)
		return true;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ull i = 5; i * i <= n; i = i + 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}

	return true;
}
bool isPrime(ull n)
{
	if (n == 1)
	{
		return false;
	}
	ull i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
		{
			return false;
		}
		i += 1;
	}
	return true;
}

int main()
{
	//test
	{
		ull x=1, y=500000;
		//cin >> x >> y;

		for (ull i = x; i <= y; i++)
		{
			if (isPrime(i))
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}
