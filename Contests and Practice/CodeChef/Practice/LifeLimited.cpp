#include<iostream>
using namespace std;
int main()
{
    int t,i,j,flag=0;
    char a[3][3];
    cin>>t;
    while(t>=1&&t<=1000)
    {
        flag=0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                cin>>a[i][j];
        }
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                if(a[i][j]=='l')
                {
                    if(a[i+1][j]=='l'&&a[i+1][j+1]=='l')
                    {
                        flag=1;
    
                    }
                }
            }
        }
        end:
        if(flag==1)
        cout<<"yes\n";
        else
        {
            cout<<"no\n";
        }
        t--;
        

    }
}