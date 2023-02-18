#include <iostream>
using namespace std;
#include<iomanip>

int main()
{
	int t;cin>>t;
    while(t--)
    {
        int n,i,j,k,p;cin>>n;
        int a[n][n]={0};
        p=1;
        for(i=1;i<=n;i++)
        {
            for(j=0,k=i-1;j<i;j++,k--)
            {
                a[j][k]=p++;
            }
        }
        for(i=1;i<n;i++)
        {
            for(j=i,k=n-1;k>=i;j++,k--)
            {
                a[j][k]=p++;
            }
        }
            
        for(i=0;i<n;i++)
        {
             for(j=0;j<n;j++)                       //output is not as intended in
                cout<<setw(4)<<a[i][j];             //the problem (format only)
            cout<<endl<<endl;
        }
           

        
    }
}