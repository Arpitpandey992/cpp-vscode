#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
const long long M = 1000000007;
const long long M2 = 998244353;
const long long M3 = 1000000009;
const unsigned int INF = INT_MAX;
#define endl '\n'
#define nl cout << '\n'
#define fout fflush(stdout)
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ld long double
#define um unordered_map
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpil vector<pil>
#define vpli vector<pli>
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define paus      \
    cout << endl; \
    system("pause");
#define fok(i, k, n) for (ll i = k; i < n; i++)
#define Fok(i, k, n) for (ll i = n; i >= k; i--)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = n; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define allg(v) v.rbegin(), v.rend()
#define Sort(v) sort(all(v))
#define Sortg(v) sort(allg(v))
#define bs(v, val) binary_search(all(v), val)
#define lb(v, val) lower_bound(all(v), val)
#define ub(v, val) upper_bound(all(v), val)
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
constexpr ll mod_exp(ll a, ll b, ll c)  //Precise Pow() (a^b)%c
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
bool* prime;
void SieveOfEratosthenes(int n) {
    prime = new bool[n];
    memset(prime, true, n);
    prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return;
}
ll gcdExtended(ll a, ll b, ll* x, ll* y) {
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
ll mod_inv(ll a, ll m)  //Finding Mod inverse of a under mod m
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x % m + m) % m;
    return res;
}
struct hash_pair  //use like unordered_map <pii, int, hash_pair> m;
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
ll mod_add(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (mod_mul(a, mod_inv(b, m), m) + m) % m;
}
//--------------------------------------------------------------------//
ll dp[1002][1002][2];
int n0, k0;

ll DP(int n, int k, int dir) {
    if (k < 1) return -1;
    if (n < 1 || n > n0) return 0;
    if (dir == 0) {
        if (dp[n][k][dir] == -1) {
            dp[n][k][dir] = (DP(n + 1, k, 0) % M + DP(n - 1, k - 1, 1) % M + 1 + M) % M;
        }
    } else {
        if (dp[n][k][dir] == -1)
            dp[n][k][dir] = (DP(n + 1, k - 1, 0) % M + DP(n - 1, k, 1) % M + 1 + M) % M;
    }
    return dp[n][k][dir];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test {
        cin >> n0 >> k0;
        fo(i, n0 + 1) {
            fo(j, k0 + 1) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        cout << DP(1, k0, 0) + 1 << endl;
    }
}