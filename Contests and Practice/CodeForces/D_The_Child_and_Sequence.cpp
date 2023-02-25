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

struct SegTree {
   private:
    vector<ll> stSum;
    vector<pair<ll, ll>> stMax;
    vector<ll> a;
    ll n;
    void build(ll node, ll sl, ll sr) {
        if (sl > sr) return;
        if (sl == sr) {
            stSum[node] = a[sl];
            stMax[node] = {a[sl], sl};
            return;
        }
        ll mid = (sl + sr) >> 1;
        build(node * 2 + 1, sl, mid);
        build(node * 2 + 2, mid + 1, sr);
        stSum[node] = stSum[node * 2 + 1] + stSum[node * 2 + 2];
        stMax[node] = max(stMax[node * 2 + 1], stMax[node * 2 + 2]);
    }

    ll qrySum(ll node, ll sl, ll sr, ll &l, ll &r) {
        if (sl > sr || sl > r || sr < l)
            return 0;
        if (sl >= l && sr <= r)
            return stSum[node];
        ll mid = (sl + sr) >> 1;
        return qrySum(node * 2 + 1, sl, mid, l, r) + qrySum(node * 2 + 2, mid + 1, sr, l, r);
    }
    pair<ll, ll> qryMax(ll node, ll sl, ll sr, ll &l, ll &r) {
        if (sl > sr || sl > r || sr < l)
            return {-1, -1};
        if (sl >= l && sr <= r)
            return stMax[node];
        ll mid = (sl + sr) >> 1;
        return max(qryMax(node * 2 + 1, sl, mid, l, r), qryMax(node * 2 + 2, mid + 1, sr, l, r));
    }

    void upd(ll node, ll sl, ll sr, ll &i, ll &x) {
        if (sl == sr) {
            a[i] = x;
            stSum[node] = x;
            stMax[node] = {x, i};
            return;
        }
        ll mid = (sl + sr) >> 1;
        if (i <= mid)
            upd(node * 2 + 1, sl, mid, i, x);
        else
            upd(node * 2 + 2, mid + 1, sr, i, x);
        stSum[node] = stSum[node * 2 + 1] + stSum[node * 2 + 2];
        stMax[node] = max(stMax[node * 2 + 1], stMax[node * 2 + 2]);
    }

   public:
    SegTree(const vector<ll> &a) {
        this->a = a;
        n = a.size();
        stSum.resize(4 * n + 5);
        stMax.resize(4 * n + 5);
        build(0, 0, n - 1);
    }
    ll querySum(ll l, ll r) {
        return qrySum(0, 0, n - 1, l, r);
    }
    pair<ll, ll> queryMax(ll l, ll r) {
        return qryMax(0, 0, n - 1, l, r);
    }
    void update(ll i, ll x) {
        upd(0, 0, n - 1, i, x);
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    vll a(n);
    fo(i, n) cin >> a[i];
    SegTree st(a);
    while (m--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll l, r;
            cin >> l >> r;
            cout << st.querySum(l - 1, r - 1) << endl;
        } else if (t == 2) {
            ll l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            pair<ll, ll> p = st.queryMax(l, r);
            while (p.first >= x) {
                a[p.second] = a[p.second] % x;
                st.update(p.second, a[p.second]);
                p = st.queryMax(l, r);
            }

        } else {
            ll i, x;
            cin >> i >> x;
            i--;
            a[i] = x;
            st.update(i, x);
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