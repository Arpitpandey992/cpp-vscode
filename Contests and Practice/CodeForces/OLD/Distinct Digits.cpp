#include<iostream>
using namespace std;
int chk(long p)
{
    int i=0,n[7],j,size=0;
    while(p>0)
    {
        size++;
        n[i]=p%10;
        p/=10;
        i++;
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size&&j!=i;j++)
        {
            if(n[i]==n[j])
                return 0;
        }
    }
    return 1;
}
int main()
{
    
    long l,r,i,j,p;
    cin>>l>>r;
    for(p=l;p<=r;p++)
    {
        if(chk(p))
        {
            cout<<p;
            exit(0);
        }    
    }
    cout<<"-1";
}