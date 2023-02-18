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
#include <unordered_map> //prefer this over map
#include <unordered_set>
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
void shift(vvi &ans, int x, int y, int z)
{
    vi tp;
    tp.pb(x);
    tp.pb(y);
    tp.pb(z);
    ans.pb(tp);
}
void changer(set<int> &s, vi &p, int x, int y, int z)
{
    int a = p[x], b = p[y], c = p[z];
    s.erase(y);
    s.erase(z);
    p[x] = c;
    p[y] = a;
    p[z] = b;
}
void changel(set<int> &s, vi &p, int x, int y, int z)
{
    int a = p[x], b = p[y], c = p[z];
    s.erase(x);
    s.erase(y);
    p[x] = c;
    p[y] = a;
    p[z] = b;
}
void change2r(set<int> &s, vi &p, int x, int y, int z)
{
    int a = p[x], b = p[y], c = p[z];
    p[x] = c;
    p[y] = a;
    p[z] = b;
}
void change2l(set<int> &s, vi &p, int x, int y, int z)
{
    int a = p[x], b = p[y], c = p[z];
    p[x] = c;
    p[y] = a;
    p[z] = b;
}
int main()
{
    test
    {
        ll n, k, m = 0;
        vvi ans;
        cin >> n >> k;
        vi p;
        bool flag = 1;
        p.pb(0);
        set<int> s;
        fok(i, 1, n + 1)
        {
            int temp;
            cin >> temp;
            p.pb(temp);
            if (temp != i)
                s.insert(i);
        }
        for (int i = 1; (i < n + 1) && flag; i++)
        {
            if ((p[p[i]] > p[i]) && p[i] > i && p[p[i]] > i)
            {

                if (p[p[p[i]]] == i)
                {
                    shift(ans, i, p[i], p[p[i]]);
                    changer(s, p, i, p[i], p[p[i]]);
                    if (i == p[i])
                        s.erase(i);
                    m++;
                }
            }
            else if ((p[p[i]] < p[i]) && p[i] > i && p[p[i]] > i) //case 2, left shift
            {
                if (p[p[p[i]]] == i)
                {
                    shift(ans, p[i], p[p[i]], i);
                    changel(s, p, p[i], p[p[i]], i);
                    if (i == p[i])
                        s.erase(i);
                    m++;
                }
            }
        }
        bool flags = 1;
        if (s.empty())
            flags = 0;
    start:
        for (int i = 1; (i < n + 1) && flag && flags; i++)
        {
            if (s.empty())
            {
                flags = 0;
                goto start;
            }
            while (p[i] != i)
            {
                if (p[p[i]] > p[i] && p[i] > i && p[p[i]] > i) //case 1, right shift
                {
                    shift(ans, i, p[i], p[p[i]]);
                    changer(s, p, i, p[i], p[p[i]]);
                    if (i == p[i])
                        s.erase(i);
                    m++;
                }
                else if (p[p[i]] < p[i] && p[i] > i && p[p[i]] > i) //case 2, left shift
                {
                    shift(ans, p[i], p[p[i]], i);
                    changel(s, p, p[i], p[p[i]], i);
                    if (i == p[i])
                        s.erase(i);
                    m++;
                }
                else //p[p[i]]==i
                {
                    break;
                }
            }
        }
        if (s.empty())
            flags = 0;
        for (int i = 1; (i < n + 1) && flag && flags; i++)
        {
            if (s.empty())
            {
                flags = 0;
                goto start;
            }
            while (p[i] != i)
            {
                if (p[p[i]] > p[i]) //case 1, right shift
                {
                    shift(ans, i, p[i], p[p[i]]);
                    changer(s, p, i, p[i], p[p[i]]);
                    if (i == p[i])
                        s.erase(i);
                    m++;
                }
                else if (p[p[i]] < p[i] && p[p[i]] != i) //case 2, left shift
                {
                    shift(ans, p[i], p[p[i]], i);
                    changel(s, p, p[i], p[p[i]], i);
                    if (i == p[i])
                        s.erase(i);
                    m++;
                }
                else //p[p[i]]==i
                {
                    s.erase(p[i]);
                    auto it = s.begin();
                    bool flag1 = 0;
                    for (; it != s.end(); it++)
                    {
                        if (*it != i)
                        {
                            flag1 = 1;
                            break;
                        }
                    }
                    if (flag1)
                    {
                        int tt = *it;
                        m++;
                        if (tt > p[i])
                        {
                            shift(ans, i, p[i], tt);
                            change2r(s, p, i, p[i], tt);
                            if (i == p[i])
                                s.erase(i);
                        }
                        else
                        {
                            shift(ans, p[i], tt, i);
                            change2l(s, p, p[i], tt, i);
                            if (i == p[i])
                                s.erase(i);
                        }
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag && (m <= k))
        {
            cout << m << endl;
            fo(i, m)
            {
                for (auto x : ans[i])
                {
                    cout << x << " ";
                }
                cout << endl;
            }
        }
        else
            cout << -1 << endl;
    }
}