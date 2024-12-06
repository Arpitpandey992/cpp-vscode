const long long M = 1e9 + 7;
const int INF = 2147483647;
const long long INFLL = 9223372036854775807ll;
#pragma region Template Start
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
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

class RangeCountHelper {
   public:
    RangeCountHelper(int n) {
        this->n = n;
        this->st.resize(4 * n, 0);
    }

    int getCount(int l, int r) {
        return this->_query(l, r, 0, n - 1, 0);
    }

    void switchOn(int index) {
        this->_update(index, 0, n - 1, 0);
    }

   private:
    vector<int> st;
    int n;

    int _query(int l, int r, int sl, int sr, int idx) {
        if (l > sr || r < sl || sl > sr)
            return 0;
        if (sl >= l && sr <= r)
            return st[idx];
        int mid = (sl + sr) / 2;
        return _query(l, r, sl, mid, idx * 2 + 1) + _query(l, r, mid + 1, sr, idx * 2 + 2);
    }

    void _update(int i, int sl, int sr, int idx) {
        if (i > sr || i < sl)
            return;
        if (sl == sr) {
            st[idx] = 1;
            return;
        }
        int mid = (sl + sr) / 2;
        if (i <= mid)
            _update(i, sl, mid, idx * 2 + 1);
        else
            _update(i, mid + 1, sr, idx * 2 + 2);
        st[idx] = st[idx * 2 + 1] + st[idx * 2 + 2];
    }
};

class LargestIndexHelper {
   public:
    LargestIndexHelper(vector<int> &a) {
        this->n = a.size();
        this->a = a;
        this->st.resize(4 * n, 0);
        this->_build(0, n - 1, 0);
    }

    int getLargestIndex(int greaterThanEqualTo) {
        return _query(greaterThanEqualTo, 0, n - 1, 0);
    }

    void invalidate(int index) {
        this->_remove(index, 0, n - 1, 0);
    }

   private:
    vector<int> st;
    vector<int> a;
    int n;

    int _query(int k, int sl, int sr, int idx) {
        if (a[st[idx]] < k)
            return -1;
        if (sl == sr) {
            return sl;
        }
        int mid = (sl + sr) / 2;
        int rightSegmentMax = a[st[idx * 2 + 2]];
        if (rightSegmentMax >= k)
            return _query(k, mid + 1, sr, idx * 2 + 2);  // find the largest index in right segment
        int leftSegmentMax = a[st[idx * 2 + 1]];
        if (leftSegmentMax >= k)
            return _query(k, sl, mid, idx * 2 + 1);  // since right segment does not have any element >= k, we begrudgeingly resort to left segment
        return -1;
    }

    void _remove(int i, int sl, int sr, int idx) {
        if (i > sr || i < sl)
            return;
        if (sl == sr) {
            a[i] = -1;  // this will no longer be considered during query
            st[idx] = sl;
            return;
        }
        int mid = (sl + sr) / 2;
        if (i <= mid)
            _remove(i, sl, mid, idx * 2 + 1);
        else
            _remove(i, mid + 1, sr, idx * 2 + 2);
        int leftSegmentMaxIndex = st[idx * 2 + 1];
        int rightSegmentMaxIndex = st[idx * 2 + 2];
        if (a[rightSegmentMaxIndex] >= a[leftSegmentMaxIndex])
            st[idx] = rightSegmentMaxIndex;
        else
            st[idx] = leftSegmentMaxIndex;
    }

    int _build(int sl, int sr, int idx) {
        if (sl == sr) {
            return st[idx] = sl;
        }
        int mid = (sl + sr) / 2;
        int leftSegmentMaxIndex = _build(sl, mid, idx * 2 + 1);
        int rightSegmentMaxIndex = _build(mid + 1, sr, idx * 2 + 2);
        if (a[rightSegmentMaxIndex] >= a[leftSegmentMaxIndex])
            st[idx] = rightSegmentMaxIndex;
        else
            st[idx] = leftSegmentMaxIndex;
        return st[idx];
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    vector<int> queries(k);
    fo(i, n) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](auto &p1, auto &p2) { return max(p1.ff, p1.ss) > max(p2.ff, p2.ss); });
    fo(i, k) {
        cin >> queries[i];
    }
    RangeCountHelper rangeCountHelper(queries.size());
    LargestIndexHelper largestIndexHelper(queries);
    vector<pair<int, int>> q;
    for (int i = 0; i < k; i++) {
        q.push_back({queries[i], i});
    }
    sort(q.begin(), q.end());
    ll ans = 0;
    for (auto &[ai, bi] : a) {
        while (q.size() && q.back().ff >= max(ai, bi)) {
            auto [currentMaxQuery, currentMaxQueryIndex] = q.back();
            q.pop_back();
            rangeCountHelper.switchOn(currentMaxQueryIndex);
            largestIndexHelper.invalidate(currentMaxQueryIndex);
        }
        int largestIndex = largestIndexHelper.getLargestIndex(min(ai, bi));
        int rotationCount = rangeCountHelper.getCount(largestIndex + 1, k - 1);
        bool isRotated = rotationCount % 2 == 1;
        if (ai < bi) {
            if (largestIndex != -1)
                isRotated = !isRotated;
        }
        ans += isRotated ? (ll)bi : (ll)ai;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tes = 1;
    // cin >> tes;
    for (ll t = 1; t <= tes; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
/*
    What to do?
    1. for any query q[i] >= a[i].ss && q[i] < a[i].ff (assuming first > second)
        - This will cause rotation to revert back to initial state (above assumption)
        - After last q[i] >= ... && q[i] < ..., all q[i] >= a[i].ff will rotate once
    2. find the last query index whose value is lesser than a[i].ff but >= a[i].ss
        - max index in array whose value is >= given value [queries]
        - since we are iterating in reducing value of a[i].ff, we can permanently ignore them when calculating maxIndex
        - basically largest index with value >= given query
    3. rotationCount = number of q[i] where i > above index && q[i] >= a[i].ff
        - willRotate = rotationCount%2 == 1
        - if a[i].ff < a[i].ss:
            - rotation will still count in the same way, just that we assume we start from bigger value as first
            - if no query between a[i].ff and a[i].ss, then rotation will count from smaller value (edge case).
    4. when iterating in reverse manner of a[i].ff, the above count will only increase
        - simple range sum query in binary array
        - initially, all zero
        - while iterating on a, make imaginaryArray[j] = 1 where q[j] >= a[i].ff
*/
