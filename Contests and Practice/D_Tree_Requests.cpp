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
const int MaxDepth = 500005;

vector<pair<int, int>> nodes[MaxDepth];
vector<int> ct[MaxDepth];
vector<int> adj[MaxDepth];
int in[MaxDepth], out[MaxDepth], dep[MaxDepth];

bool valid(int &ct) {
    int bitCount = __builtin_popcount(ct);
    return bitCount <= 1;
}
void solve() {
    int n, m;
    cin >> n >> m;
    fok(i, 1, n) {
        int p;
        cin >> p;
        p--;
        adj[p].pb(i);
    }
    string s;
    cin >> s;
    auto dfs1 = [&](int i, int cur, auto &dfs1) -> int {
        dep[i] = cur;
        int mx = 1;
        for (auto &x : adj[i]) {
            mx = max(mx, 1 + dfs1(x, cur + 1, dfs1));
        }
        return mx;
    };
    int maxDepth = dfs1(0, 1, dfs1) + 1;
    auto dfs = [&](int i, int &timer, auto &dfs) -> void {
        nodes[dep[i]].push_back({timer, i});
        in[i] = timer;
        timer++;
        for (auto &x : adj[i])
            dfs(x, timer, dfs);
        out[i] = timer;
        timer++;
    };
    {
        int timer = 0;
        dfs(0, timer, dfs);
    }
    for (int depth = 1; depth < maxDepth; depth++) {
        auto &vec = nodes[depth];
        int count = 0;
        for (auto &[timer, node] : vec) {
            int c = s[node] - 'a';
            count ^= (1 << c);
            ct[depth].push_back(count);
        }
    }
    fo(qq, m) {
        int v, h;
        cin >> v >> h;
        v--;
        auto &vec = nodes[h];
        int IN = in[v], OUT = out[v];
        auto i = lb(vec, mp(IN, -1)) - vec.begin();
        auto j = ub(vec, mp(OUT, INF)) - vec.begin() - 1;
        if (i <= j) {
            int ctq = ct[h][j];
            if (i - 1 >= 0) {
                ctq ^= ct[h][i - 1];
            }
            if (valid(ctq))
                cout << "Yes\n";
            else
                cout << "No\n";
        } else {
            cout << "Yes\n";
        }
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