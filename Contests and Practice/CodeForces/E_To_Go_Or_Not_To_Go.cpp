const long long M = 1e9 + 7;
const int INF = 2147483647;
const long long INFLL = 9223372036854775807ll / 4;
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
ll n, m, k;
vvll a;

void djikstra(int sx, int sy, vector<vector<ll>> &dis) {
    dis.assign(n, vll(m, INFLL));
    dis[sx][sy] = 0;
    priority_queue<tlll, vector<tlll>, greater<tlll>> q;
    q.push({0, sx, sy});
    vpii del = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    while (q.size()) {
        auto [d, x, y] = q.top();
        q.pop();
        if (d != dis[x][y]) continue;
        for (auto &[dx, dy] : del) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == -1)
                continue;
            if (dis[nx][ny] <= d + k) continue;
            dis[nx][ny] = d + k;
            q.push({d + k, nx, ny});
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    a.resize(n, vll(m));
    fo(i, n) fo(j, m) cin >> a[i][j];
    vector<pair<ll, ll>> portal;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0) {
                portal.pb({i, j});
            }
        }
    }
    vvll dis1, dis2;
    djikstra(0, 0, dis1);
    djikstra(n - 1, m - 1, dis2);
    if (portal.size()) {
        vector<ll> p1, p2;
        for (auto &[x, y] : portal) {
            p1.push_back({dis1[x][y] + a[x][y]});
            p2.push_back({dis2[x][y] + a[x][y]});
        }
        Sort(p1);
        Sort(p2);
        dis1[n - 1][m - 1] = min(dis1[n - 1][m - 1], p1[0] + p2[0]);
    }
    if (dis1[n - 1][m - 1] < INFLL) {
        cout << dis1[n - 1][m - 1] << endl;
    } else {
        cout << -1 << endl;
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