#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int t, n, m, k,a[100],r=0;
    cin >> t;
    int p=t;
    while (t >= 1 && t <= 100)
    {
        cin >> n >> m >> k;
        for (; k > 0; k--)
        {
            if (n >= m)
            {
                m++;
                if(n==m)
                   break;
            }
            else
            {
                n++;
            }
        }
        a[r] = abs(n - m);
        t--;
        r++;
    }
    for(int i=0;i<p;i++)
       cout<<a[i]<<endl;
}