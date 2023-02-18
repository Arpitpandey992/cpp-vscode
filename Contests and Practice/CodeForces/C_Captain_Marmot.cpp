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
#include <unordered_set>
#include <vector>
using namespace std;
const long long M = 1000000007;
const long long M2 = 998244353;
const long long M3 = 1000000009;
const unsigned int INF = INT32_MAX;
/* #region   */
#define endl '\n'
#define nl cout << '\n'
#define fout cout.flush()
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
#define bs(v, val) binary_search(all(v), val)
#define lb(v, val) lower_bound(all(v), val)
#define ub(v, val) upper_bound(all(v), val)
#define test    \
    ui tes;     \
    cin >> tes; \
    while (tes--)

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
constexpr ll modexp(ll a, ll b, ll c = M)  //Precise Pow() (a^b)%c
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
/* #endregion */
//--------------------------------------------------------------------//

int distSq(int& x1, int& y1, int& x2, int& y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
bool isSquare(int x[], int y[]) {
    int d2 = distSq(x[0], y[0], x[1], y[1]);  // from p1 to p2
    int d3 = distSq(x[0], y[0], x[2], y[2]);  // from p1 to p3
    int d4 = distSq(x[0], y[0], x[3], y[3]);  // from p1 to p4
    if (d2 == 0 || d3 == 0 || d4 == 0)
        return false;
    if (d2 == d3 && 2 * d2 == d4 && 2 * distSq(x[1], y[1], x[3], y[3]) == distSq(x[1], y[1], x[2], y[2])) {
        return true;
    }

    // The below two cases are similar to above case
    if (d3 == d4 && 2 * d3 == d2 && 2 * distSq(x[1], y[1], x[2], y[2]) == distSq(x[2], y[2], x[3], y[3])) {
        return true;
    }
    if (d2 == d4 && 2 * d2 == d3 && 2 * distSq(x[1], y[1], x[2], y[2]) == distSq(x[1], y[1], x[3], y[3])) {
        return true;
    }

    return false;
}
int mrot[4][4][4][4];
int fun(int x[], int y[], int a[], int b[], int rot[]) {
    if (mrot[rot[0]][rot[1]][rot[2]][rot[3]] != -1)
        return mrot[rot[0]][rot[1]][rot[2]][rot[3]];
    if (isSquare(x, y)) return accumulate(rot, rot + 4, 0);
    int ans = INF;
    fo(i, 4) {
        if (rot[i] < 3) {
            int tx = x[i], ty = y[i];
            x[i] = b[i] - ty + a[i], y[i] = tx - a[i] + b[i];
            rot[i]++;
            ans = min(fun(x, y, a, b, rot), ans);
            x[i] = tx;
            y[i] = ty;
            rot[i]--;
        }
    }
    return mrot[rot[0]][rot[1]][rot[2]][rot[3]] = ans;
}
int main() {
    fastio;
    int n;
    cin >> n;
    fo(i, n) {
        int x[4], y[4], a[4], b[4], rot[4] = {0};
        fo(i, 4) fo(j, 4) fo(k, 4) fo(l, 4) mrot[i][j][k][l] = -1;
        fo(j, 4) { cin >> x[j] >> y[j] >> a[j] >> b[j]; }
        int ans = fun(x, y, a, b, rot);
        cout << (ans == INF ? -1 : ans) << endl;
    }
}