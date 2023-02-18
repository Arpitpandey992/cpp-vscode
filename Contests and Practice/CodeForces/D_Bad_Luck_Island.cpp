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
// #define ss second
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

void add(vector<ld>& a, vector<ld> b) {
    for (int i = 0; i < 3; i++)
        a[i] += b[i];
}

void solve() {
    int rocks, papers, scissors;
    cin >> rocks >> scissors >> papers;
    vector<ld> DP[rocks + 1][papers + 1][scissors + 1];
    for (int r = 0; r <= rocks; r++) {
        for (int p = 0; p <= papers; p++) {
            for (int s = 0; s <= scissors; s++) {
                ld rr = r, pp = p, ss = s;
                DP[r][p][s] = {0, 0, 0};
                if (r == 0 && p == 0 && s == 0) {
                    DP[r][p][s] = {0, 0, 0};
                } else if (r == 0 && p == 0) {
                    DP[r][p][s] = {0, 0, 1};
                } else if (r == 0 && s == 0) {
                    DP[r][p][s] = {0, 1, 0};
                } else if (p == 0 && s == 0) {
                    DP[r][p][s] = {1, 0, 0};
                } else {
                    // paper vs scissor
                    ld choose;
                    ld den = (rr * pp + pp * ss + rr * ss);
                    if (p > 0 && s > 0) {
                        choose = (pp * ss) / (den);
                        add(DP[r][p][s], {choose * DP[r][p - 1][s][0], choose * DP[r][p - 1][s][1], choose * DP[r][p - 1][s][2]});
                    }
                    // rock vs scissor
                    if (r > 0 && s > 0) {
                        choose = (rr * ss) / (den);
                        add(DP[r][p][s], {choose * DP[r][p][s - 1][0], choose * DP[r][p][s - 1][1], choose * DP[r][p][s - 1][2]});
                    }
                    // rock vs paper
                    if (r > 0 && p > 0) {
                        choose = (rr * pp) / (den);
                        add(DP[r][p][s], {choose * DP[r - 1][p][s][0], choose * DP[r - 1][p][s][1], choose * DP[r - 1][p][s][2]});
                    }
                }
            }
        }
    }
    vi ww = {0, 2, 1};
    for (auto who : ww) {
        cout << setprecision(10) << fixed << DP[rocks][papers][scissors][who] << " ";
    }
    cout << endl;
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