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
class SegTree {
#define T ll  // change if needed
    vector<T> st;
    vll pref;
    int siz;
    vpll ranges;

   public:
    int sum(int l, int r) {
        if (l > r) return 0;
        return pref[r] - (l > 0 ? pref[l - 1] : 0);
    }
    SegTree(vll &a) {
        int n = a.size();
        pref.resize(n);
        siz = 1 << int(ceil(log2(n)));
        ranges.resize(2 * siz, mp(0, 0));
        for (int i = 0; i < n; i++)
            pref[i] = a[i] + (i > 0 ? pref[i - 1] : 0);
        st.resize(2 * siz, 0);
        for (int i = siz; i - siz < n; i++) {
            st[i] = a[i - siz];
            ranges[i] = {i - siz, i - siz};
        }
        for (int i = siz - 1; i > 0; i--) {
            ranges[i] = {ranges[i * 2].ff, ranges[i * 2 + 1].ss};
            int a1 = st[i * 2];
            auto &[l, mid] = ranges[i * 2];
            int a2 = sum(l, mid) + st[i * 2 + 1];
            st[i] = min(a1, a2);
        }
    }
    T query(int l, int r) {
        T res = INF;
        ll l0 = l, r0 = r;
        for (l += siz, r += siz; l <= r; l >>= 1, r >>= 1) {
            if (l % 2 == 1) {
                auto &[l1, r1] = ranges[l];
                ll mnSum = sum(l0, l1 - 1);
                mnSum += st[l];
                res = min(res, mnSum);
                l++;
            }
            if (r % 2 == 0) {
                auto &[l1, r1] = ranges[r];
                ll mnSum = sum(l0, l1 - 1);
                mnSum += st[r];
                res = min(res, mnSum);
                r--;
            }
        }
        return res;
    }
#undef T
};
void solve() {
    ll n;
    cin >> n;
    vll a(n);
    fo(i, n) cin >> a[i];
    ll ans = 0;
    SegTree st(a);
    vll pref(n);
    fo(i, n)
        pref[i] = a[i] + (i > 0 ? pref[i - 1] : 0);
    vll ppref(n);
    fo(i, n)
        ppref[i] = pref[i] + (i > 0 ? ppref[i - 1] : 0);
    fo(i, n) {
        ll l = i, r = n;
        while (l < r) {
            ll mid = (l + r) / 2;
            ll mn = st.query(i, mid);
            if (mn >= 0)
                l = mid + 1;
            else
                r = mid;
        }
        if (l > i) {
            ll len = l - i;
            ans += ppref[l - 1] - (i > 0 ? pref[i - 1] * len + ppref[i - 1] : 0);
        }
    }
    cout << ans << endl;
    // for (int i = n - 1; i >= 0; i--) {
    //     int cur = 0;
    //     for (int j = i; j < n; j++) {
    //         cur += a[j];
    //         if (cur >= 0) {
    //             ans += cur;
    //         } else
    //             break;
    //     }
    // }
    // cout << ans << endl;
}

int main() {
#ifdef ONLINE_JUDGE
    fastio;
#endif
    ll tes = 1;
    cin >> tes;
    for (ll t = 1; t <= tes; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}