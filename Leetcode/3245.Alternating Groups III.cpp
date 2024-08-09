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

#pragma region Debug Statements
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
template <typename T>
void __print(priority_queue<T> &q) {
    vector<T> v;
    while (q.size()) {
        v.pb(q.top());
        q.pop();
    }
    __print(v);
    for (auto &i : v) q.push(i);
}
template <typename T>
void __print(stack<T> &s) {
    vector<T> v;
    while (s.size()) {
        v.pb(s.top());
        s.pop();
    }
    reverse(all(v));
    __print(v);
    for (auto &i : v) s.push(i);
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
#pragma endregion Debug end

/*------------------------------------------END OF TEMPLATE-------------------------------------------*/
/*
SegTree will give the following info for an array like:
indices: 0 1 2 3 4 5 6 7 8 9 10 11 12 ...
values:  0 0 1 4 2 3 1 6 9 1 0  4  0  ...
query for index from [left, right]
it will give: [sum of index*value from left to right, sum of values from left to right]

update for index: value[index] = newValue
*/

class SegTree {
    vector<pair<int, int>> st;  // from left to right: sum of index*value, sum of values
    vector<int> arr;

   public:
    SegTree(vector<int> &a, int maxValue) {
        st.resize(4 * maxValue);
        arr.resize(maxValue + 1, 0);
        for (auto &x : a)
            arr[x]++;
        a = arr;
        build(0, 0, arr.size() - 1);
    }

    pair<int, int> query(int groupSizeFrom) {
        return this->query(groupSizeFrom, arr.size() - 1, 0, 0, arr.size() - 1);
    }

    void update(int groupSize, int newGroupCount) {
        arr[groupSize] = newGroupCount;
        this->update(groupSize, 0, 0, arr.size() - 1);
    }

   private:
    void build(int si, int sl, int sr) {
        // sl...sr in arr is represented by this node
        if (sl == sr) {
            int index = sl;
            st[si] = {arr[index] * index, arr[index]};  // index*value, value
            return;
        }
        int mid = (sl + sr) / 2;
        build(si * 2 + 1, sl, mid);
        build(si * 2 + 2, mid + 1, sr);
        st[si] = {st[si * 2 + 1].first + st[si * 2 + 2].first,
                  st[si * 2 + 1].second + st[si * 2 + 2].second};
    }

    void update(int index, int si, int sl, int sr) {
        // assuming arr[index] was updated before this call
        if (sl == sr) {
            st[si] = {arr[index] * index, arr[index]};  // index*value, value
            return;
        }
        int mid = (sl + sr) / 2;
        if (index <= mid)
            update(index, si * 2 + 1, sl, mid);
        else
            update(index, si * 2 + 2, mid + 1, sr);
        st[si] = {st[si * 2 + 1].first + st[si * 2 + 2].first,
                  st[si * 2 + 1].second + st[si * 2 + 2].second};
    }

    pair<int, int> query(int l, int r, int si, int sl, int sr) {
        if (sl > r || sr < l)
            return {0, 0};
        if (sl >= l && sr <= r)
            return st[si];
        int mid = (sl + sr) / 2;
        auto [leftSum, leftValueSum] = query(l, r, si * 2 + 1, sl, mid);
        auto [rightSum, rightValueSum] = query(l, r, si * 2 + 2, mid + 1, sr);
        return {leftSum + rightSum, leftValueSum + rightValueSum};
    }
};

class Solution {
    int findSize(int left, int right, int &n) {
        if (right >= left)
            return right - left + 1;
        return n - left + right + 1;
        return ((right - left + 1) % n + n) % n;
    }
    int findSize(const pair<int, int> &p, int &n) {
        return findSize(p.first, p.second, n);
    }

   public:
    vector<int> numberOfAlternatingGroups(vector<int> &colors, vector<vector<int>> &queries) {
        set<pair<int, int>> groups;
        vector<int> sizes;
        int n = colors.size();
        // forming groups
        {
            int start = -1;
            for (int i = 0; i < n; i++) {
                if (colors[i] == colors[((i - 1) % n + n) % n]) {
                    start = i;
                    break;
                }
            }
            if (start == -1) {
                sizes.push_back(findSize(0, n - 1, n));
                groups.insert({0, n - 1});
            } else {
                int cur = (start + 1) % n;
                while (cur != start && colors[cur] != colors[(cur + n - 1) % n])
                    cur = (cur + 1) % n;
                groups.insert({start, (cur - 1 + n) % n});
                sizes.push_back(findSize(start, (cur - 1 + n) % n, n));

                while (cur != start) {
                    int next = (cur + 1) % n;
                    while (next != start && colors[next] != colors[(next - 1 + n) % n])
                        next = (next + 1) % n;
                    // cur....next-1 is one group
                    groups.insert({cur, (next - 1 + n) % n});
                    sizes.push_back(findSize(cur, (next - 1 + n) % n, n));
                    cur = next;
                }
            }
        }
        // create segment tree for querying
        // max group size is n
        SegTree segTree(sizes, n);
        vector<int> sizesCount = sizes;  // sizes was modified inside the segTree to contain the sizeCounters
        vector<int> ans;
        vector<pair<int, int>> toRemove;  // clear after every query
        vector<pair<int, int>> toAdd;     // clear after every query

        auto removeSegment = [&](const pair<int, int> &segment) {
            int segmentSize = findSize(segment, n);
            int currentCount = sizesCount[segmentSize];
            sizesCount[segmentSize]--;
            segTree.update(segmentSize, sizesCount[segmentSize]);
            toRemove.push_back(segment);
        };

        auto addSegment = [&](const pair<int, int> &segment) {
            int segmentSize = findSize(segment, n);
            int currentCount = sizesCount[segmentSize];
            sizesCount[segmentSize]++;
            segTree.update(segmentSize, sizesCount[segmentSize]);
            toAdd.push_back(segment);
        };

        auto getPreviousSegment = [&](const set<pair<int, int>>::iterator &it) -> set<pair<int, int>>::iterator {
            if (it == groups.begin())
                return --groups.end();
            auto previousIterator = it;
            previousIterator--;
            return previousIterator;
        };

        auto getNextSegment = [&](const set<pair<int, int>>::iterator &it) -> set<pair<int, int>>::iterator {
            auto nextIterator = it;
            nextIterator++;
            if (nextIterator == groups.end())
                nextIterator = groups.begin();
            return nextIterator;
        };

        for (auto &query : queries) {
            int queryType = query[0];
            if (queryType == 1) {
                int queryGroupSize = query[1];
                if (groups.size() == 1) {
                    auto &[groupLeft, groupRight] = *groups.begin();
                    if (colors[groupLeft] != colors[groupRight]) {
                        // special case, only one single group is present and the array itself is one whole alternating wheel with no specific starting point
                        // here, the answer would be the number of subarrays in circular array of size queryGroupSize
                        ans.push_back(n);  // because we can take any point as the starting point
                        continue;
                    }
                }
                // ans = sum of groupSize*countOfThisGroupSize - numGroups * queryGroupSize + numGroups where groupSize >= queryGroupSize
                auto [sizeCountSum, numGroups] = segTree.query(queryGroupSize);
                ans.push_back(sizeCountSum - numGroups * queryGroupSize + numGroups);
            } else {
                int index = query[1], color = query[2];
                if (colors[index] == color)
                    continue;

                // step1: find the segment containing this index
                auto currentSegment = groups.upper_bound(make_pair(index, INT_MAX));
                currentSegment = getPreviousSegment(currentSegment);

                // step2: break this segment down. all segments in the groups set are continous.
                removeSegment(*currentSegment);
                auto &[groupLeft, groupRight] = *currentSegment;

                // special case when there is only one segment and it is already a full wheel with all alternating colors
                if (groups.size() == 1 && colors[groupLeft] != colors[groupRight]) {
                    // in this case, no matter where we flip the bit. it will always break into two parts instead of the usual three
                    // 1010101010 --->  10101 1 1010
                    //      ^           >---- - --->
                    addSegment({index, index});
                    addSegment({(index + 1) % n, (index - 1 + n) % n});
                } else if (groupLeft == groupRight) {
                    // only one element in segment. This will connect the left and right segments
                    auto previousSegment = getPreviousSegment(currentSegment);
                    auto nextSegment = getNextSegment(currentSegment);
                    int currentIndex = groupLeft;
                    if (*previousSegment == *nextSegment) {
                        // there are only two groups available out of which the current group contains only 1 element. hence it will form 1 group of all elements
                        // 1010101   1
                        removeSegment(*previousSegment);
                        addSegment({previousSegment->first, currentIndex});
                    } else {
                        // more than two other segments, hence we can remove both of them
                        removeSegment(*previousSegment);
                        removeSegment(*nextSegment);
                        addSegment({previousSegment->first, nextSegment->second});
                    }
                } else if (index != groupLeft && index != groupRight) {
                    // the position where the color was flipped was in between an existing group. hence this group will divide into three parts
                    addSegment(make_pair(groupLeft, (index - 1 + n) % n));
                    addSegment(make_pair(index, index));
                    addSegment(make_pair((index + 1) % n, groupRight));
                } else if (index == groupLeft) {
                    // this means we go from 010 01010 to 0101 1010
                    //                           ^
                    auto previousSegment = getPreviousSegment(currentSegment);
                    if (*previousSegment == *currentSegment) {  // this would only happen if there are only one segment available and we are changing the extreme point
                        if (colors[groupLeft] == colors[groupRight]) {
                            // the segment will just shift start and end points
                            // 0 101010  to // 110101 0
                            // s      e        es
                            addSegment({(index + 1) % n, index});
                        } else {
                            // 0 10101  to // 1 10101
                            // s     e        - -----
                            addSegment({groupLeft, index});  // index == groupLeft, so segment containing only one element
                            // now, after breaking, the current segment will be from groupLeft to index-1
                            addSegment({(index + 1) % n, groupRight});
                        }
                    } else {
                        // previousSegment will be extended
                        // 10101 10101  --->  101010 0101
                        //       ^                 ^
                        
                        removeSegment(*previousSegment);
                        addSegment({previousSegment->first, index});
                        // now, after breaking the second segment will be from index+1 to groupRight
                        addSegment({(index + 1) % n, groupRight});
                    }
                } else {
                    // index is at the rightmost end of the segment
                    // this means we go from 010 01010 to 0101 1010
                    //                         ^
                    auto nextSegment = getNextSegment(currentSegment);
                    if (*nextSegment == *currentSegment) {  // this would only happen if there are only one segment available and we are changing the extreme point
                        if (colors[groupLeft] == colors[groupRight]) {
                            // the segment will just shift start and end points
                            // 010101 0  to // 010101 1
                            // s      e             e s
                            addSegment({index, (index - 1 + n) % n});
                        } else {
                            addSegment({index, groupRight});  // index == groupRight, so segment containing only one element
                            // now, after breaking, the current segment will be from groupLeft to index-1
                            addSegment({groupLeft, (index - 1 + n) % n});
                        }
                    } else {
                        // nextSegment will be extended
                        removeSegment(*nextSegment);
                        addSegment({index, nextSegment->second});
                        // now, after breaking, the current segment will be from groupLeft to index-1
                        addSegment({groupLeft, (index - 1 + n) % n});
                    }
                }

                // After changing of segments is done, remove and add the required segments to the groups set
                for (auto &removeSegment : toRemove) {
                    groups.erase(removeSegment);
                }
                for (auto &addSegment : toAdd) {
                    groups.insert(addSegment);
                }
                toRemove.clear();
                toAdd.clear();

                // color is flipped for index
                colors[index] = color;
            }
        }
        return ans;
    }
};
int main() {
    {
        Solution sol;
        vector<int> colors = {0, 1, 1, 0, 1};
        vector<vector<int>> queries = {{2, 1, 0}, {1, 4}};
        vector<int> ans = sol.numberOfAlternatingGroups(colors, queries);
        debug(ans);
    }
    {
        Solution sol;
        vector<int> colors = {0, 0, 1, 0, 1, 1};
        vector<vector<int>> queries = {{1, 3}, {2, 3, 0}, {1, 5}};
        vector<int> ans = sol.numberOfAlternatingGroups(colors, queries);
        debug(ans);
    }
    {
        Solution sol;
        vector<int> colors = {0, 0, 0, 1};
        vector<vector<int>> queries = {{2, 1, 1}, {1, 3}, {2, 1, 1}, {2, 0, 1}};
        vector<int> ans = sol.numberOfAlternatingGroups(colors, queries);
        debug(ans);
    }
    {
        Solution sol;
        vector<int> colors = {0, 1, 0, 1};
        vector<vector<int>> queries = {{1, 3}, {2, 2, 1}, {1, 3}, {1, 3}};
        vector<int> ans = sol.numberOfAlternatingGroups(colors, queries);
        debug(ans);
    }
    {
        Solution sol;
        vector<int> colors = {1, 1, 1, 0, 1};
        vector<vector<int>> queries = {{1, 4}, {2, 1, 0}, {1, 3}, {1, 4}};
        vector<int> ans = sol.numberOfAlternatingGroups(colors, queries);
        debug(ans);
    }
    {
        Solution sol;
        vector<int> colors = {0, 1, 0, 1, 0};
        vector<vector<int>> queries = {{2, 0, 1}, {2, 4, 1}, {2, 2, 1}, {1, 4}, {2, 1, 0}, {1, 3}};
        vector<int> ans = sol.numberOfAlternatingGroups(colors, queries);
        debug(ans);
    }
}
/*
0 1 0 0 1 0 1 1 0 1 0  0  0  1
0 1 2 3 4 5 6 7 8 9 10 11 12 13
----- ------- -------  -  ----
*/