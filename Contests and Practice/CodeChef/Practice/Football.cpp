#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int cas = 0, tes, p = 0;
    cin >> tes;
    if (tes > 100 || tes < 1)
        exit(0);

start:
    cas++;
    int a[150], b[150], c[150], n, maxim[100];
    cin >> n;
    if (n > 150 || n < 1)
        exit(0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 50 || a[i] < 0)
            exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] > 50 || b[i] < 0)
            exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        c[i] = ((a[i] * 20) - (b[i] * 10));
        if (c[i] < 0)
            c[i] = 0;
    }
    maxim[p] = c[0];
    for (int i = 0; i < n; i++)
    {
        if (c[i] > maxim[p])
            maxim[p] = c[i];
    }

    if (cas < tes)
    {
        p++;
        goto start;
    }
    for (int i = 0; i < tes; i++)
        cout << maxim[i] << endl;
}
