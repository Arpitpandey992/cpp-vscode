#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int t, n, i, x[200], y[200], a, b, flag = 0;
    cin >> t;
    while (t >= 1 && t <= 50)
    {
        flag=0;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        cin >> a >> b;

       // for (int j = 0; j < 9; j++)
        {
            for (i = 0; i < n; i++)
            {
                int numx = abs(x[i] - a);
                int numy = abs(y[i] - b);
                if (numx == numy || a == x[i] || b == y[i])
                {
                    flag++;
                    break;
                }
                    
            }

        }
        for (i = 0; i < n; i++)
            {
                int numx = abs(x[i] - (a-1));
                int numy = abs(y[i] - (b-1));
                if (numx == numy || (a-1) == x[i] || (b-1) == y[i])
                {
                    flag++;
                    break;
                }
                    
            }
        for (i = 0; i < n; i++)
            {
                int numx = abs(x[i] - (a-1));
                int numy = abs(y[i] - (b));
                if (numx == numy || (a-1) == x[i] || (b) == y[i])
                {
                    flag++;
                    break;
                }
                    
            }
        for (i = 0; i < n; i++)
            {
                int numx = abs(x[i] - (a-1));
                int numy = abs(y[i] - (b+1));
                if (numx == numy || (a-1) == x[i] || (b+1) == y[i])
                {
                    flag++;
                    break;
                }
                    
            }
        for (i = 0; i < n; i++)
            {
                int numx = abs(x[i] - (a));
                int numy = abs(y[i] - (b-1));
                if (numx == numy || (a) == x[i] || (b-1) == y[i])
                {
                    flag++;
                    break;
                }
                    
            }
        for (i = 0; i < n; i++)
            {
                int numx = abs(x[i] - (a));
                int numy = abs(y[i] - (b+1));
                if (numx == numy || (a) == x[i] || (b+1) == y[i])
                {
                    flag++;
                    break;
                }
                    
            }
        for (i = 0; i < n; i++)
            {
                int numx = abs(x[i] - (a+1));
                int numy = abs(y[i] - (b-1));
                if (numx == numy || (a+1) == x[i] || (b-1) == y[i])
                {
                    flag++;
                    break;
                }
                    
            }
        for (i = 0; i < n; i++)
            {
                int numx = abs(x[i] - (a+1));
                int numy = abs(y[i] - (b));
                if (numx == numy || (a+1) == x[i] || (b) == y[i])
                {
                    flag++;
                    break;
                }
                    
            }
        for (i = 0; i < n; i++)
            {
                int numx = abs(x[i] - (a+1));
                int numy = abs(y[i] - (b+1));
                if (numx == numy || (a+1) == x[i] || (b+1) == y[i])
                {
                    flag++;
                    break;
                }
                    
            }
        
        if (flag == 9)
        {
            cout << "YES\n";
        }
        else
        {
            cout<<flag<<endl;
            cout << "NO\n";
        }

        t--;
    }
}