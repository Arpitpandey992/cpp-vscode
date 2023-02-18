#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using namespace __gnu_pbds;
const long long M = 100000000;
const int INF = 2147483647;
const long long INFLL = 9223372036854775807ll;
#pragma region
#define endl '\n'
#define nl cout << '\n'
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpil vector<pil>
#define vpli vector<pli>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ff first
#define ss second
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fok(i, k, n) for (ll i = k; i < n; i++)
#define Fok(i, k, n) for (ll i = n; i >= k; i--)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = n; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define allg(v) v.rbegin(), v.rend()
#define Sort(v) sort(all(v))
#define Sortg(v) sort(allg(v))
#define sz(v) v.size()
#define bs(v, val) binary_search(all(v), val)
#define lb(v, val) lower_bound(all(v), val)
#define ub(v, val) upper_bound(all(v), val)
#define setbits(x) __builtin_popcount(x)
#define test    \
    ui tes;     \
    cin >> tes; \
    while (tes--)
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//--------------------------------------------------------------------//
//DEBUG STATEMENTS!
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x) {
    int f = 0;
    cerr << '{';
    for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
//END OF DEBUG STATEMENTS!
//--------------------------------------------------------------------//
//Modular Class
template <int MOD = M>
struct Modular {
    int value;
    static const int MOD_value = MOD;

    Modular(long long v = 0) {
        value = v % MOD;
        if (value < 0) value += MOD;
    }
    Modular(long long a, long long b) : value(0) {
        *this += a;
        *this /= b;
    }

    Modular& operator+=(Modular const& b) {
        value += b.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    Modular& operator-=(Modular const& b) {
        value -= b.value;
        if (value < 0) value += MOD;
        return *this;
    }
    Modular& operator*=(Modular const& b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }

    friend Modular mexp(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

    Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend std::ostream& operator<<(std::ostream& os, Modular const& a) { return os << a.value; }
    friend bool operator==(Modular const& a, Modular const& b) { return a.value == b.value; }
    friend bool operator!=(Modular const& a, Modular const& b) { return a.value != b.value; }
};
typedef Modular<M> mint;
//End of ModInt Class
//--------------------------------------------------------------------//
//Useful Functions
ll ceil(ll a, ll b) {
    return (a / b) + ((a % b) != 0);
}
unsigned ll rng(unsigned ll l = 0, unsigned ll r = INFLL - 1) {
    mt19937_64 gen(std::random_device{}());
    unsigned ll res = gen();
    return res % (r - l + 1) + l;  //Random no in [l, r].
}
ll modexp(ll a, ll b, ll m = M) {  //Precise Pow() (a^b)%m
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll pow2(ll a, ll b) {  //Precise Pow() for integers only
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a);
        b >>= 1;
        a = a * a;
    }
    return res;
}
bool* prime;
int* spf;
void SieveOfEratosthenes(int n = 1e7) {
    prime = new bool[n + 1];
    memset(prime, true, n + 1);
    spf = new int[n + 1];
    fo(i, n + 1) spf[i] = i;
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
                if (spf[i] == i)
                    spf[i] = p;
            }
        }
    }
}
vector<int> prime_fac(int n) {  //call sieve before using this function
    vector<int> ret;
    while (n != 1) {
        ret.push_back(spf[n]);
        n = n / spf[n];
    }
    return ret;
}
ll *fac, *facNumInv, *NaturalNumInv;
void factorial(int N = 1e6 + 1, int p = M) {
    fac = new ll[N + 1];
    fac[0] = 1;
    for (int i = 1; i <= N; ++i)
        fac[i] = fac[i - 1] * i, fac[i] %= p;
}
void InverseofNumber(int N = 1e6 + 1, ll p = M) {
    NaturalNumInv = new ll[N + 1];
    NaturalNumInv[0] = NaturalNumInv[1] = 1;
    for (int i = 2; i <= N; i++)
        NaturalNumInv[i] = NaturalNumInv[p % i] * (p - p / i) % p;
}
void InverseofFactorial(int N = 1e6 + 1, ll p = M) {
    facNumInv = new ll[N + 1];
    facNumInv[0] = facNumInv[1] = 1;
    for (int i = 2; i <= N; i++)
        facNumInv[i] = (NaturalNumInv[i] * facNumInv[i - 1]) % p;
}
void precomputeNcR(int n = 1e6 + 1, int p = M) {
    InverseofNumber(n, p);
    InverseofFactorial(n, p);
    factorial(n, p);
}
ll ncrmodp(ll n, ll r, ll p = M) {  // maximum N = 1e7, M must be prime
    if (r > n || r < 0) return 0;
    if (r == 0) return 1;
    return ((fac[n] * facNumInv[r]) % p * facNumInv[n - r]) % p;
}
#pragma endregion
//-------------------------------------------------------------------------------//
int n1, n2, k1, k2;
int DP[101][101][2];
int dp(int n1, int n2, int ch) {
    if (n1 < 0 || n2 < 0) return 0;
    if (n1 == 0 && n2 == 0)
        return 1;
    if (DP[n1][n2][ch] != -1)
        return DP[n1][n2][ch];
    if (ch) {
        int ans = 0;
        for (int i = 1; i <= k1; i++)
            ans = (ans + dp(n1 - i, n2, !ch)) % M;
        return DP[n1][n2][ch] = ans;
    }
    int ans = 0;
    for (int i = 1; i <= k2; i++)
        ans = (ans + dp(n1, n2 - i, !ch)) % M;
    return DP[n1][n2][ch] = ans;
}

void solve() {
    cin >> n1 >> n2 >> k1 >> k2;
    memset(DP, -1, sizeof(DP));
    cout << (dp(n1, n2, 0) + dp(n1, n2, 1)) % M;
}

int main() {
#ifdef ONLINE_JUDGE
    fastio;
#endif
    int tes = 1;
    // cin >> tes;
    while (tes--) {
        solve();
    }
}