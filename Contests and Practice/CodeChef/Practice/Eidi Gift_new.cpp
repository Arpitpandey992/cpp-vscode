#include <iostream>
using namespace std;
void eidi()
{
    int t;
    int max = 0;
    cin >> t;
    while (t >= 1 && t <= 1000)
    {
        int a[3], c[3], i, m = 0, flag = 0, j, n = 0, boo = 0;
        for (i = 0; i < 3; i++)
            cin >> a[i];
        for (i = 0; i < 3; i++)
            cin >> c[i];
        if (a[0] <= 17 && a[1] <= 17 && a[2] <= 17 &&
            c[0] <= 100 && c[1] <= 100 && c[2] <= 100 &&
            a[0] >= 1 && a[1] >= 1 && a[2] >= 1 && c[0] >= 1 &&
            c[1] >= 1 && c[2] >= 1)
        {
            if(a[0]==a[1]&&a[0]==a[2]&&a[1]==a[2])
            {
                if(c[0]==c[1]&&c[0]==c[2]&&c[1]==c[2])
                    goto peak;
            }
            for (i = 0; i < 3; i++)
            {
                if (a[i] > max)
                {
                    max = a[i];
                    m = i;
                }
            }
            for (i = 0; i < 3; i++)
            {
                if (i != m)
                {
                    if (c[m] <= c[i])
                    {
                        flag = 1;
                    }
                }
            }
            //cout << endl<< flag << endl;

            for (i = 0; i < 3; i++)
            {
                for (j = i + 1; j < 3; j++)
                {
                    if (a[i] == a[j])
                    {
                        boo = 1;
                        if (c[i] != c[j])
                            flag = 1;
                    }
                }
            }
            //cout << endl<< flag << endl;
            if (boo == 0)
            {
                max = 0;
                for (i = 0; i < 3; i++)
                {
                    if (i != m)
                    {
                        if (a[i] > max)
                        {
                            max = a[i];
                            n = i;
                        }
                    }
                }
                // cout << endl<< flag << endl;
                for (i = 0; i < 3; i++)
                {
                    if ((i != m) && (i != n))
                    {
                        if (c[n] <= c[i])
                        {
                            flag = 1;
                        }
                    }
                }
            }

            //cout << endl  << flag << endl;

            if (flag == 0)
            {
                peak:
                cout << "FAIR\n";
            }
                
            else
            {
                
                cout << "NOT FAIR\n";
            }
        }
        
        t--;
    }
}

int main()
{
    eidi();
}