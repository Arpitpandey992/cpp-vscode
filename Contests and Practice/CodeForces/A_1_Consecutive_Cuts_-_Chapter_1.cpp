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

vector<int> kmp(vll &a, vll &b) {
    int n = a.size(), m = b.size();
    vll lps(m);
    int i = 1, j = 0;
    lps[0] = 0;
    while (i < m) {
        if (b[i] == b[j])
            lps[i++] = ++j;
        else if (j != 0)
            j = lps[j - 1];
        else
            lps[i++] = 0;
    }
    i = 0, j = 0;
    vector<int> matches;
    while (i < n) {
        if (a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == m) {
            matches.pb(i - j);
            j = lps[j - 1];
        }
        if (i < n && a[i] != b[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return matches;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vll a(n), b(n);
    fo(i, n) cin >> a[i];
    fo(i, n) cin >> b[i];

    if (k == 0) {
        if (a == b) {
            cout << "YES\n";
        } else
            cout << "NO\n";
        return;
    }
    fo(i, n) a.push_back(a[i]);
    a.pop_back();
    auto match = kmp(a, b);
    if (match.empty()) {
        cout << "NO\n";
        return;
    }
    if (k == 1) {
        if (match.size() > 1 || match[0] != 0) {
            cout << "YES\n";
        } else
            cout << "NO\n";
        return;
    }
    if (n == 2) {
        if (match.size() == 2) {
            cout << "YES\n";
        } else {
            if ((k % 2 == 0 && match[0] == 0) || (k % 2 == 1 && match[0] == 1)) {
                cout << "YES\n";
            } else
                cout << "NO\n";
        }
        return;
    }
    cout << "YES\n";
}

int main() {
    fastio;
    fileio;
    ll tes = 1;
    cin >> tes;
    for (ll t = 1; t <= tes; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}