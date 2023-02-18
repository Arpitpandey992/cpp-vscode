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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    fo(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }
    int lef = -1, rig = -1, len = 0;
    auto dfs = [&](int i, int par, auto &dfs) -> pair<int, int> {
        vector<pair<int, int>> chil = {{0, i}};
        for (auto &x : adj[i]) {
            if (x == par) continue;
            auto [dis, who] = dfs(x, i, dfs);
            chil.push_back({dis + 1, who});  // at what distance and who.
        }
        Sortg(chil);
        if (chil.size() > 1 && chil[0].ff + chil[1].ff > len) {
            len = chil[0].ff + chil[1].ff;
            lef = chil[0].ss;
            rig = chil[1].ss;
        }
        return chil[0];
    };
    dfs(0, -1, dfs);  // getting diametric endpoints
    vector<int> parent(n, -1);
    auto getDiameter = [&](int i, int par, auto &getDiameter) -> void {
        parent[i] = par;
        for (auto &x : adj[i]) {
            if (x != par)
                getDiameter(x, i, getDiameter);
        }
    };
    getDiameter(lef, -1, getDiameter);
    queue<pair<int, int>> q;
    vector<bool> vis(n, false);
    int cur = rig;
    while (cur != lef) {
        vis[cur] = true;
        q.push({cur, 0});
        cur = parent[cur];
    }
    vis[cur] = true;
    q.push({cur, 0});
    int mxdis = -1, thirdPoint = -1;
    while (q.size()) {
        auto &[t, d] = q.front();
        q.pop();
        if (d > mxdis && t != lef && t != rig) {
            mxdis = d;
            thirdPoint = t;
        }
        for (auto &x : adj[t]) {
            if (!vis[x]) {
                q.push({x, d + 1});
                vis[x] = true;
            }
        }
    }
    cout << len + mxdis << endl
         << lef + 1 << " " << rig + 1 << " " << thirdPoint + 1 << endl;
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