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

int main()
{
	test
	{
		string s;
		cin >> s;
		cin.ignore();
		ull n = s.size();
		//cout << n << endl;

		if (n % 2 == 0)
		{
			for (ull i = (n / 2) - 1, j = (n / 2); j < n; i--, j++)
			{
				if (s[j] > s[i])
				{
					if(s[(n / 2) - 1]=='9')
					{
						for (ull k = 0; k < i;k++)
						{
							cout << s[k];
						}
						cout << char(s[i] + 1);
						for (ull k = i + 1; k < n / 2;k++)
						{
							cout << "0";
						}
						for (ull k = i + 1; k < n / 2;k++)
						{
							cout << "0";
						}
						cout << char(s[i] + 1);
						for (ll k = i-1; k >=0;k--)
						{
							cout << s[k];
						}
						cout << endl;
						break;
					}
					else
					{
						for (ull k = 0; k < (n/2)-1;k++)
						{
							cout << s[k];
							
						}
						cout << char(s[(n / 2) - 1] + 1);
						cout << char(s[(n / 2) - 1] + 1);
						for (ll k = (n/2)-2; k >=0;k--)
						{
							cout << s[k];
						}
						cout << endl;
						break;
					}
					
				}
				else
				{
					{
						for (ull k = 0; k < (n/2)-1;k++)
						{
							cout << s[k];
							
						}
						cout << char(s[(n / 2) - 1]);
						cout << char(s[(n / 2) - 1]);
						for (ll k = (n/2)-2; k >=0;k--)
						{
							cout << s[k];
						}
						cout << endl;
						break;
					}
				}
			}		
		}
		else
		{
			/* code */
		}
		
	}
}