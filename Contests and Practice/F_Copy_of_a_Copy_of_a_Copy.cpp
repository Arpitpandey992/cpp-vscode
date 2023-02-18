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

bool chk1(vvi &a, int i, int j) {
    int ct = 0;
    if (a[i - 1][j]) ct++;
    if (a[i + 1][j]) ct++;
    if (a[i][j - 1]) ct++;
    if (a[i][j + 1]) ct++;
    if (a[i][j]) ct++;
    if (ct == 0 || ct == 5)
        return true;
    return false;
}

vector<pair<int, int>> getChange(vvi &a, vvi &b) {
    vector<pair<int, int>> ans;
    int n = a.size(), m = a[0].size();
    for (int i = 1; i + 1 < n; i++) {
        for (int j = 1; j + 1 < m; j++) {
            if (a[i][j] != b[i][j])
                ans.pb({i, j});
        }
    }
    return ans;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    k++;
    vvvi a(k);
    fo(i, k) {
        a[i].resize(n, vi(m));
        fo(j, n) {
            string s;
            cin >> s;
            fo(kk, m) {
                a[i][j][kk] = s[kk] - '0';
            }
        }
    }
    vi filled(k, 0);
    fo(idx, k) {
        for (int i = 1; i + 1 < n; i++) {
            for (int j = 1; j + 1 < m; j++) {
                if (chk1(a[idx], i, j))
                    filled[idx]++;
            }
        }
    }
    vector<int> indices(k);
    fo(i, k) indices[i] = i;
    sort(all(indices), [&](auto &i, auto &j) {
        return filled[i] < filled[j];
    });
    cout << indices[0] + 1 << endl;
    vector<tuple<int, int, int>> ans;
    for (int idx = 0; idx + 1 < k; idx++) {
        int i = indices[idx], j = indices[idx + 1];
        vector<pair<int, int>> change = getChange(a[i], a[j]);
        for (auto &[x, y] : change) {
            ans.push_back({1, x + 1, y + 1});
        }
        ans.push_back({2, j + 1, -1});
    }
    cout << ans.size() << endl;
    for (auto &[typ, x, y] : ans) {
        if (typ == 1)
            cout << typ << " " << x << " " << y << endl;
        else
            cout << typ << " " << x << endl;
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