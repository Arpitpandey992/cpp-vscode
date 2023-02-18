#include <iostream>
using namespace std;
#include <cmath>
int n;
void sort(int x[],int st)
{
    n--;
    for(int i=st;i<n;i++)
    {
        x[i]=x[i+1];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t>=1)
    {
        int a[200],cost=0;
        cin>>n;
        for (int i = 0; i < n-1; i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            if(a[i+1]>a[i])
            {
                cost+=a[i];
                sort(a,i+1);
                
            }

        }
        cout<<cost<<endl;
        
        t--;
    }
}