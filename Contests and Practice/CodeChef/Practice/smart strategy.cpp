#include<iostream>
using namespace std;
#include<cmath>
unsigned int d[1000],x[100000];
unsigned int n,t,q,i,j;
int main()
{
    cin>>t;
    while(t>=1&&t<=1000)
    {
        cin>>n>>q;
        for ( i = 0; i < n; i++)
        {
            cin>>d[i];
        }
        for ( i = 0; i < q; i++)
        {
            cin>>x[i];
        }

        for(j=0;j<q;j++)
        {
            for(i=0;i<n;i++)
            {
                x[j]=floor(x[j]/d[i]);
            }
            cout<<x[j]<<" ";
        }
        cout<<endl;
        t--;
    }
}