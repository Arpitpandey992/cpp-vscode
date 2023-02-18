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
/*-----------------------------------------UTILITY FUNCTIONS------------------------------------------*/
inline ll ceil(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }   // divide a by b rounded up
inline ll floor(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }  // divide a by b rounded down
/*------------------------------------------END OF TEMPLATE-------------------------------------------*/

void solve() {
    int n;
    cin >> n;
    vll a(n);
    fo(i, n) cin >> a[i];
    int i = 0;
    vector<pair<int, int>> ans;
    int cur = 0;
    while (i < n) {
        if (a[i] == 0) {
            ans.pb({i, i});
            i++;
            continue;
        }
        int j = i;
        while (j < n && a[j] == a[i])
            j++;
        int len = j - i;
        if (len != 1) {
            ans.pb({i, j - 1 - (len & 1 ? 1 : 0)});
            i = j - (len & 1 ? 1 : 0);
            continue;
        }
        if (j < n && a[i] + a[j] == 0) {  // 1,-1
            ans.pb({i, i});
            ans.pb({j, j});
            i = j + 1;
            continue;
        }
        if (j == n) {  // 1,end
            ans.pb({i, i});
            cur += a[i];
            i = j;
            continue;
        }
        // a[j] = 0
        int k = j;
        while (k < n && a[k] == a[j])
            k++;
        if (k == n) {  // 1,0,0,0,...,0,0,end
            ans.pb({i, k - 1});
            cur += a[i];
            i = k;
            continue;
        }
        int len0 = k - j;  // continous zeros
        if (len0 % 2 == 0) {
            if (a[k] == a[i]) {  // 1,0,0,0,...even Zeros,1
                ans.pb({i, k});
                i = k + 1;
            } else {  // 1,0,0,0,0,-1
                ans.pb({i, k - 1});
                ans.pb({k, k});
                i = k + 1;
            }
        } else {
            if (a[k] == a[i]) {  // 1,0,1
                ans.pb({i, i});
                ans.pb({i + 1, k});
                i = k + 1;
            } else {  // 1,0,-1
                ans.pb({i, k});
                i = k + 1;
            }
        }
    }
    if (cur != 0) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (auto &[x, y] : ans) cout << x + 1 << " " << y + 1 << endl;
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