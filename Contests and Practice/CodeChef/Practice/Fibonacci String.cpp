#include <iostream>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
void sort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
int main()
{
	int t;cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int size=s.size(),i,j,k;
        char c[size];
        int sz[size]={1};
        fill_n(sz, size, 1);
        for(i=0,k=0;i<size;i++)
        {
            bool flag=0;
            for(j=0;j<k;j++)
            {
                if(c[j]==s[i])
                {
                    flag=1;
                    sz[j]++;
                }  
            }
            if(flag==0)
            {
                c[k++]=s[i];
            }
        }
        sort(sz,k);
        for(i=0;i<k;i++)
            cout<<sz[i]<<" ";
        bool flag=0;
        for(i=2;i<k;i++)
        {
            if(sz[i]!=(sz[i-1]+sz[i-2]))
                flag=1;
        }
        if(flag==0)
            cout<<"Dynamic\n";
        else
        {
            cout<<"Not\n";
        }
        
        
    }
}