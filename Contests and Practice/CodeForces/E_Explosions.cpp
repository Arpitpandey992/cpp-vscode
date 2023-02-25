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
    int n;
    cin >> n;
    vll a(n);
    fo(i, n) cin >> a[i];
    vll prefSum(n), pref(n, 0), suff(n, 0);
    vll pse(n, -1), nse(n, n);
    {
        vll b(n);
        fo(i, n) {
            b[i] = a[i] - i;
            prefSum[i] = b[i] + (i > 0 ? prefSum[i - 1] : 0);
        }
        auto sum = [&](int l, int r) {
            return prefSum[r] - (l > 0 ? prefSum[l - 1] : 0);
        };
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() && b[s.top()] >= b[i]) {
                pse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            ll prev = pse[i];
            ll aft = i - prev;
            ll zeroElements = a[i] + 1;
            ll reqChange = max(0ll, aft - zeroElements);
            // 1 + 2 + .. + reqChange
            pref[i] -= (reqChange * (reqChange + 1)) / 2;
            pref[i] += sum(prev + 1, i) - aft * b[i];
            if (prev >= 0)
                pref[i] += pref[prev];
        }
    }
    {
        vll b(n);
        for (int i = n - 1; i >= 0; i--) {
            b[i] = a[i] - (n - 1 - i);
        }
        fo(i, n) {
            prefSum[i] = b[i] + (i > 0 ? prefSum[i - 1] : 0);
        }
        auto sum = [&](int l, int r) {
            return prefSum[r] - (l > 0 ? prefSum[l - 1] : 0);
        };
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (s.size() && b[s.top()] >= b[i]) {
                nse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            ll next = nse[i];
            ll aft = next - i;
            ll zeroElements = a[i] + 1;
            ll reqChange = max(0ll, aft - zeroElements);
            // 1 + 2 + .. + reqChange
            suff[i] -= (reqChange * (reqChange + 1)) / 2;
            suff[i] += sum(i, next - 1) - aft * b[i];
            if (next < n)
                suff[i] += suff[next];
        }
    }

    ll ans = INFLL;
    for (int i = 0; i < n; i++) {
        ans = min(ans, pref[i] + suff[i] + a[i]);
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
        // cout << "Case #" << t << ": ";
        solve();
    }
}