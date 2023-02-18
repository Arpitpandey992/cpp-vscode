const long long M = 998244353;
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
#define tiii tuple<int, int, int>
#define tlll tuple<ll, ll, ll>
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
#define sz(v) v.size()
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#pragma endregion
//-----------------------------------------UTILITY FUNCTIONS------------------------------------------
inline ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }   // divide a by b rounded up
inline ll floor(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
//------------------------------------------END OF TEMPLATE-------------------------------------------
ll n, m;
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
Mint pref(ll i, ll j) {
    Mint ans = 0;
    Mint one = ceil(i, 2), two = floor(i, 2);
    Mint c1 = ceil(j, 2), c2 = floor(j, 2);
    // 1,3,... will get ceil terms, 2,4,..will floor terms.
    ans = (ans + one * ((c1 * (Mint(1) + (c1 - 1)))));
    ans = (ans + two * ((c2 * (Mint(2) + (c2 - 1)))));

    ans = (ans + Mint(m) * c1 * ((one * ((one - 1)))));
    ans = (ans + Mint(m) * c2 * ((two * (Mint(1) + (two - 1)))));
    return Mint(ans);
}

void solve() {
    cin >> n >> m;
    ll q;
    cin >> q;
    while (q--) {
        ll a, b, c, d;
        cin >> a >> c >> b >> d;
        Mint ans = pref(c, d);
        if (b > 1) ans = (ans - pref(c, b - 1));
        if (a > 1) ans = (ans - pref(a - 1, d));
        if (b > 1 && a > 1) ans += pref(a - 1, b - 1);
        cout << ans << endl;
    }
}

int main() {
#ifdef ONLINE_JUDGE
    fastio;
#endif
    ll tes = 1;
    // cin >> tes;
    for (ll t = 1; t <= tes; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}