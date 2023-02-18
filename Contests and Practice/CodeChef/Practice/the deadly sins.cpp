#include <iostream>
using namespace std;
#include <cmath>
int n;

int main()
{
    int t;
    cin>>t;
    while(t>=1&&t<=100000)
    {
        int x,y;
        cin>>x>>y;
        
        while(x!=y&&x!=0&&y!=0)
        {
            if(x>y)
            {
                x-=y;
            }
            else if(x<y)
            {
                y-=x;
            }
        }
        cout<<x+y<<endl;
        t--;
    }
}