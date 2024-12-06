#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
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
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define fileio                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
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
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fo(i, a, n) for (ll i = a; i <= n; i++)
#define fr(i, n, a) for (ll i = n; i >= a; i--)
#define all(v) v.begin(), v.end()
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define endl "\n"

/*
#define M 998244353

ll multiply (ll a, ll b) {
        return ((a*b)%M +M)%M;
}

ll power (ll base, ll exp) {
        if (exp==0) return 1;
        ll ans = (exp%2==1) ? base:1;
        ll sa = power(base, exp/2);
        ans = multiply(ans, sa);
        ans = multiply(ans, sa);
        return ans;
}

ll divide (ll a, ll b) {
        ll x = power(b, M-2);
        return multiply(a,x);
}
*/

struct Elements {
    ll a;
    ll b;
    ll idx;
    ll maxi;
    ll mini;
};

struct Query {
    ll val;
    ll idx;
};

class SegmentTree {
    vl maxiCalculator;
    vl countCalculator;
    vl a;
    int n;

    void buildTree(vl& sTree, int idx, int start, int end) {
        if (start == end) {
            sTree[idx] = start;
            return;
        }
        int mid = (start + end) / 2;
        buildTree(sTree, 2 * idx + 1, start, mid);
        buildTree(sTree, 2 * idx + 2, mid + 1, end);
        sTree[idx] = (a[sTree[2 * idx + 2]] >= a[sTree[2 * idx + 1]]) ? sTree[2 * idx + 2] : sTree[2 * idx + 1];
    }

    ll queryMaxTreeIdx(vl& sTree, int idx, int start, int end, int maxi) {
        if (a[sTree[idx]] < maxi) return -1;
        if (start == end) return start;
        int mid = (start + end) / 2;
        int rightVal = a[sTree[2 * idx + 2]];
        if (rightVal >= maxi)
            return queryMaxTreeIdx(sTree, 2 * idx + 2, mid + 1, end, maxi);
        else
            return queryMaxTreeIdx(sTree, 2 * idx + 1, start, mid, maxi);
    }

    ll queryCountTreeIdx(const vl& sTree, int idx, int start, int end, int qs, int qe) {
        if (qs > end || qe < start) return 0;
        if (start >= qs && end <= qe) return sTree[idx];
        int mid = (start + end) / 2;
        ll leftAns = queryCountTreeIdx(sTree, 2 * idx + 1, start, mid, qs, qe);
        ll rightAns = queryCountTreeIdx(sTree, 2 * idx + 2, mid + 1, end, qs, qe);
        return leftAns + rightAns;
    }

    void updateMaxTreeIdx(vl& sTree, int idx, int start, int end, int updateIdx) {
        if (start == end) {
            a[updateIdx] = -1;
            return;
        }
        int mid = (start + end) / 2;
        if (updateIdx <= mid)
            updateMaxTreeIdx(sTree, 2 * idx + 1, start, mid, updateIdx);
        else
            updateMaxTreeIdx(sTree, 2 * idx + 2, mid + 1, end, updateIdx);
        sTree[idx] = (a[sTree[2 * idx + 2]] >= a[sTree[2 * idx + 1]]) ? sTree[2 * idx + 2] : sTree[2 * idx + 1];
    }

    void updateCountTreeIdx(vl& sTree, int idx, int start, int end, int updateIdx) {
        sTree[idx]++;
        if (start == end) return;
        int mid = (start + end) / 2;
        if (updateIdx <= mid)
            updateCountTreeIdx(sTree, 2 * idx + 1, start, mid, updateIdx);
        else
            updateCountTreeIdx(sTree, 2 * idx + 2, mid + 1, end, updateIdx);
    }

    void displayTree(const vl& sTree, int idx, int start, int end) {
        cout << "Range " << start << " -> " << end << " contains " << sTree[idx] << endl;
        if (start == end) return;
        int mid = (start + end) / 2;
        displayTree(sTree, 2 * idx + 1, start, mid);
        displayTree(sTree, 2 * idx + 2, mid + 1, end);
    }

    void displayTree(const vl& sTree) {
        displayTree(sTree, 0, 0, n - 1);
    }

   public:
    SegmentTree(const vector<Query>& array) {
        n = array.size();
        a.resize(n, 0);
        maxiCalculator.resize(4 * n, 0);
        countCalculator.resize(4 * n, 0);
        fo(i, 0, n - 1) a[i] = array[i].val;
        buildTree(maxiCalculator, 0, 0, n - 1);
        // cout<<"Displaying MaxTree"<<endl; displayTree(maxiCalculator);
    }

    ll findRightmostIndex(ll maxi) {
        return queryMaxTreeIdx(maxiCalculator, 0, 0, n - 1, maxi);
    }

    void update(Query query) {
        // cout<<"Updating : "<<query.idx<<" having "<<query.val<<endl;
        updateMaxTreeIdx(maxiCalculator, 0, 0, n - 1, query.idx);
        updateCountTreeIdx(countCalculator, 0, 0, n - 1, query.idx);
        // cout<<"Displaying MaxTree"<<endl; displayTree(maxiCalculator);
        // cout<<"Displaying CountTree"<<endl; displayTree(countCalculator);
    }

    ll countRotations(ll leftIdx) {
        return queryCountTreeIdx(countCalculator, 0, 0, n - 1, leftIdx, n - 1);
    }
};

long long generateRandomNumber(long long lower_bound, long long upper_bound) {
    // Create a random device to seed the random number generator
    std::random_device rd;

    // Initialize the Mersenne Twister random number generator
    std::mt19937_64 gen(rd());

    // Define the distribution range
    std::uniform_int_distribution<long long> dis(lower_bound, upper_bound);

    // Generate and return the random number
    return dis(gen);
}
void solve() {
    int n, q;
    // n = 40000;
    // q = 40000;
    cin >> n >> q;
    vector<Elements> array(n);
    // ll MX = 1000000000;

    fo(i, 0, n - 1) {
        ll x, y;
        // x = generateRandomNumber(1, MX);
        // y = generateRandomNumber(1, MX);

        cin >> x >> y;
        array[i] = {x, y, i, max(x, y), min(x, y)};
    }
    sort(all(array), [](auto x, auto y) { return x.maxi > y.maxi; });

    vector<Query> query(q);
    fo(i, 0, q - 1) {
        // query[i].val = generateRandomNumber(1, MX);
        cin >> query[i].val;
        query[i].idx = i;
    }
    SegmentTree fastQueries(query);
    sort(all(query), [](auto x, auto y) { return x.val > y.val; });
    ll eliminatedIdx = 0;
    ll ans = 0;

    fo(i, 0, n - 1) {
        // cout<<"Solving for : "<<array[i].idx<<" having "<<array[i].a<<" and "<<array[i].b<<endl;
        while (eliminatedIdx < q && query[eliminatedIdx].val >= array[i].maxi) {
            fastQueries.update(query[eliminatedIdx]);
            eliminatedIdx++;
        }
        int rightMost = fastQueries.findRightmostIndex(array[i].mini);
        int countRotations = (rightMost == n - 1) ? 0 : fastQueries.countRotations(rightMost + 1);
        // cout<<"Found rightmost index : "<<rightMost<<" and rotations are "<<countRotations<<endl;
        ll shortAns = ((countRotations % 2) ? array[i].mini : array[i].maxi);
        if (rightMost == -1) shortAns = ((countRotations % 2) ? array[i].b : array[i].a);
        ans += shortAns;
    }
    cout << ans << endl;
}

int main() {
    fastio;
    int t = 1;  // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}