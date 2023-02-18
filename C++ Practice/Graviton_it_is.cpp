const long long M = 1e9 + 7;
const int INF = 2147483647;
const long long INFLL = 9223372036854775807ll;
#pragma region Template Start
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

#pragma region Debug Statements
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
template <typename T>
void __print(priority_queue<T> &q) {
    vector<T> v;
    while (q.size()) {
        v.pb(q.top());
        q.pop();
    }
    __print(v);
    for (auto &i : v) q.push(i);
}
template <typename T>
void __print(stack<T> &s) {
    vector<T> v;
    while (s.size()) {
        v.pb(s.top());
        s.pop();
    }
    reverse(all(v));
    __print(v);
    for (auto &i : v) s.push(i);
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
#pragma endregion Debug end

#pragma region Modular class
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
#pragma endregion Modular Class End

#pragma endregion Template End
/*-----------------------------------------UTILITY FUNCTIONS------------------------------------------*/
inline ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }   // divide a by b rounded up
inline ll floor(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
/*------------------------------------------END OF TEMPLATE-------------------------------------------*/

template <typename T>
class CustomPointer {
    T *m_pointer;
    static unordered_map<T *, int> counter;

   public:
    CustomPointer(T *ptr = NULL) {
        m_pointer = ptr;
        counter[m_pointer]++;
    }
    T *operator->() {
        return m_pointer;
    }
    T &operator*() {
        return *m_pointer;
    }
    ~CustomPointer() {
        counter[m_pointer]--;
        if (counter[m_pointer] == 0) {
            delete m_pointer;
            counter.erase(m_pointer);
        }
    }
};
template <typename T>
unordered_map<T *, int> CustomPointer<T>::counter;

int main() {
    int *x = new int(45);
    int *y = new int(56);
    int *ptr = x;
    CustomPointer test(x);
    {
        CustomPointer p1(x), p2(x), p3(x);
        cout << *p1 << endl;
    }
    cout << *ptr << endl;
    {
        CustomPointer p4(y), p5(y);
    }
    int t = 45;
    {
        shared_ptr<int> p7(&t);
    }
    return 0;
}