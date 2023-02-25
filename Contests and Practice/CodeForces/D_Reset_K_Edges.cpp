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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    vector<int> par(n);
    par[0] = 0;
    fo(i, n - 1) {
        int p;
        cin >> p;
        par[i + 1] = p - 1;
        adj[p - 1].pb(i + 1);
    }
    // vector<int> maxDep(n);
    // auto dfs2 = [&](int i, auto &dfs2) -> int {
    //     int ans = 0;
    //     for (auto &x : adj[i]) {
    //         ans = max(ans, 1 + dfs2(x, dfs2));
    //     }
    //     return maxDep[i] = ans;
    // };
    // dfs2(0, dfs2);
    // auto dfs = [&](int i, int cur, int k, auto &dfs) -> int {
    //     int ans = 0;
    //     if (cur > k) {
    //         cur = 1;
    //         ans++;
    //     }
    //     if (maxDep[i] + 1 <= k && cur + maxDep[i] > k) {
    //         ans++;
    //         return ans;
    //     }
    //     for (auto &x : adj[i]) {
    //         ans += dfs(x, cur + 1, k, dfs);
    //     }
    //     return ans;
    // };
    auto operations = [&](int k) -> int {
        vector<int> out(n, 0);
        fo(i, n) out[i] = adj[i].size();
        queue<pair<int, int>> q;
        vector<int> md(n, 0);
        fo(i, n) if (out[i] == 0) {
            q.push({i, 0});
        }
        int ans = 0;
        while (q.size()) {
            auto [i, dep] = q.front();
            q.pop();
            if (dep + 1 == k && par[i] != 0) {
                ans++;
                out[par[i]]--;
            } else {
                out[par[i]]--;
                md[par[i]] = max(md[par[i]], dep + 1);
            }
            if (out[par[i]] == 0)
                q.push({par[i], md[par[i]]});
        }
        return ans;
    };

    int l = 1, r = n + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        // int ops = dfs(0, 0, mid, dfs);
        int ops = operations(mid);
        if (ops <= k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
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