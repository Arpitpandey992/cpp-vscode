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

#pragma endregion
//-----------------------------------------UTILITY FUNCTIONS------------------------------------------
inline ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }   // divide a by b rounded up
inline ll floor(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
//------------------------------------------END OF TEMPLATE-------------------------------------------
// st is telling from l to r, how many tech leads are present and what is the cost
class SegTree {
    vector<pll> st;
    int siz;

   public:
    SegTree(int n) {
        siz = 1 << int(ceil(log2(n)));
        st.resize(2 * siz);
    }
    pll query(int l, int r) {
        pll res = {0, 0};
        for (l += siz, r += siz; l <= r; l >>= 1, r >>= 1) {
            if (l % 2 == 1) {
                res.ff += st[l].ff;
                res.ss += st[l].ss;
                l++;
            }
            if (r % 2 == 0) {
                res.ff += st[r].ff;
                res.ss += st[r].ss;
                r--;
            }
        }
        return res;
    }
    void update(int i, int x) {  //
        i += siz;
        st[i] = {st[i].ff + x, st[i].ss + x * (i - siz)};
        i >>= 1;
        while (i > 0) {
            st[i].ff = st[i * 2].ff + st[i * 2 + 1].ff;
            st[i].ss = st[i * 2].ss + st[i * 2 + 1].ss;
            i >>= 1;
        }
    }
#undef T
};

void solve() {
    ll n, k, x, d;
    cin >> n >> k >> x >> d;
    ll m;
    cin >> m;
    vector<tuple<int, int, int>> a;  // timestamp, enter/out, who
    vector<int> meetings(n, 0);
    fo(i, m) {
        int p, l, r;
        cin >> p >> l >> r;
        meetings[p - 1]++;
        a.push_back({l, r, p - 1});
    }
    int mxMeet = 0;
    fo(i, n) mxMeet = max(mxMeet, meetings[i]);
    // SegTree st(mxMeet + 1);
    Sort(a);
    int i = 0, j = 0, idx = 0;
    priority_queue<pll, vpll, greater<pll>> curIn;
    vector<int> coll(n, 0);
    // fo(i, n) st.update(0, +1);
    ll ans = INF;
    set<pair<ll, ll>> st, backup;
    ll cur = 0;
    auto upd = [&](ll who, ll newColl) {
        pll p = {coll[who], who};
        pll np = {newColl, who};
        if (CHK(st, p)) {
            cur -= coll[who];
            cur += newColl;
            st.erase(p);
            st.insert(np);
        } else {
            backup.erase(p);
            st.insert(np);
            cur += newColl;
        }
        while (st.size() > k) {
            backup.insert(*st.rbegin());
            cur -= st.rbegin()->ff;
            st.erase(--st.end());
        }
        while (backup.size() && st.size() && (st.rbegin()->ff) > (backup.begin()->ff)) {
            auto temp = *(st.rbegin());
            cur -= st.rbegin()->ff;
            st.erase(--st.end());
            st.insert(*backup.begin());
            cur += backup.begin()->ff;
            backup.erase(backup.begin());
            backup.insert(temp);
        }
    };
    fo(i, n) upd(i, 0);
    while (i + x <= d) {
        map<ll, ll> newIn;
        while (j <= i + x) {
            while (idx < m) {
                auto &[lef, rig, who] = a[idx];
                if (lef >= j) break;
                curIn.push({rig, who});
                newIn[who]++;
                idx++;
            }
            j++;
        }
        for (auto &[who, newColl] : newIn) {
            upd(who, coll[who] + newColl);
            coll[who] += newColl;
        }
        ans = min(ans, cur);
        i++;
        newIn.clear();
        while (curIn.size()) {
            auto [rig, who] = curIn.top();
            if (rig > i) break;
            newIn[who]++;
            curIn.pop();
        }
        for (auto &[who, newColl] : newIn) {
            upd(who, coll[who] - newColl);
            coll[who] -= newColl;
        }
    }
    cout << ans << endl;
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