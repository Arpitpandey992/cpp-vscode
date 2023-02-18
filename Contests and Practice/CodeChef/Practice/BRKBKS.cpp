#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#define nl cout << '\n'
#define us unsigned short
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ul unsigned long
#define endl '\n'
ll i, j, temp;
#define fok(i, k, n) for (i = k; i < n; i++)
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n; i >= 0; i--)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    //cin.tie(NULL);                    \
    //cout.tie(NULL); // to get output after all input is done
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
int main()
{
    fastio;
    test
    {
        int s;
        vector<int> w;
        int temp;
        cin >> s;
        fo(i, 3)
        {
            cin >> temp;
            w.push_back(temp);
        }
        int ct = 0;
        for (i = 0, j = 2;;)
        {
            int suma = w[i] + w[i + 1];
            int sumb = w[j] + w[j - 1];
            if (suma <= sumb && suma <= s)
            {
                if (suma + w[i + 2] <= s)
                {
                    cout << 1 << endl;
                    break;
                }
                else
                {
                    cout << 2 << endl;
                    break;
                }
            }
            else if (suma > sumb && sumb <= s)
            {
                if (sumb + w[j - 2] <= s)
                {
                    cout << 1 << endl;
                    break;
                }
                else
                {
                    cout << 2 << endl;
                    break;
                }  
            }
            else
            {
                cout << 3 << endl;
                break;
            }
            
        }
    }
}