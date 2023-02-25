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

ll nc2(ll n) {
    if (n <= 0) return 0;
    return (n * (n + 1)) / 2;
}

void solve() {
    int n;
    cin >> n;
    vll a(n), b(n);
    vll pos1(n), pos2(n);
    fo(i, n) {
        cin >> a[i];
        a[i]--;
        pos1[a[i]] = i;
    }
    fo(i, n) {
        cin >> b[i];
        b[i]--;
        pos2[b[i]] = i;
    }
    ll l = min(pos1[0], pos2[0]);
    ll r = max(pos1[0], pos2[0]);
    ll ans = 0;
    ans += nc2(l) + nc2(n - 1 - r) + nc2(r - l - 1);
    ll cur = 1;

    auto between = [&](ll i) -> bool {
        return i >= l && i <= r;
    };
    while (cur < n) {
        ll p1 = min(pos1[cur], pos2[cur]);
        ll p2 = max(pos1[cur], pos2[cur]);
        if (between(p1) || between(p2)) {
            l = min(l, p1);
            r = max(r, p2);
            cur++;
            continue;
        }
        if (p1 <= l && p2 >= r) {
            ll lef = max(0ll, l - p1), rig = max(0ll, p2 - r);
            ans += lef * rig;
            l = p1;
            r = p2;
        } else if (p2 <= l) {
            ans += (l - p2) * (n - r);
            l = p1;
        } else {
            ans += (p1 - r) * (l + 1);
            r = p2;
        }
        cur++;
    }
    cout << ans + 1 << endl;
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