#include<iostream>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        unsigned long n,i,j; cin>>n;
        unsigned long a[n];
        int count,max=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=1;i<n;i++)
        {
            count =0;
            for(j=0;j<i;j++)
            {
                if(a[j]%a[i]==0)
                    count++;
            }
            if(count>max)
                max=count;
        }
        cout<<max<<endl;

    }
}