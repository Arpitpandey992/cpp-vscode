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
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n - 1; i >= 0; i--)
#define fok(i, k, n) for (i = k; i < n; i++)
#define forj for (j = 0; j < n; j++)
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
int main()
{
    ios_base::sync_with_stdio(false); // just speeds up execution time
    //cin.tie(NULL);                    // to get output after all input is done
    test
    {
        ll n, ct = 0;
        cin >> n;
        ll s[n];
        fo(i, n)
        {
            cin >> s[i];
        }
        ll tmp = 0,ct2=0;
        for (i = n-1; i >= 0;)
        {
            auto it = min_element(s, s + i+1);
            if((*it-tmp)>=1)
            {
                //cout << "*it = " << *it << " i= "<< i;
                ct += (*it-tmp)*(i+1);
                tmp += ((ct-ct2) / (i + 1));
                ct2 = ct;
                //cout<< "ct = " << ct <<" temp = "<<tmp<< endl;
                for (j = i; j >= 0;j--)
                {
                    if (s[j] == *it)
                    {
                        //cout << j << " j\n";
                        i = j-1;
                        break;
                    }
                }
            }
            else
            {
                i--;
            }
            
            
        }
        cout << ct << endl;
    }
}
                