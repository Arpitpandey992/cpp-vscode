#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <iostream>
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
ll modexp(ll a, ll b, ll c = M) {  //Precise Pow() (a^b)%c
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
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
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
ll* fac;
void SieveOfEratosthenes(int n = 1e7 + 1) {
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
void factorial(int N = 1e6 + 1, int p = M) {
    fac = new ll[N + 1];
    fac[0] = 1;
    for (int i = 1; i <= N; ++i)
        fac[i] = fac[i - 1] * i, fac[i] %= p;
}
ll ncrmodp(ll n, ll r, ll p = M) {
    if (r > n || r < 0) return 0;
    if (r == 0) return 1;
    return fac[n] * modinv(fac[r], p) % p * modinv(fac[n - r], p) % p;
}
#pragma endregion

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
string pet[3][2] = {{"lios", "liala"}, {"etr", "etra"}, {"initis", "inites"}};
pii which(string s) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            auto& t = pet[i][j];
            if (s.size() >= t.size()) {
                if (s.substr(s.size() - t.size()) == t)
                    return {i, j};
            }
        }
    }
    return {3, 2};
}

void solve() {
    string s;
    getline(cin, s);
    vector<string> a;
    stringstream ss(s);
    bool flag = true;
    while (ss >> s) {
        if (which(s).ff == 3) {
            cout << "NO\n";
            return;
        }
        a.push_back(s);
    }
    if (a.size() == 1) {
        cout << "YES\n";
        return;
    }
    int gen = which(s).ss;
    int cur = -1;
    for (auto& s : a) {
        auto [gram, gender] = which(s);
        if ((gender != gen) ||
            (cur < 1 && gram == 2) ||
            (cur == 1 && gram == 1) ||
            (gram < cur)) {
            cout << "NO\n";
            return;
        }
        cur = gram;
    }
    if (cur == 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}
