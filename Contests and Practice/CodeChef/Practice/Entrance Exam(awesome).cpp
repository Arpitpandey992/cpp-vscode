#include <iostream>
using namespace std;
long long maxk(long long x[],int k,int n)
{
int p=0;
	start :
	long long max=x[0];
	int l=0;
	
	for(int i=0;i<n-1;i++)
	{
	//	cout<<x[i]<<endl;
		if(x[i]>max)
		{
			max=x[i];
			l=i;
		}	
	}
	p++;
		if(p==k)
			return max;
		x[l]=0;
		goto start;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int k,n,e,i,j;
		long long m;
		cin>>n>>k>>e>>m;
		long long sc[n][e];
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<e;j++)
				cin>>sc[i][j];
		}
		for(j=0;j<e-1;j++)
		{
				cin>>sc[n-1][j];
		}
		long long sum[n]={0};
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<e;j++)
			{
				sum[i]+=sc[i][j];
			}
		}
		for(j=0;j<e-1;j++)
		{
				sum[n-1]+=sc[n-1][j];
		}
		long long need=maxk(sum,k,n);
		//cout<<"test"<<need<<endl;
		if((-sum[n-1]+need)>=m)
			cout<<"Impossible\n";
		else if(sum[n-1]>need)
			cout<<"0\n";
		else
		{
			//cout<<need<<endl;
			cout<<(need-sum[n-1])+1<<endl;
		}
		
	}
}