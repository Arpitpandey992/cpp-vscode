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

vector<int> getCT(int l, int r, vector<vector<int>>& ct) {
    if (l == 0) return ct[r];
    auto ans = ct[r];
    for (int i = 0; i < 26; i++)
        ans[i] -= ct[l - 1][i];
    return ans;
}

bool valid(vector<int>& a, vector<int>& b) {
    int mis = 0;
    for (int i = 0; i < 26; i++)
        mis += abs(a[i] - b[i]);
    return mis == 1;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> ct(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        ct[i][s[i] - 'a']++;
        if (i > 0) {
            for (int j = 0; j < 26; j++)
                ct[i][j] += ct[i - 1][j];
        }
    }
    int q;
    cin >> q;
    int ans = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r) {
            ans++;
            continue;
        }
        if ((r - l + 1) % 2 == 0)
            continue;
        int mid = (l + r) / 2;
        auto a = getCT(l, mid, ct), b = getCT(mid + 1, r, ct);
        if (valid(a, b)) {
            ans++;
            continue;
        }
        a = getCT(l, mid - 1, ct);
        b = getCT(mid, r, ct);
        if (valid(b, a))
            ans++;
    }
    cout << ans << endl;
}

int main() {
#ifdef ONLINE_JUDGE
    fastio;
    fileio;
#endif
    ll tes = 1;
    cin >> tes;
    for (ll t = 1; t <= tes; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}