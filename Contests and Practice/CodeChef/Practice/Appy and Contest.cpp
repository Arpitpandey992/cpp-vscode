#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		unsigned long long int k,n,count=0,i;
        unsigned long int a,b;
        cin>>n>>a>>b>>k;
        for(i=1;i<=n&&count<=k;i++)
        {
            if(i%a==0)
            {
                if(i%b!=0)
                    count++;
            }
                
            else if(i%b==0)
            {
                if(i%a!=0)
                    count++;
            }
                
                cout<<i<<" "<<count<<endl;
        }
        if(count>=k)
            cout<<"Win\n";
        else
        {
            cout<<"Lose\n";
        }
        
        
	}
}