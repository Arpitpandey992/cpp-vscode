#include <bits/stdc++.h> 
using namespace std;
int main()
{
    unsigned int k; unsigned long n; cin>>n>>k;
    for(unsigned int i=0;i<k;i++)
    {
        if(n>=10)
        {
            if(n%10!=0)
            {
                n--;
            }
            else
            {
                n/=10;
            }
            
        }
        else
        {
            n--;
        }
        
    }
    cout<<n;
}