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
#define int ll
class SegTree {
    vector<int> st, lazy;
    int n;
    void build(int node, int sl, int sr, vector<int>& a) {
        if (sl == sr) {
            st[node] = a[sl];
            return;
        }
        int mid = (sl + sr) >> 1;
        build(node * 2 + 1, sl, mid, a);
        build(node * 2 + 2, mid + 1, sr, a);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }
    int qry(int node, int sl, int sr, int& l, int& r) {
        st[node] += (sr - sl + 1) * lazy[node];
        if (sl != sr) {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
        if (sl > r || sr < l)
            return 0;
        if (sl >= l && sr <= r)
            return st[node];
        int mid = (sl + sr) >> 1;
        return qry(node * 2 + 1, sl, mid, l, r) + qry(node * 2 + 2, mid + 1, sr, l, r);
    }
    void upd(int node, int sl, int sr, int& l, int& r, int& k) {
        st[node] += (sr - sl + 1) * lazy[node];
        if (sl != sr) {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
        if (sl > r || sr < l)
            return;
        if (sl >= l && sr <= r) {
            st[node] += (sr - sl + 1) * k;
            if (sl != sr) {
                lazy[node * 2 + 1] += k;
                lazy[node * 2 + 2] += k;
            }
            return;
        }
        int mid = (sl + sr) >> 1;
        upd(node * 2 + 1, sl, mid, l, r, k);
        upd(node * 2 + 2, mid + 1, sr, l, r, k);
    }

   public:
    SegTree(vector<int>& a) {
        n = a.size();
        st.resize(4 * n + 5, 0);
        lazy.resize(4 * n + 5, 0);
        build(0, 0, n - 1, a);
    }
    int query(int l, int r) {
        return qry(0, 0, n - 1, l, r);
    }
    void update(int l, int r, int k) {
        upd(0, 0, n - 1, l, r, k);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    fo(i, n) cin >> a[i];
    SegTree st(a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            st.update(a - 1, b - 1, u);
        } 
        else if(t==2){
            int a, b, u;
            cin >> a >> b >> u;
            st.update(a - 1, b - 1, u);
        }
        else {
            int k;
            cin >> k;
            cout << st.query(k - 1, k - 1) << endl;
        }
    }
}

signed main() {
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