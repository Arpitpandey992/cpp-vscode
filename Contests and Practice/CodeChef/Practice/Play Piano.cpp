#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin>>s;
		int len = s.size();
		int flag=0;
		for(int i=0;i<(len);i+=2)
		{
			if(s[i]=='A')
			{
				if(s[i+1]=='B')
					continue;
				flag=1;
				break;
			}
			if(s[i]=='B')
			{
				if(s[i+1]=='A')
					continue;
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"YES\n";
		else
		{
			cout<<"NO\n";
		}
		
	}
}