const long long M = 1e9 + 7;
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

#pragma endregion Template End
//-----------------------------------------UTILITY FUNCTIONS------------------------------------------
inline ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }   // divide a by b rounded up
inline ll floor(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
//------------------------------------------END OF TEMPLATE-------------------------------------------

ll a, b, c, d;
map<tuple<int, int, int>, pii> DP;
pii dp(ll i, ll cur1, ll cur2, vll &fac) {
    if (cur1 > c || cur2 > d) return {-1, -1};
    if (i == fac.size()) {
        ll k1 = ceil(a + 1, cur1);
        ll k2 = ceil(b + 1, cur2);
        if (k1 * cur1 <= c && k2 * cur2 <= d)
            return {cur1 * k1, cur2 * k2};
        return {-1, -1};
    }
    if (DP.contains(mt(i, cur1, cur2)))
        return DP[mt(i, cur1, cur2)];

    auto ans1 = dp(i + 1, cur1 * fac[i], cur2, fac);
    if (ans1.ff != -1) return DP[mt(i, cur1, cur2)] = ans1;
    auto ans2 = dp(i + 1, cur1, cur2 * fac[i], fac);
    return DP[mt(i, cur1, cur2)] = ans2;
}

void solve() {
    cin >> a >> b >> c >> d;
    map<int, int> f;
    ll n1 = a, n2 = b;
    for (int i = 2; i * i <= n1; i++) {
        while (n1 % i == 0) {
            f[i]++;
            n1 /= i;
        }
    }
    if (n1 > 1)
        f[n1]++;
    for (int i = 2; i * i <= n2; i++) {
        while (n2 % i == 0) {
            f[i]++;
            n2 /= i;
        }
    }
    if (n2 > 1)
        f[n2]++;
    vector<ll> fac;
    for (auto [who, how] : f) {
        while (how--)
            fac.pb(who);
    }
    DP.clear();
    auto ans = dp(0, 1, 1, fac);
    cout << ans.ff << " " << ans.ss << endl;
}

int main() {
#ifdef ONLINE_JUDGE
    fastio;
#endif
    ll tes = 1;
    cin >> tes;
    for (ll t = 1; t <= tes; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}