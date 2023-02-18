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
#define pil pair<int, long long>
#define pli pair<long long, int>
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
#define vpil vector<pil>
#define vpli vector<pli>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define FIX(number, digits) fixed << setprecision(digits) << number  // use in cout
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fileio                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#pragma endregion
//-------------------------------------------------------------------------------//
#define N 100005
ll n, m;
vll a(N);
vll adj[N];
vll rev[N];
vll ord;
vll DP(N, -1);

void dfs(ll i, vb &vis) {
    vis[i] = true;
    for (auto &x : adj[i]) {
        if (!vis[x]) {
            dfs(x, vis);
        }
    }
    ord.pb(i);
}
void dfs2(ll i, vb &vis, vll &fam, ll &curFam) {
    fam[i] = curFam;
    vis[i] = true;
    for (auto &x : rev[i]) {
        if (!vis[x]) {
            dfs2(x, vis, fam, curFam);
        }
    }
}

ll dp(ll i, vector<ll> adjj[], vector<ll> &a) {
    if (DP[i] != -1) return DP[i];
    ll ans = a[i];
    for (auto &x : adjj[i]) {
        ans = max(ans, a[i] + dp(x, adjj, a));
    }
    return DP[i] = ans;
}

void solve() {
    cin >> n >> m;
    fo(i, n) cin >> a[i];
    vpll ed;
    fo(i, m) {
        ll u, v;
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
        rev[v - 1].pb(u - 1);
        ed.pb({u - 1, v - 1});
    }
    vb vis(n, false);
    fo(i, n) {
        if (!vis[i]) {
            dfs(i, vis);
        }
    }
    vis.clear();
    vis.resize(n, false);
    vll fam(n, -1);
    ll curFam = 0;
    while (ord.size()) {
        auto i = ord.back();
        ord.pob();
        if (vis[i]) continue;
        dfs2(i, vis, fam, curFam);
        curFam++;
    }
    vll b(curFam + 1);
    fo(i, n) {
        b[fam[i]] += a[i];
    }
    vector<ll> adj2[curFam + 1];
    for (auto &[u, v] : ed) {
        if (fam[u] != fam[v])
            adj2[fam[u]].pb(fam[v]);
    }
    ll ans = 0;
    fo(i, curFam) ans = max(ans, dp(i, adj2, b));
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