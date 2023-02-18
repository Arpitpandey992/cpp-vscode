const long long M = 1e9 + 7;
const int INF = 2147483647;
const long long INFLL = 9223372036854775807ll;
#pragma region
#include <algorithm>
#include <chrono>
#include <climits>
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
#define endl '\n'
#define nl cout << '\n'
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define tiii tuple<int, int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
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
#define mt make_tuple
#define ff first
#define ss second
#define FIX(number, digits) fixed << setprecision(digits) << number  // use in cout
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fileio                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define fok(i, k, n) for (ll i = k; i < n; i++)
#define Fok(i, k, n) for (ll i = n; i >= k; i--)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = n; i >= 0; i--)
#define CHK(s, k) (s.find(k) != s.end())
#define all(v) v.begin(), v.end()
#define allg(v) v.rbegin(), v.rend()
#define Sort(v) sort(all(v))
#define Sortg(v) sort(allg(v))
#define sz(v) v.size()
#define bs(v, val) binary_search(all(v), val)
#define lb(v, val) lower_bound(all(v), val)
#define ub(v, val) upper_bound(all(v), val)
#define setbits(x) __builtin_popcount(x)

// For quickly defining Multidimentional Vectors
// Use as Vector<dimensions,data_type> vec_name(siz_1,siz_2,...). [Notice Capital 'V'ector].
// Examples - Vector<2,int> a(5,40),
// Vector<3,ll> b(5,5); [Here, it is 3-D vector with third dimention as empty, so use push_back like b[0][1].pb(1) to insert in b[0][1][0]].
template <int D, typename T>
struct Vector : public vector<Vector<D - 1, T>> {
    static_assert(D >= 1, "Vector dimension must be greater than zero!");
    template <typename... Args>
    Vector(int n = 0, Args... args) : vector<Vector<D - 1, T>>(n, Vector<D - 1, T>(args...)) {
    }
};
template <typename T>
struct Vector<1, T> : public vector<T> {
    Vector(int n = 0, const T &val = T()) : vector<T>(n, val) {
    }
};

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//--------------------------------------------------------------------//
// DEBUG STATEMENTS!
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
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
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
// END OF DEBUG STATEMENTS!
//--------------------------------------------------------------------//

// Modular Class
const ll MOD = M;

// Comment the line above and uncomment the line below if problem requires more than 1 MOD
// After uncommenting the below line, declaration of Mint becomes [ Mint<mod> M; ]

// template<ll MOD>
class Mint {
    // WARNING:
    // Be very careful not to use two Mints with different mods for any operation
    // No guarantee of behavior in this case
   public:
    ll val;
    static ll mod_exp(ll a, ll b) {
        ll res = 1;
        a = a % MOD;
        while (b > 0) {
            if (b % 2 == 1) res = (res * a) % MOD;
            b /= 2;
            a = (a * a) % MOD;
        }
        return res;
    }
    static ll gcdExtended(ll a, ll b, ll *x, ll *y) {
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
    static ll modInverse(ll a) {
        ll x, y;
        ll g = gcdExtended(a, MOD, &x, &y);
        g++;
        ll res = (x % MOD);
        if (res < 0) res += MOD;
        return res;
    }
    Mint() { val = 0; }
    Mint(ll x) {
        val = x % MOD;
        if (val < 0) val += MOD;
    }
    Mint &operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return (*this);
    }
    Mint &operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return (*this);
    }
    Mint &operator*=(const Mint &other) {
        val = (val * other.val) % MOD;
        return (*this);
    }
    Mint &operator/=(const Mint &other) {
        val = (val * modInverse(other.val)) % MOD;
        return (*this);
    }
    Mint &operator=(const Mint &other) {
        val = other.val;
        return (*this);
    }
    Mint operator+(const Mint &other) const { return Mint(*this) += other; }
    Mint operator-(const Mint &other) const { return Mint(*this) -= other; }
    Mint operator*(const Mint &other) const { return Mint(*this) *= other; }
    Mint operator/(const Mint &other) const { return Mint(*this) /= other; }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    bool operator<(const Mint &other) const { return val < other.val; }
    bool operator>(const Mint &other) const { return val > other.val; }
    bool operator<=(const Mint &other) const { return val <= other.val; }
    bool operator>=(const Mint &other) const { return val >= other.val; }

    Mint operator++() {
        ++val;
        if (val == MOD) val = 0;
        return (*this);
    }
    Mint operator++(int) {
        val++;
        if (val == MOD) val = 0;
        return Mint(val - 1);
    }
    Mint operator--() {
        --val;
        if (val == -1) val = MOD - 1;
        return (*this);
    }
    Mint operator--(int) {
        val--;
        if (val == -1) val = MOD - 1;
        return Mint(val + 1);
    }

    // ^ has very low precedence, careful!!

    template <typename T>
    Mint &operator^=(const T &other) {
        val = mod_exp(val, other);
        return (*this);
    }
    template <typename T>
    Mint operator^(const T &other) const { return Mint(*this) ^= other; }

    Mint &operator^=(const Mint &other) {
        val = mod_exp(val, other.val);
        return (*this);
    }
    Mint operator^(const Mint &other) const { return Mint(*this) ^= other; }

    template <typename T>
    explicit operator T() { return (T)val; }
    template <typename T>
    friend Mint operator+(T other, const Mint &M) { return Mint(other) + M; }
    template <typename T>
    friend Mint operator-(T other, const Mint &M) { return Mint(other) - M; }
    template <typename T>
    friend Mint operator*(T other, const Mint &M) { return Mint(other) * M; }
    template <typename T>
    friend Mint operator/(T other, const Mint &M) { return Mint(other) / M; }
    template <typename T>
    friend Mint operator^(T other, const Mint &M) { return Mint(other) ^ M; }

    friend std::ostream &operator<<(std::ostream &output, const Mint &M) { return output << M.val; }
    friend std::istream &operator>>(std::istream &input, Mint &M) {
        input >> M.val;
        M.val %= MOD;
        return input;
    }
};
// End of ModInt Class

//--------------------------------------------------------------------//
// Useful Functions
ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }   // divide a by b rounded up
ll floor(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down

unsigned ll rng(unsigned ll l = 0, unsigned ll r = 9223372036854775806ll) {
    mt19937_64 gen(std::random_device{}());
    unsigned ll res = gen();
    return res % (r - l + 1) + l;  // Random no in [l, r].
}
ll modexp(ll a, ll b, ll m = M) {  // Precise Pow() (a^b)%m
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
ll pow2(ll a, ll b) {  // Precise Pow() for integers only
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a);
        b >>= 1;
        a = a * a;
    }
    return res;
}
bool *prime;
int *spf;
void SieveOfEratosthenes(int n = 1e7) {
    prime = new bool[n + 1];
    memset(prime, true, n + 1);
    spf = new int[n + 1];
    fo(i, n + 1) spf[i] = i;
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
                if (spf[i] == i)
                    spf[i] = p;
            }
        }
    }
}

Mint *fac, *facNumInv;
void precomputeNcR(int n = 1e6 + 1) {  // call before using NCR()
    fac = new Mint[n + 1];
    facNumInv = new Mint[n + 1];
    fac[0] = 1;
    for (int i = 1; i < n; i++) fac[i] = i * fac[i - 1];
    facNumInv[n - 1] = 1 / fac[n - 1];
    for (int i = n - 2; i >= 0; i--) facNumInv[i] = (i + 1) * facNumInv[i + 1];
}
Mint NCR(ll a, ll b) {  // nCr Modulo M (M is defined at the top).
    if (b < 0 || b > a) return Mint(0);
    return (fac[a] * facNumInv[b] * facNumInv[a - b]);
}
#pragma endregion
//-------------------------------------------------------------------------------//

class segTree {
    vector<vector<ll>> st;
    vector<vector<bool>> lazy;
    vector<ll> a;
    ll siz, n;

    void build(ll sl, ll sr, ll node, ll bit) {
        if (sl == sr) {
            if (a[sl] & (1 << bit))
                st[bit][node] = 1;
            else
                st[bit][node] = 0;
            return;
        }
        ll mid = sl + (sr - sl) / 2;
        build(sl, mid, node * 2 + 1, bit);
        build(mid + 1, sr, node * 2 + 2, bit);
        st[bit][node] = st[bit][node * 2 + 1] + st[bit][node * 2 + 2];
    }

    void rangeUpd(ll sl, ll sr, ll node, ll l, ll r, ll bit) {
        if (sl >= l && sr <= r) {
            lazy[bit][node] = !lazy[bit][node];
            // st[bit][node] = sr - sl + 1 - st[bit][node];
            // if (sl != sr) {
            //     lazy[bit][node * 2 + 1] = !lazy[bit][node * 2 + 1];
            //     lazy[bit][node * 2 + 2] = !lazy[bit][node * 2 + 2];
            // }
        }
        if (lazy[bit][node]) {
            st[bit][node] = sr - sl + 1 - st[bit][node];
            if (sl != sr) {
                lazy[bit][node * 2 + 1] = !lazy[bit][node * 2 + 1];
                lazy[bit][node * 2 + 2] = !lazy[bit][node * 2 + 2];
            }
            lazy[bit][node] = false;
        }

        if (sr < l || sl > r || sl >= l && sr <= r) return;

        ll mid = sl + (sr - sl) / 2;
        rangeUpd(sl, mid, node * 2 + 1, l, r, bit);
        rangeUpd(mid + 1, sr, node * 2 + 2, l, r, bit);
        st[bit][node] = st[bit][node * 2 + 1] + st[bit][node * 2 + 2];
    }
    ll qry(ll sl, ll sr, ll node, ll l, ll r, ll bit) {
        if (lazy[bit][node]) {
            st[bit][node] = sr - sl + 1 - st[bit][node];
            if (sl != sr) {
                lazy[bit][node * 2 + 1] = !lazy[bit][node * 2 + 1];
                lazy[bit][node * 2 + 2] = !lazy[bit][node * 2 + 2];
            }
            lazy[bit][node] = false;
        }

        if (sr < l || sl > r) return 0;

        if (sl >= l && sr <= r)
            return st[bit][node];
        ll mid = sl + (sr - sl) / 2;
        return qry(sl, mid, node * 2 + 1, l, r, bit) + qry(mid + 1, sr, node * 2 + 2, l, r, bit);
    }

   public:
    segTree(vector<ll> a) {
        this->a = a;
        this->n = a.size();
        lazy.resize(31, vector<bool>(4 * n + 1, 0));
        st.resize(31, vector<ll>(4 * n + 1, 0));
        siz = 4 * n;
        for (ll i = 0; i < 31; i++)
            build(0, n - 1, 0, i);
    }
    void rangeUpdate(ll l, ll r, ll k) {
        for (ll bit = 0; bit < 31; bit++) {
            if (k & (1 << bit))
                rangeUpd(0, n - 1, 0, l, r, bit);
        }
    }
    ll query(ll l, ll r) {
        ll ans = 0;
        for (ll bit = 0; bit < 31; bit++) {
            ll ct = qry(0, n - 1, 0, l, r, bit);
            ans += (1 << bit) * ct;
        }
        return ans;
    }
};

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    fo(i, n) cin >> a[i];
    segTree SEG(a);
    ll q;
    cin >> q;
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll l, r;
            cin >> l >> r;
            cout << SEG.query(l - 1, r - 1) << endl;
        } else {
            ll l, r, k;
            cin >> l >> r >> k;
            SEG.rangeUpdate(l - 1, r - 1, k);
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
    fastio;
#endif
    int tes = 1;
    // cin >> tes;
    for (int t = 1; t <= tes; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}