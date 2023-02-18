#include <iostream>
using namespace std;
#include<cmath>

int gcd(int a,int b){	
	while(a!=b){
		if(a==1 || b==1)	return 1;
		if(a==0)	return b;
		if(b==0)	return a;
		(a>b)?(a=a%b):(b=b%a);
	}
	return a;
}
 
long long hcf(int a,int b){
	return (a/(gcd(a,b)))*(long long)b;}

int main()
{
	int t, n, i, j;
	long long tim;
	cin >> t;
	while (t--)
	{
		cin >> n;
		long long a[n];
		if (n >= 2 && n <= 500)
		{
			for (i = 0; i < n; i++)
			{
				cin >> a[i];
				if (a[i] < 1||a[i]>pow(10,9))
					exit(0);
			}
			tim = pow(10,18);
			for (i = 0; i < n; i++)
			{
				for (j = i; j < n; j++)
				{
					if (i != j)
					{
						if (hcf(a[i], a[j]) < tim)
						{
							tim = hcf(a[i], a[j]);
						}
					}
				}
			}
			cout << tim << endl;
		}
	}
}