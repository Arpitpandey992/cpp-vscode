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

// Useful Functions
ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }   // divide a by b rounded up
ll floor(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down

#pragma endregion

int n, m;
vector<vector<int>> adj;

int dfs(int i, int par, int height, vector<int> &h, vector<int> &DP) {
    h[i] = height;
    DP[i] = height;
    for (auto &x : adj[i]) {
        if (x == par) continue;
        if (h[x] != -1) {
            DP[i] = min(DP[i], h[x]);
        } else {
            DP[i] = min(DP[i], dfs(x, i, height + 1, h, DP));
        }
    }
    return DP[i];
}

pair<vi, vi> find_bridges() {
    vector<int> h(n, -1);
    vector<int> DP(n);
    dfs(0, -1, 0, h, DP);
    return {DP, h};
}

class DSU {
    vector<int> par;

   public:
    DSU(int n) {
        par.resize(n);
        iota(all(par), 0);
    }
    int find(int x) {
        return par[x] = (par[x] == x ? x : find(par[x]));
    }
    void uni(int x, int y) {
        par[find(y)] = find(x);
    }
};

void solve() {
    cin >> n >> m;
    vector<tiii> ed;
    adj.clear();
    adj.resize(n);
    vi col(m, 0);
    fo(i, m) {
        int u, v;
        cin >> u >> v;
        ed.pb({i, min(u - 1, v - 1), max(u - 1, v - 1)});
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }
    DSU dsu(n);
    int left = m - (n - 1);
    vb done(m, false);
    while (left > 0) {
        auto [DP, h] = find_bridges();
        for (auto &[id, u, v] : ed) {
            if (h[u] > h[v]) swap(u, v);
            if (done[id]) continue;
            if (DP[v] <= DP[u]) {
                if (dsu.find(u) == dsu.find(v)) continue;
                dsu.uni(u, v);
                done[id] = true;
                left--;
                col[id] = 1;
                for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                    if (*it == v) {
                        adj[u].erase(it++);
                        break;
                    }
                }
                for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
                    if (*it == u) {
                        adj[v].erase(it++);
                        break;
                    }
                }
                break;
            }
        }
    }
    fo(i, m) cout << col[i];
    nl;
}

int32_t main() {
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