#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>  //prefer this over map
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
#define mp make_pair
#define ff first
#define ss second
#define paus      \
    cout << endl; \
    system("pause");
ll temp;
#define fok(i, k, n) for (ll i = k; i < n; i++)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = n; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define Sort(v) sort(all(v))
#define Sortg(v) sort(all(v), greater<int>())
#define bs(v, val) binary_search(all(v), val)
#define lb(v, val) lower_bound(all(v), val)
#define ub(v, val) upper_bound(all(v), val)
#define watch(x) cout << endl \
                      << (#x) << " is " << (x) << endl
#define inpt(v)      \
    {                \
        cin >> temp; \
        v.pb(temp);  \
    }
#define fastio ios_base::sync_with_stdio(false);
//cin.tie(NULL);                    \
//cout.tie(NULL); // to get output after all input is done
#define test    \
    ui tes;     \
    cin >> tes; \
    while (tes--)
//--------------------------------------------------------------------//
unsigned long long raand()  //use raand() %x+y for numbers in (y,x)
{
    unsigned long long randnumber = 0;
    int digits[20];

    for (int i = 19; i >= 1; i--) {
        digits[i] = rand() % 10;
    }
    for (int i = 19; i >= 1; i--) {
        unsigned long long power = pow(10, i - 1);

        if (power % 2 != 0 && power != 1)  //eliminates "bug" (which comes from long long power is not a float))
            power++;

        randnumber += power * digits[i];
    }
    return randnumber;
}
template <class T1, class T2, class T3>
constexpr ll mode_exp(ll a, ll b, ll c)  //Precise Pow() (a^b)%c
{
    ll res = 1;
    a = a % c;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % c;
        }
        b /= 2;
        a = (a * a) % c;
    }
    return res;
}
constexpr ll pow2(ll a, ll b)  //Precise Pow() for integers only
{
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a);
        }
        b >>= 1;
        a = a * a;
    }
    return res;
}
bool prime[200001];  //Till n= 2*10^5
void SieveOfEratosthenes(ll n) {
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
ll modinv(ll a, ll m)  //Finding Mod inverse of a under mod m
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x % m + m) % m;
    return res;
}
struct hash_pair  //use like unordered_map <pii, int, hash_pair> m;
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
//--------------------------------------------------------------------//
bool chk0(ll a, ll b, ll c, ll p, ll q, ll r) {
    if (a == p && b == q && c == r) return true;
    return false;
}
template <class t1>
bool chk(t1 a, t1 b, t1 p, t1 q) {
    if (a == p || b == q) return true;
    if (a - p == b - q) return true;
    if (a * q == b * p)
        if (p != 0 && q != 0)
            if (ceil(float(a) / float(p)) == a / p && (ceil(float(b) / float(q)) == b / q))
                return true;
    return false;
}
bool chk1(ll a, ll b, ll c, ll p, ll q, ll r) {
    if (a == 0 && b == 0 && c == 0) return true;
    if ((a == p && b == q)) return true;
    if (c == r)
        if (chk(a, b, p, q)) return true;
    if ((a - p == b - q) && (a - p == c - r)) return true;
    if ((a * q == b * p) && (a * r == c * p)) {
        if (p != 0 && q != 0 && r != 0)
            if (ceil(float(a) / float(p)) == a / p && (ceil(float(b) / float(q)) == b / q) && (ceil(float(c) / float(r)) == c / r))
                return true;
    }
    return false;
}
bool chk2(ll a, ll b, ll c, ll p, ll q, ll r)  //considering only a,b,p,q here
{
    if (c == r) return true;
    if (chk(a, b, p, q)) return true;
    float aa = a, bb = b, cc = c, pp = p, qq = q, rr = r;
    if (chk(a, b, p + (c - r), q)) return true;
    if (chk(a, b, p, q + (c - r))) return true;
    if (chk(a, b, p + (c - r), q + (c - r))) return true;
    if (r != 0)
        if (c % r == 0) {
            if (chk(a, b, p * (c / r), q)) return true;
            if (chk(a, b, p, q * (c / r))) return true;
            if (chk(a, b, p * (c / r), q * (c / r))) return true;
        }
    float d1;
    if (pp != qq) {
        float d1 = ((bb - aa) / (qq - pp));
        if (ceil(d1) == d1) {
            float d2 = aa - pp * d1;
            if (d1 * r + d2 == c) return true;
        }
    }
    if (bb != aa) {
        d1 = (aa * qq - bb * pp) / (bb - aa);
        if (ceil(d1) == d1) {
            if (pp + d1 != 0) {
                float d2 = aa / (pp + d1);
                if (ceil(d2) == d2)
                    if ((r + d1) * d2 == c) return true;
            }
        }
    }
    if (qq != 0) {
        d1 = (rr - cc + bb) / qq;
        if (ceil(d1) == d1) {
            if (pp * d1 - aa == qq * d1 - b) return true;
        }
    }
    if (r != 0) {
        if (c % r == 0 && cc != 0) {
            float d1 = ((aa * rr) / cc) - pp;
            if (ceil(d1) == d1) {
                if (aa * (qq + d1) == (bb * (pp + d1))) {
                    if ((aa != 0 && (pp + d1) != 0) && (bb != 0 && (qq + d1) != 0)) {
                        if (ceil(aa / (pp + d1)) == aa / (pp + d1) && ceil(bb / (qq + d1)) == bb / (qq + d1))
                            return true;
                    }
                }
            }
        }
    }
    return false;
}
/* 
test cases:
10 14 16
28 36 20 
ans = 2
10 14 16
42 54 20
ans = 2
6 9 1 
0 -6 -1
ans=3
*/
int main() {
    test {
        ll p, q, r, a, b, c;
        cin >> p >> q >> r >> a >> b >> c;
        int ans = 3;
        if (chk0(a, b, c, p, q, r))
            ans = 0;
        else if (chk1(a, b, c, p, q, r) || chk1(b, c, a, q, r, p) || chk1(c, a, b, r, p, q))
            ans = 1;
        else if (chk2(a, b, c, p, q, r) || chk2(b, c, a, q, r, p) || chk2(c, a, b, r, p, q))
            ans = 2;
        cout << ans << endl;
    }
}