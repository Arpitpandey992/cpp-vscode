#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define fileio                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define M 1000000007
#define ll long long
#define ld long double
#define vl vector<long long>
#define vi vector<int>
#define vb vector<bool>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vsi vector<set<int>>
#define ull unordered_map<ll, ll>
#define pll pair<long long, long long>
#define pii pair<int, int>
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fo(i, a, n) for (ll i = a; i <= n; i++)
#define fr(i, n, a) for (ll i = n; i >= a; i--)
#define all(v) v.begin(), v.end()
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define endl "\n"

void solve() {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    priority_queue<int> maxHeap;
    int count = 0, countOne = 0;
    fo(i, 0, n) {
        // cout<<s[i]<<" ";
        if (i < n && s[i] == '0')
            count++;
        else {
            maxHeap.push(count);
            count = 0;
            countOne++;
        }
    }
    // cout << count << endl;
    int ans = countOne;
    while (!maxHeap.empty() && x > 0) {
        int curr = maxHeap.top();
        maxHeap.pop();
        int maxPoss = (x - 1) / 2;
        ans += min(curr, maxPoss);
        x -= (2 * (maxPoss, curr) + 1);
        if (x < 3) x = 0;
    }
    cout << ans << endl;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
