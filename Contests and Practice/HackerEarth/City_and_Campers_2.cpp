const int INF = 2147483647 / 4;
#include <iostream>
#include <vector>
using namespace std;
class DSU {
   private:
    int n;  // Elements present are from 0 to n-1
    vector<int> par, size;

   public:
    int totalSets;
    DSU(int n) {
        this->n = n;
        totalSets = n;
        par.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    int fin(int a) {
        if (par[a] == a)
            return a;
        return par[a] = fin(par[a]);
    }
    bool uni(int a, int b) {
        a = fin(a);
        b = fin(b);
        if (a == b) return false;
        if (size[a] < size[b]) {
            par[a] = b;
            size[b] += size[a];
        } else {
            par[b] = a;
            size[a] += size[b];
        }
        totalSets--;
        return true;
    }
    int getGroupSize(int a) {
        return size[fin(a)];
    }
    void clear() {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }
        totalSets = n;
    }
};

class SegTree {
    // query(l,r) will give the left most element which is > 0 from l to r, rightMostElement, minDiff in l...r
    int n;
    vector<int>* a;
    vector<tuple<int, int, int>> st;

   public:
    SegTree(vector<int>& arr) {
        this->a = &arr;
        this->n = a->size();
        this->st.resize(4 * n);

        this->build(0, n - 1, 0);
    }

    int query(const int& l, const int& r) {
        auto [_1, _2, minDiffInRange] = this->_query(l, r, 0, n - 1, 0);
        return minDiffInRange;
    }

    void update(const int& index, const int& newValue) {
        (*a)[index] = newValue;
        this->_update(index, 0, n - 1, 0);
    }

   private:
    void _update(int index, int sl, int sr, int si) {
        if (sl == sr) {
            if ((*a)[sl] > 0) {
                st[si] = {sl, sl, (*a)[sl] > 1 ? 0 : INF};
            } else {
                st[si] = {-1, -1, INF};
            }
            return;
        }
        int mid = (sl + sr) / 2;
        if (index <= mid)
            _update(index, sl, mid, si * 2 + 1);
        else
            _update(index, mid + 1, sr, si * 2 + 2);
        st[si] = joinSegmentResults(st[si * 2 + 1], st[si * 2 + 2]);
    }

    tuple<int, int, int> _query(int l, int r, int sl, int sr, int si) {
        if (l > sr || r < sl)
            return {-1, -1, INF};
        if (sl >= l && sr <= r)
            return st[si];
        int mid = (sl + sr) / 2;
        auto left = _query(l, r, sl, mid, si * 2 + 1);
        auto right = _query(l, r, mid + 1, sr, si * 2 + 2);
        return joinSegmentResults(left, right);
    }

    void build(int sl, int sr, int si) {
        if (sl == sr) {
            if ((*a)[sl] > 0) {
                st[si] = {sl, sl, (*a)[sl] > 1 ? 0 : INF};
            } else {
                st[si] = {-1, -1, INF};
            }
            return;
        }
        int mid = (sl + sr) / 2;

        build(sl, mid, si * 2 + 1);
        build(mid + 1, sr, si * 2 + 2);
        st[si] = joinSegmentResults(st[si * 2 + 1], st[si * 2 + 2]);
    }

    tuple<int, int, int> joinSegmentResults(const tuple<int, int, int>& left, const tuple<int, int, int>& right) {
        auto& [leftLeftIndex, leftRightIndex, leftMinDiff] = left;
        auto& [rightLeftIndex, rightRightIndex, rightMinDiff] = right;
        if (leftLeftIndex == -1) {
            // there is no non zero value in left segment
            return right;
        } else if (rightLeftIndex == -1) {
            // there is no non zero value in left segment
            return left;
        }
        // there is at least one element in both left and right segments
        int minVal = min(min(leftMinDiff, rightMinDiff), rightLeftIndex - leftRightIndex);
        return {leftLeftIndex, rightRightIndex, minVal};
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    vector<int> groupSizeCount(n + 1, 0);
    groupSizeCount[1] = n;
    SegTree segTree(groupSizeCount);

    auto getAnswer = [&]() -> int {
        if (groupSizeCount[n] == 1)
            return 0;
        return segTree.query(1, n - 1);  // groups of size zero will never be considered
    };

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (dsu.fin(u) == dsu.fin(v)) {
            cout << getAnswer() << endl;
            continue;
        }
        int group1Size = dsu.getGroupSize(u), group2Size = dsu.getGroupSize(v);
        segTree.update(group1Size, groupSizeCount[group1Size] - 1);
        segTree.update(group2Size, groupSizeCount[group2Size] - 1);
        segTree.update(group1Size + group2Size, groupSizeCount[group1Size + group2Size] + 1);
        dsu.uni(u, v);
        cout << getAnswer() << endl;
    }
}

int main() {
    solve();
}