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
    int n, e;
    int p, b;
    cin >> n >> e >> p >> b;
    vector<vector<int>> adj(n);
    vector<bool> sp(n, false), token(n, false);
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        token[x - 1] = true;
    }
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        sp[x - 1] = true;
    }
    fo(i, e) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }
    sp[0] = true;
    vb vis(n, false);
    queue<pii> q;
    vis[0] = true;
    int reqDis = INF, firstToken = -1;
    q.push({0, 0});
    while (q.size()) {
        auto &[t, dis] = q.front();
        q.pop();
        if (token[t]) {
            reqDis = dis;
            firstToken = t;
            break;
        }
        if (!sp[t]) {
            continue;
        }
        for (auto &x : adj[t]) {
            if (!vis[x]) {
                q.push({x, dis + 1});
                vis[x] = true;
            }
        }
    }
    if (firstToken == -1) {
        cout << "NO\n";
        return;
    }
    vi tokens;
    fo(i, n) {
        if (i != firstToken && token[i]) {
            tokens.pb(i);
        }
    }
    reqDis--;
    for (auto &token : tokens) {
        int mx = 0;
        bool done = false;
        auto dfs = [&](auto &i, int dis, int par, auto &dfs) -> void {
            if (done)
                return;
            mx = max(mx, dis);
            for (auto &x : adj[i]) {
                if (x == par && sp[x]) {
                    done = true;
                    return;
                }
                if (sp[x]) {
                    dfs(x, dis + 1, i, dfs);
                    if (done)
                        return;
                }
            }
        };
        dfs(token, 0, -1, dfs);
        if (done) {
            cout << "YES\n";
            return;
        }
        reqDis -= mx;
    }
    if (reqDis > 0)
        cout << "NO\n";
    else
        cout << "YES\n";
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