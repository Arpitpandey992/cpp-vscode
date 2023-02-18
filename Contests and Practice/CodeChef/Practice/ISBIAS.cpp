#include<bits/stdc++.h>
using namespace std;
 
const double PI=acos(-1.0);
#define ll long long
int main()
{
 
	ll i,j,k;
	ll n,t;
	ll x,y;
	ll mult,count;
	cin>>t;
	while(t--){
	cin>>n;
	int a[100000];
	for ( i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for ( i = 0,count=0; i < n; ++i)
	{
		for ( j = i,mult=1; j < n; ++j)
		{
			mult*=a[j];
			x=mult;
			y=(x+2)/4;
			if((4*y)-2!=x)
			{
				count++;
			}
		}
	}
	cout<<count<<"\n";
	}
	return 0;
}