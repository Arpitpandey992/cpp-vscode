#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<algorithm>   
#include<cmath>
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ul unsigned long
#define fori for (i = 0; i < n; i++)
#define forj for (j = i+1; j < n; j++)
#define test  ul t; cin >> t; while (t--)
using namespace std;
//----------------------------------------------------------------------------------//

int main()
{
    test
    {
        int n,i,j,k=0; cin >> n; cin.ignore();
        char s[n]; cin >> s;
        int max[n]={0}, temp;
        fori
        {
            forj
            {
                if(s[i]==s[j])
                {
                    max[k++] = (n - j);
                    break;
                }
            }
        }
        
        for (i = 1, temp = max[0]; i < k; i++)
        {
            if (max[i] > temp)
                temp = max[i];
            }
        cout << temp << endl;
    }
}