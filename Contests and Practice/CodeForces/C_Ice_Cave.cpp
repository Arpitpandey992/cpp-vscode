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

vpii del = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, m;
bool dfs(vector<string> &a, pii st, pii &ed, vvb &vis) {
    vis[st.ff][st.ss] = true;
    for (auto &[dx, dy] : del) {
        int nx = st.ff + dx, ny = st.ss + dy;
        if (mp(nx, ny) == ed) return true;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == 'X' || vis[nx][ny])
            continue;
        if (dfs(a, {nx, ny}, ed, vis))
            return true;
    }
    return false;
}

bool canReach(vector<string> &a, pii &st, pii &ed) {
    vvb vis(n, vb(m, false));
    if (dfs(a, st, ed, vis))
        return true;
    return false;
}

void solve() {
    cin >> n >> m;
    vector<string> a(n);
    fo(i, n) cin >> a[i];
    pii st, ed;
    cin >> st.ff >> st.ss >> ed.ff >> ed.ss;
    st.ff--;
    st.ss--;
    ed.ff--;
    ed.ss--;
    if (a[ed.ff][ed.ss] == 'X') {
        if (canReach(a, st, ed))
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }
    for (auto &[dx, dy] : del) {
        int nx = ed.ff + dx, ny = ed.ss + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == 'X')
            continue;
        a[nx][ny] = 'X';
        if (canReach(a, st, ed)) {
            cout << "YES\n";
            return;
        }
        a[nx][ny] = '.';
    }
    cout << "NO\n";
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