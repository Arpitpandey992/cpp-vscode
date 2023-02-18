#include<iostream>
using namespace std;
#include<stdio.h>

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,i;
        long long k;
        cin>>n>>k;
        long a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<k;i++)
        {
            int at=i%n;
            int bt=n-at-1;
            a[at]=a[at]^a[bt];

        }
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
    }
}