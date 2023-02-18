const long long M1 = 1e9 + 7, M2 = 1e9 + 9;
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

vector<int> getOcc(string &a, string &s) {
    int n = s.size(), m = a.size();
    vector<int> lps(m), occ;
    {
        int i = 1, len = 0;
        lps[0] = 0;
        while (i < m) {
            if (a[len] == a[i])
                lps[i++] = ++len;
            else if (len != 0)
                len = lps[len - 1];
            else
                i++;
        }
    }
    {
        int i = 0, j = 0;
        while (i < n) {
            if (s[i] == a[j]) {
                i++;
                j++;
                if (j == m) {
                    occ.push_back(i - m);
                    j = lps[j - 1];
                }
            } else if (j != 0) {
                j = lps[j - 1];
            } else
                i++;
        }
    }
    return occ;
}

struct node {
    bool eow;
    vector<node *> next;
    node() {
        eow = false;
        next.assign(26, NULL);
    }
};

struct Trie {
    node *root;
    Trie() {
        root = new node();
    }
    void insert(const string &s) {
        int n = s.size();
        auto cur = root;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (!cur->next[c])
                cur->next[c] = new node();
            cur = cur->next[c];
        }
        cur->eow = true;
    }
    bool search(const string &s) {
        int n = s.size();
        auto cur = root;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (!cur->next[c]) return false;
            cur = cur->next[c];
        }
        return true;
    }
};

void solve() {
    Trie t;
    string s, a, b;
    cin >> s >> a >> b;
    int n = s.size();
    vector<int> occa = getOcc(a, s), occb = getOcc(b, s);
    unordered_set<ll> ans;
    for (auto &j : occb) {
        int idx = (int)occa.size() - 1;
        int cur = j + b.size() - 1;
        ll h1 = 0, h2 = 0;
        while (idx >= 0) {
            int i = occa[idx];
            int len = j + b.size() - i;
            if (len < int(max(a.size(), b.size()))) {
                idx--;
                continue;
            }
            while (cur >= i) {
                ll c = s[cur] - 'a' + 1;
                h1 = (h1 * 26 + c) % M1;
                h2 = (h2 * 26 + c) % M2;
                cur--;
            }
            ans.insert(h1 * h2);
            idx--;
        }
    }
    cout << ans.size() << endl;
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