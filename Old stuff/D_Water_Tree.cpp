const long long M = 1e9 + 7;
const int INF = 2147483647;
const long long INFLL = 9223372036854775807ll;
#pragma region Template Start
#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
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

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

#pragma region Debug Statements
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
template <typename T>
void __print(priority_queue<T> &q) {
    vector<T> v;
    while (q.size()) {
        v.pb(q.top());
        q.pop();
    }
    __print(v);
    for (auto &i : v) q.push(i);
}
template <typename T>
void __print(stack<T> &s) {
    vector<T> v;
    while (s.size()) {
        v.pb(s.top());
        s.pop();
    }
    reverse(all(v));
    __print(v);
    for (auto &i : v) s.push(i);
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
#pragma endregion Debug end

/*------------------------------------------END OF TEMPLATE-------------------------------------------*/

class SegmentTree {
   public:
    SegmentTree(int &n) {
        this->n = n;
        this->st.resize(4 * n, 0);  // tell number of elements in l to r (subtree basically) which are filled
        this->lazy.resize(4 * n, 0);
    }

    void fillRange(int l, int r) {
        rangeFill(l, r, 0, n - 1, 0);
    }

    void emptySingleNode(int index) {
        singleEmpty(index, 0, n - 1, 0);
    }

    int query(int l, int r) {
        return _query(l, r, 0, n - 1, 0);
    }

   private:
    vector<int> st, lazy;
    int n;

    int _query(int l, int r, int sl, int sr, int idx) {
        lazyUpdate(sl, sr, idx);
        if (l > sr || r < sl || sl > sr)
            return 1;
        if (sl >= l && sr <= r) {
            return st[idx];
        }
        int mid = (sl + sr) / 2;
        return _query(l, r, sl, mid, idx * 2 + 1) && _query(l, r, mid + 1, sr, idx * 2 + 2);
    }

    void rangeFill(int l, int r, int sl, int sr, int idx) {
        lazyUpdate(sl, sr, idx);
        if (l > sr || r < sl || sl > sr)
            return;
        if (sl >= l && sr <= r) {
            st[idx] = 1;
            if (sl != sr) {
                lazy[idx * 2 + 1] = 1;
                lazy[idx * 2 + 2] = 1;
            }
            return;
        }
        int mid = (sl + sr) / 2;
        rangeFill(l, r, sl, mid, idx * 2 + 1);
        rangeFill(l, r, mid + 1, sr, idx * 2 + 2);
        st[idx] = st[idx * 2 + 1] && st[idx * 2 + 2];
    }

    void singleEmpty(int leakIndex, int sl, int sr, int idx) {
        lazyUpdate(sl, sr, idx);
        if (leakIndex < sl || leakIndex > sr || sl > sr)
            return;
        if (sl == sr) {
            st[idx] = 0;
            return;
        }
        int mid = (sl + sr) / 2;
        if (leakIndex <= mid)
            singleEmpty(leakIndex, sl, mid, idx * 2 + 1);
        else
            singleEmpty(leakIndex, mid + 1, sr, idx * 2 + 2);
        st[idx] = st[idx * 2 + 1] && st[idx * 2 + 2];
    }

    void lazyUpdate(int sl, int sr, int idx) {
        if (lazy[idx]) {  // subtree was completely filled sometime back
            if (sl != sr) {
                lazy[idx * 2 + 1] = lazy[idx * 2 + 2] = 1;
            }
            st[idx] = 1;
            lazy[idx] = 0;
        }
    }
};

void dfs(int i, int par, int &curTime, vpii &timer, vvi &adj, vector<int> &parent) {
    parent[i] = par;
    timer[i].ff = curTime;
    for (auto &x : adj[i]) {
        if (x == par) continue;
        dfs(x, i, ++curTime, timer, adj, parent);
    }
    timer[i].ss = curTime;
}

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
    vector<int> parent(n);
    vector<pair<int, int>> timer(n, {-1, -1});
    int curTime = 0;
    dfs(0, -1, curTime, timer, adj, parent);
    SegmentTree segmentTree(n);
    int q;
    cin >> q;
    while (q--) {
        int c, v;
        cin >> c >> v;
        v--;
        if (c == 1) {
            /*
            l to r means we are filling subtree of node at lth index
            node at lth index in euler tour = nodes[l]
            if number of nodes filled in this range is less than r-l+1, this means at least one child was emptied before
            hence, we fill this subtree and mark the parent as explicitly emptied, to not lose this info.
            */
            int filled = segmentTree.query(timer[v].ff, timer[v].ss);
            if (!filled && parent[v] != -1)
                segmentTree.emptySingleNode(timer[parent[v]].first);
            segmentTree.fillRange(timer[v].ff, timer[v].ss);
        } else if (c == 2) {
            segmentTree.emptySingleNode(timer[v].ff);
        } else {
            int filled = segmentTree.query(timer[v].ff, timer[v].ss);
            if (filled)
                cout << 1 << endl;
            else
                cout << 0 << endl;
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
