#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define M 1000000007
#define M2 998244353
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
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define pb push_back
#define paus system("pause");
ll temp;
#define fok(i, k, n) for (ll i = k; i < n; i++)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = n; i >= 0; i--)
#define Sort(v) sort(v.begin(), v.end())
#define Sortg(v) sort(v.begin(), v.end(), greater<int>())
#define lb(v, val) lower_bound(v.begin(), v.end(), val)
#define ub(v, val) upper_bound(v.begin(), v.end(), val)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define inpt(v)      \
    {                \
        cin >> temp; \
        v.pb(temp);  \
    }
#define fastio ios_base::sync_with_stdio(false);
//cin.tie(NULL);                    \
//cout.tie(NULL); // to get output after all input is done
#define test    \
    ul tes;     \
    cin >> tes; \
    while (tes--)
//----------------------------------------------------------------------------------//
template <class T1, class T2, class T3>
constexpr ll mode_exp(ll a, ll b, ll c) //Precise Pow() (a^b)%c
{
    ll res = 1;
    a = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % c;
        }
        b /= 2;
        a = (a * a) % c;
    }
    return res;
}
constexpr ll pow2(ll a, ll b) //Precise Pow() for integers only
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a);
        }
        b /= 2;
    }
    return res;
}
bool prime[200001]; //Till n= 2*10^5
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int p = 2; p * p <= 200000; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= 200000; i += p)
                prime[i] = false;
        }
    }
    return;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
ll modinv(ll a, ll m) //Finding Mod inverse of a under mod m
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x % m + m) % m;
    return res;
}
//----------------------------------------------------------------------------------//
int main()
{
    test
    {
        int n;
        cin >> n;
        vi x;
        fo(i, n)
            inpt(x);
        int ct[n];
        fo(i, n) ct[i] = 1;
        fo(i, n)
        {
            int inf = i;
            fok(j, i + 1, n)
            {
                if (x[j] - x[inf] <= 2)
                {
                    ct[i]++;
                    inf = j;
                }
                else
                    break;
            }
            inf = i;
            for (ll j = i - 1; j >= 0; j--)
            {
                if (x[inf] - x[j] <= 2)
                {
                    ct[i]++;
                    inf = j;
                }
                else
                    break;
            }
        }
        cout << *min_element(ct, ct + n) << " " << *max_element(ct, ct + n) << endl;
    }
}