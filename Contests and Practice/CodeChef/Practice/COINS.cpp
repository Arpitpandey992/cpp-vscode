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

ull coin(ull n)
{

	if(n<=6)
		return n;
	ull temp = (coin(n / 2) + coin(n / 3) + coin(n / 4));
	if(temp>n)
	{
		return temp;
	}	
	else
	{
		return n;
	}
	
}
int main()
{
	ull n;
	while(cin >> n)
		cout << coin(n) << endl;	
}