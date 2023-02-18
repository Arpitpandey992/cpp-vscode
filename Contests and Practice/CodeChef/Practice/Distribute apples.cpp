#include <iostream>
using namespace std;
int main()
{
    int t, n, k, box1[100], box2[100], i, mul, max = 0;
    bool flag;
    cin >> t;

    while (t >= 1 && t <= 250)
    {
        flag=0;
        cin >> n >> k;
        mul = n / k;
        for (i = 0; i < k; i++)
            box2[i] = 0;
        for (i = 0; i < k; i++)
            box1[i] = 0;
        if (n % k == 0)
        {
            for (int k = 1; k <= mul; k++)
            {
                for (i = 0; i < k; i++)
                {
                    box1[i] += 1;
                }
                for (i = 0; i < k; i++)
                {
                    if (box2[i] <= max)
                    {
                        box2[i] += k;
                        max = box2[i];
                    }
                }
            }
            for (i = 0; i < k; i++)
            {
                if (box1[i] == box2[i])
                    continue;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                cout << "YES\n";
            else
            {
                cout << "NO\n";
            }
        }
        t--;
    }
}