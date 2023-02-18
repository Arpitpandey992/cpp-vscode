#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map> //prefer this over map
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
unsigned long long raand() //use raand() %x+y for numbers in (y,x)
{
    unsigned long long randnumber = 0;
    int digits[20];

    for (int i = 19; i >= 1; i--)
    {
        digits[i] = rand() % 10;
    }
    for (int i = 19; i >= 1; i--)
    {
        unsigned long long power = pow(10, i - 1);

        if (power % 2 != 0 && power != 1) //eliminates "bug" (which comes from long long power is not a float))
            power++;

        randnumber += power * digits[i];
    }
    return randnumber;
}
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
        a = a * a;
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
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        int n;
        vector<pair<string, int>> s;
        cin >> a >> b >> n;
        vector<string> sa, sb;
        int na = a.size(), nb = b.size();
        for (int i = 0; i < na; i++)
        {
            char temp[na - i + 1];
            int tempindex = 0;
            for (int j = i; j < na; j++)
            {
                temp[tempindex++] = a[j];
                temp[tempindex] = '\0';
                sa.pb(temp);
            }
        }
        for (int i = 0; i < nb; i++)
        {
            char temp[nb - i + 1];
            int tempindex = 0;
            for (int j = i; j < nb; j++)
            {
                temp[tempindex++] = b[j];
                temp[tempindex] = '\0';
                sb.pb(temp);
            }
        }
        Sort(sb);
        Sort(sa);
        fo(i, n) //input
        {
            string tp;
            int pp;
            cin >> tp >> pp;
            s.pb({tp, pp});
        }
        Sort(s);
    }
}