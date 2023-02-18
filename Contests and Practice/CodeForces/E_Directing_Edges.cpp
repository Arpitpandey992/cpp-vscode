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

class DSU {
   private:
    int n;  // Elements present are from 0 to n-1
    vector<int> par, rank;

   public:
    int totalSets;
    DSU(int n) {
        this->n = n;
        totalSets = n;
        par.resize(n, -1);
        rank.resize(n, 0);
        iota(par.begin(), par.end(), 0);
    }
    int fin(int a) {
        if (par[a] == a)
            return a;
        return par[a] = fin(par[a]);
    }
    bool uni(int a, int b) {
        a = fin(a);
        b = fin(b);
        if (a == b) return false;
        if (rank[a] < rank[b])
            par[a] = b;
        else if (rank[b] < rank[a])
            par[b] = a;
        else {
            rank[a]++;
            par[b] = a;
        }
        totalSets--;
        return true;
    }
    void clear() {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
        totalSets = n;
    }
};

//------------------------------------------END OF TEMPLATE-------------------------------------------

bool hasCycle(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> vis(n, 0);

    auto dfs = [&](int i, auto &dfs) -> bool {
        vis[i] = 1;
        for (auto &x : adj[i]) {
            if (vis[x] == 1) return true;
            if (vis[x] == 0 && dfs(x, dfs))
                return true;
        }
        vis[i] = 2;
        return false;
    };

    for (int i = 0; i < n; i++) {
        if (vis[i] == 0 && dfs(i, dfs))
            return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> undir, dir;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        u--;
        v--;
        if (t == 0) {
            undir.push_back({u, v});
        } else {
            adj[u].pb(v);
            dir.push_back({u, v});
        }
    }
    // if (hasCycle(adj)) {
    //     cout << "NO\n";
    //     return;
    // }

    vector<int> in(n, 0);
    for (auto &[u, v] : dir)
        in[v]++;
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0)
            q.push(i);
    }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        topo.pb(t);
        for (auto &x : adj[t]) {
            in[x]--;
            if (in[x] == 0) {
                q.push(x);
            }
        }
    }
    if (topo.size() != n) {
        cout << "NO\n";
        return;
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        pos[topo[i]] = i;
    cout << "YES\n";
    for (auto &[x, y] : dir) {
        cout << x + 1 << " " << y + 1 << endl;
    }
    for (auto &[x, y] : undir) {
        if (pos[x] < pos[y])
            cout << x + 1 << " " << y + 1 << endl;
        else
            cout << y + 1 << " " << x + 1 << endl;
    }
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