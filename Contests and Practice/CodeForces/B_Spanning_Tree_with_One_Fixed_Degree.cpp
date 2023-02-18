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
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> ed;
    vector<int> adj[n];
    vector<int> in(n, 0);
    fo(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ed.pb({u, v});
        adj[u].pb(v);
        adj[v].pb(u);
        in[u]++;
        in[v]++;
    }
    if (in[0] < k) {
        cout << "NO\n";
        return;
    }
    DSU dsu1(n), dsu2(n);
    for (auto &[u, v] : ed) {
        if (u != 0 && v != 0)
            dsu1.uni(u, v);
    }
    vb conn(n, false);
    conn[0] = true;
    vector<pair<int, int>> ans;
    for (auto &x : adj[0]) {
        if (k == 0) break;
        int p = dsu1.fin(x);
        if (conn[p])
            continue;
        conn[p] = true;
        k--;
        dsu2.uni(0, x);
        ans.pb({0, x});
    }
    for (auto &x : adj[0]) {
        if (k == 0) break;
        if (dsu2.fin(x) == dsu2.fin(0)) continue;
        k--;
        dsu2.uni(0, x);
        ans.pb({0, x});
    }
    if (k != 0) {
        cout << "NO\n";
        return;
    }
    for (auto &[u, v] : ed) {
        if (u != 0 && v != 0 && dsu2.fin(u) != dsu2.fin(v)) {
            dsu2.uni(u, v);
            ans.pb({u, v});
        }
    }
    for (int i = 0; i < n; i++) {
        if (dsu2.fin(i) != dsu2.fin(0)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (auto &[u, v] : ans)
        cout << u + 1 << " " << v + 1 << endl;
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