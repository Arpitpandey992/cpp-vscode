#include <algorithm>
#include <chrono>
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
#include <unordered_set>
#include <vector>
using namespace std;
using namespace chrono;
const long long M = 1000000007;
const int INF = INT32_MAX;
#pragma region
#define endl '\n'
#define nl cout << '\n'
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ld long double
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
#define mp make_pair
#define ff first
#define ss second
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fastio_interactive \
    cin.tie(0)->sync_with_stdio(0);  //remove #define endl for flushing
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
#define test    \
    ui tes;     \
    cin >> tes; \
    while (tes--)
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
ll modexp(ll a, ll b, ll c = M)  //Precise Pow() (a^b)%c
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
int* spf;
void SieveOfEratosthenes(int n) {
    prime = new bool[n + 1];
    memset(prime, true, n + 1);
    spf = new int[n + 1];
    fo(i, n + 1) spf[i] = i;
    prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
                spf[i] = p;
            }
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
ll modinv(ll a, ll m)  //Finding Mod inverse of a under mod m (when a and m are coprime)
{
    ll x, y;
    gcdExtended(a, m, &x, &y);
    ll res = (x % m + m) % m;
    return res;
}
ll modinvprime(ll a, ll m)  //when m is prime
{
    return modexp(a, m - 2, m);
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
ll modadd(ll a, ll b, ll m = M) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll modmul(ll a, ll b, ll m = M) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll modsub(ll a, ll b, ll m = M) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll moddiv(ll a, ll b, ll m = M)  //m must be prime
{
    a = a % m;
    b = b % m;
    return (modmul(a, modinvprime(b, m), m) + m) % m;
}
#pragma endregion
//--------------------------------------------------------------------//
int main() {
#ifdef ONLINE_JUDGE
    fastio;
#endif
    void solve();
    int tes = 1;
    //cin >> tes;
    while (tes--) {
        solve();
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int j = 0;
    for (int i = 1; i < n;) {
        int oi = i;
        while (j < n && s[i] == s[j]) {
            i++;
            j++;
        }
        if (i == n || s[j] < s[i]) {
            s = s.substr(0, oi);
            break;
        }
        i++;
        j = 0;
    }
    while (s.size() < k) {
        s += s;
    }
    while (s.size() > k) s.pop_back();
    cout << s << endl;
}