const long long M = 998244353;
const int INF = 2147483647;
const long long INFLL = 9223372036854775807ll;
#pragma region Template Start
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
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tlll = tuple<ll, ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vpii = vector<pii>;
using vpll = vector<pll>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define endl '\n'
#define nl cout << '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define FIX(number, digits) fixed << setprecision(digits) << number  // use in cout
#define fok(i, k, n) for (ll i = k; i < n; i++)
#define Fok(i, k, n) for (ll i = n; i >= k; i--)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = n; i >= 0; i--)
#define CHK(s, k) (s.find(k) != s.end())
#define all(v) v.begin(), v.end()
#define allg(v) v.rbegin(), v.rend()
#define Sort(v) sort(all(v))
#define Sortg(v) sort(allg(v))
#define sz(v) (static_cast<ll>(v.size()))
#define bs(v, val) binary_search(all(v), val)
#define lb(v, val) lower_bound(all(v), val)
#define ub(v, val) upper_bound(all(v), val)
#define setbits(x) __builtin_popcount(x)
#define start_clock() auto start_time = std::chrono::high_resolution_clock::now()
#define measure()                                              \
    auto end_time = std::chrono::high_resolution_clock::now(); \
    cerr << (end_time - start_time) / std::chrono::milliseconds(1) << "ms" << endl

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fileio                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)

#pragma endregion Template End
/*-----------------------------------------UTILITY FUNCTIONS------------------------------------------*/
inline ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }   // divide a by b rounded up
inline ll floor(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
/*------------------------------------------END OF TEMPLATE-------------------------------------------*/

#pragma region Modular class
const ll MOD = M;
// template <size_t MOD = M>
class Mint {
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
#pragma endregion Modular Class End

const int NcRLimit = 1e6 + 2;
array<Mint, NcRLimit> fac, facNumInv;
void precomputeNcR(const int &n = NcRLimit) {  // call before using NCR()
    fac[0] = 1;
    for (int i = 1; i < n; i++) fac[i] = Mint(i) * fac[i - 1];
    facNumInv[n - 1] = Mint(1) / fac[n - 1];
    for (int i = n - 2; i >= 0; i--) facNumInv[i] = Mint(i + 1) * facNumInv[i + 1];
}
Mint ncr(const int &a, const int &b) {
    if (b < 0 || b > a) return Mint(0);
    return (fac[a] * facNumInv[b] * facNumInv[a - b]);
}

void solve() {
    int n;
    cin >> n;
    Mint ans = 1;
    fo(i, n / 3) {
        vll a(3);
        fo(j, 3) {
            cin >> a[j];
        }
        Sortg(a);
        ll mx = a[0] + a[1];
        ll ways = 0;
        for (int i = 0; i < 3; i++) {
            if (a[i] + a[(i + 1) % 3] == mx)
                ways++;
        }
        ans *= ways;
    }
    ll groups = n / 3;
    ll choose = groups / 2;
    ans *= ncr(groups, choose);
    cout << ans << endl;
}

int main() {
#ifdef ONLINE_JUDGE
    fastio;
#endif
    precomputeNcR(3e5 + 1);
    ll tes = 1;
    // cin >> tes;
    for (ll t = 1; t <= tes; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}