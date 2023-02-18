#include <vector>
#include <string>
#include <map>
#include <set>
#include<stack>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <sstream>
#include<unordered_map>
using namespace std;
#define M 1000000007
#define nl cout << '\n'
#define us unsigned short
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ld long double
#define ul unsigned long
#define endl '\n'
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define pb push_back
ll i, j, k, temp;
#define fok(i, k, n) for (i = k; i < n; i++)
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n; i >= 0; i--)
#define Fok(i,k,n) for (i = n; i >= k; i--)
#define Sort(v) sort(v.begin(),v.end())
#define Sortd(v) sort(v.begin(),v.end(),greater<int>())
#define fastio ios_base::sync_with_stdio(false)
//cin.tie(NULL);                    \
//cout.tie(NULL); // to get output after all input is done
#define test ul t; cin >> t
//----------------------------------------------------------------------------------//
//Include lines And Stuff Above

void primeFactors(ll n, ll&ct)
{
    // Print the number of 2s that divide n  
    while (n % 2 == 0)
    {
        ct++;
        n = n / 2;
    }

    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n  
        while (n % i == 0)
        {
            ct++;
            n = n / i;
        }
    }

    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)
        ct++;
}

int main()
{
	fastio;
	int t; cin >> t;
	while (t--)
	{
        ll x, k; cin >> x >> k; ll nof = 0; ll ct = 0;
        primeFactors(x,ct);
        if (ct >= k)
            cout << 1 << endl;
        else
            cout << 0 << endl;
	}

}

