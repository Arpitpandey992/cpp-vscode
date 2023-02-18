#include <iostream>
using namespace std;

int sum(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
    
}
int main()
{
    int t,n,k=1,p=1,a[100];
    cin>>t;
    int temp=t;
    while(t>0)
    {
        cin>>n;
        for(;p<=n;k++)
        {
            if(sum(k)%10==0)
            {
                p++;
            }
        }
        a[t]=k-1;
        t--;
    }
    t=temp;
    while(t>0)
    {
        cout<<a[t]<<endl;
        t--;
    }

}