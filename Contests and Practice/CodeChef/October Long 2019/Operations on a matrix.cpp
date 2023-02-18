#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n, m, q, i, j,count=0;
        cin >> n >> m >> q;
        long x[q], y[q];
        long a[n][m]={0,0};

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        
        for (i = 0; i < q; i++)
        {
            cin >> x[i] >> y[i];
            x[i]--;
            y[i]--;
        }

        for (i = 0; i < q; i++)
        {
            for (j = 0; j < m; j++)
            {
                a[x[i]][j] += 1;
            }
            for (j = 0; j < n; j++)
            {
                a[j][y[i]] += 1;
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if(a[i][j]%2!=0)
                    count++;
            }
        }
        cout<<count<<endl;
    }
}