#include <iostream>
using namespace std;

int main()
{
	int t, i;
	int a,b,c,d;
	cin >> t;
	while (t--)
	{
	    long long count=0;
		cin>>a>>b>>c>>d;
		for(i=a;i<=b;i++)
		{
			if(i<c)
			{
				count+=(d-c+1);
			}
			else if(i>=c&&i<d)
			{
				count+=(d-i);
			}
			
		
		}
		cout<<count<<endl;
	}
}