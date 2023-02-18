#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
         int n;
        cin >> n;
         int p[n], i;
         int j, count = 0;
        for (i = 0; i < n; i++) 
            cin >> p[i];
        for (i = 0; i < n; i++)
        {
            if (i - 5 < 0)
                j = 0;
            else
            {
                j = i - 5;
            }

            int flag = 1;
            for (; j < i; j++)
            {
                if (p[j] <= p[i])
                {
                    //cout<<endl<<j<<endl<<i<<endl;
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                count++;
                //cout<<i<<endl;
            }
                
        }
        cout << count << endl;
    }
}
