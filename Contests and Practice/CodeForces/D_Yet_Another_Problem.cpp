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

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n + 1);
    fok(i, 1, n + 1) cin >> a[i];
    vll pref(n + 1, 0);
    vll sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = a[i] ^ pref[i - 1];
        sum[i] = a[i] + sum[i - 1];
    }

    vector<map<int, vector<int>>> m(2);
    fok(i, 0, n) {
        m[i & 1][pref[i]].pb(i);
    }

    auto chk1 = [&](int l, int r) {
        if ((pref[r] ^ pref[l - 1] == 0)) {
            if (a[r] == 0 || a[l] == 0 || ((r - l + 1) & 1)) {
                return true;
            }
        }
        return false;
    };

    while (q--) {
        ll l, r;
        cin >> l >> r;
        // handle zero case
        if (sum[r] - sum[l - 1] == 0) {
            cout << 0 << endl;
            continue;
        }
        // handle 1
        if (chk1(l, r)) {
            cout << 1 << endl;
            continue;
        }
        // testing for 2
        int bit = r & 1;
        auto &v = m[!bit][pref[r]];
        auto id = ub(v, l - 1);
        if (id == v.end() || *id >= r) {
            cout << -1 << endl;
            continue;
        }
        int j = *id;
        if (pref[j] ^ pref[l - 1] == 0) {
            cout << 2 << endl;
            continue;
        }
        v = m[!bit][pref[l - 1]];
        id = ub(v, l - 1);
        if (id == v.end() || *id > r) {
            cout << -1 << endl;
            continue;
        }
        j = *id;
        if (pref[r] ^ pref[j - 1] == 0) {
            cout << 2 << endl;
            continue;
        }
        cout << -1 << endl;
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