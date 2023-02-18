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
const long long M = 1e9 + 7;
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
ll ceil(ll a, ll b) {
    return (a / b) + ((a % b) != 0);
}
unsigned ll rng(unsigned ll l = 0, unsigned ll r = INFLL - 1) {
    mt19937_64 gen(std::random_device{}());
    unsigned ll res = gen();
    return res % (r - l + 1) + l;  //Random no in [l, r].
}
int modexp(int a, int b, int c = M) {  //Precise Pow() (a^b)%c
    int res = 1;
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
ll modinv(ll a, ll m) {
    return modexp(a, m - 2, m);  //a and m are coprime
}
ll modadd(ll a, ll b, ll m = M) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll modmul(ll a, ll b, ll m = M) {
    return (a * b) % m;
}
ll modsub(ll a, ll b, ll m = M) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll moddiv(ll a, ll b, ll m = M) {
    a = a % m;
    b = b % m;
    return (modmul(a, modinv(b, m), m) + m) % m;  //m is prime
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

#pragma endregion
//-------------------------------------------------------------------------------//

const int N = 1e7 + 1;
using namespace std;

// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];

// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];

// array to store factorial of first N numbers
ll fact[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(ll p) {
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p) {
    factorialNumInverse[0] = factorialNumInverse[1] = 1;

    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(ll p) {
    fact[0] = 1;

    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

// Function to return nCr % p in O(1) time
ll Ncrmodp(ll N, ll R, ll p) {
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
    return ans;
}

ll pref[N];
void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = ((n - 1 - k) * (n - k)) / 2;
    ans = modmul(ans, modsub(pref[n], pref[k]));
    cout << ans << endl;
}

int main() {
#ifdef ONLINE_JUDGE
    fastio;
#endif
    ll p = 1000000007;
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);
    ll ans = 0;
    pref[0] = 0;
    for (int j = 1; j <= N; j++) {
        ll val = Ncrmodp(N, j, M);
        // ll v1 = j - 1 - k;
        ll v2 = fact[max(0, j - 2)];
        ll v3 = fact[N - j];
        ans = (ans + modmul(val, modmul(v2, v3))) % M;
        pref[j] = ans;
    }
    int tes = 1;
    cin >> tes;
    while (tes--) {
        solve();
    }
}