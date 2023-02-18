#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
        int n;cin>>n;
		unsigned long long f=1;
        for(int i=1;i<=n;i++)
        {
            f=f*i;
        }
        cout<<f<<endl;
	}
}