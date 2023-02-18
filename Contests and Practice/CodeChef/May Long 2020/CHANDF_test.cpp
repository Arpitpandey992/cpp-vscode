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
vll ansa;
void decToBinary(ll n, vi &binaryNum)
{
    while (n > 0)
    {
        binaryNum.pb(n % 2);
        n = n / 2;
    }
    //reverse(binaryNum.begin(), binaryNum.end());
}
ll msb(ll n)
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    n |= n >> 64;
    n = n + 1;
    return (n >> 1);
}
ll bin2no(vi bin)
{
    ll t = 0;
    for (int i = bin.size() - 1; i >= 0; i--)
    {
        if (bin[i])
        {
            t += (pow2(2, i));
        }
    }
    return t;
}
ll naive(ll x, ll y, ll l, ll r)
{
    if (x == 0 || y == 0 || r == 0)
        return 0;
    ll maxx = -1, maxi = l;
    for (ll i = l; i <= r; i++)
    {
        if ((x & i) * (y & i) > maxx)
        {
            maxx = (x & i) * (y & i);
            maxi = i;
        }
    }
    return maxi;
}
ll x, y;
vi bin;
ll l; //TEST CASE - 23 100 56 67,1444 5676 4013 5000
ll dp(ll p, ll prev, vi &bin, int i, ll r)
{
    if (p < l)
    {
        for (int j = 0; j <= i; j++)
        {
            if (bin[j] == 0)
            {
                bin[j] = 1;
                return dp(p + pow2(2, j), prev, bin, i, r);
            }
        }
        // ansa.pb(0);
        return 0;
    }
    else if ((p <= r) && p >= l)
    {
        // ansa.pb(p);
        return (p & x) * (p & y);
    }
    else if (i == 0)
    {
        if ((p - 1) <= r && (p - 1) >= l)
        {
            p -= 1;
            bin[i] = 0;
            // ansa.pb(p);
            return (p & x) * (p & y);
        }
        else
        {
            //ansa.pb(0);
            return 0;
        }
    }
    else if (bin[i])
    {
        ll par = pow2(2, i);
        if (((p - par - prev) < p - r))
        {
            bin[i] = 0;
            return (dp(p - par, prev, bin, i - 1, r));
        }
        else
        {
            vi bin1 = bin, bin2 = bin;
            bin1[i] = 0;
            ll sum1 = dp(p - par, prev, bin1, i - 1, r);
            ll sum2 = dp(p, prev + par, bin2, i - 1, r);
            if (sum1 >= sum2)
            {
                bin = bin1;
                return sum1;
            }
            else
            {
                bin = bin2;
                return sum2;
            }
        }
    }
    else if (i != 0)
    {
        return dp(p, prev, bin, i - 1, r);
    }
    else
    {
        ansa.pb(0);
        return 0;
    }
}
int main()
{
    fastio;
    test
    {
        ll l = 0, r = 0;
        //cin >> x >> y >> l >> r;

        ll range = 10000000;
        x = raand() % (range);
        y = raand() % (range / 100);
        l = raand() % (range / 1000);
        r = raand() % (range - l) + l;

        ll ans = 0, maxx = 0;
        if (r != 0 && x != 0 && y != 0)
        {
            ::l = l;
            ll p = (x + y - (x & y));
            if (p < l) // TEst 400 1200 843 900
            {
                vi bin1, bin2;
                decToBinary(p, bin1);
                decToBinary(l, bin2);
                for (int i = bin1.size(); i < bin2.size(); i++)
                    bin1.pb(bin2[i]);
                p = bin2no(bin1);
            }
            while ((p - r) >= (msb(p)))
                p -= (msb(p));
            vi bin;
            decToBinary(p, bin);
            vi bino = bin;
            int n = bin.size();
            ans = 0;
            maxx = dp(p, 0, bin, n - 1, r);
            p = bin2no(bin);
            for (int i = bin.size() - 1; i >= 0; i--)
            {
                if (bin[i] == 1 && bino[i] == 0)
                {
                    if (p - pow2(2, i) >= l)
                    {
                        bin[i] = 0;
                        p -= pow2(2, i);
                    }
                }
            }
            if (maxx)
                ans = p;
            else
                ans = l;
        }
        else
            ans = 0;
        ll ans2 = naive(x, y, l, r);
        cout << ans << " " << ans2 << " " << x << " " << y << " " << l << " " << r << endl;
        if (ans != ans2)
        {
            cout << x << " " << y << " " << l << " " << r << " " << endl;
            cout << ans << " " << ans2 << endl;
            cout.flush();
            paus;
        }
        //cout << ans << endl;
        //cout << "val " << maxx << endl;
        //cout << "for " << x << " - " << powdown(x) << " to " << powup(x) << endl;
        //cout << "for " << y << " - " << powdown(y) << " to " << powup(y) << endl;
    }
}