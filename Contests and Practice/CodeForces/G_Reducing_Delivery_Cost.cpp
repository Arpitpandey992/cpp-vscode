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

#pragma endregion
//------------------------------------------------------------------------------------------------
inline ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }   // divide a by b rounded up
inline ll floor(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
//------------------------------------------------------------------------------------------------

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<tiii>> adj(n);
    vector<tiii> edges;
    fo(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].pb({v - 1, w, i});
        adj[v - 1].pb({u - 1, w, i});
        edges.pb({u - 1, v - 1, w});
    }
    vpii q;
    fo(i, k) {
        int a, b;
        cin >> a >> b;
        q.pb({a - 1, b - 1});
    }

    vector<int> ct(m, 0);
    ll tot = 0;
    auto djikstra = [&](int st, int ed) {
        vector<int> dis(n, INF / 4);
        dis[st] = 0;
        priority_queue<pair<int, int>, vpii, greater<pii>> q;
        q.push({0, st});
        while (q.size()) {
            auto [d, t] = q.top();
            q.pop();
            if (d != dis[t]) continue;
            for (auto &[x, w, id] : adj[t]) {
                if (dis[x] > d + w) {
                    dis[x] = d + w;
                    q.push({dis[x], x});
                }
            }
        }
        return dis;
    };
    vector<vector<vector<int>>> dis(k, vvi(2));
    fo(i, k) {
        dis[i][0] = djikstra(q[i].ff, q[i].ss);
        dis[i][1] = djikstra(q[i].ss, q[i].ff);
    }
    ll ans = INF;
    fo(i, m) {
        auto &[u, v, w] = edges[i];
        ll cur = 0;
        fo(j, k) {
            auto &[st, ed] = q[j];
            auto &dist = dis[j];
            cur += min({dist[0][ed], dist[0][u] + dist[1][v], dist[0][v] + dist[1][u]});
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
}

int32_t main() {
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