#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    bool isPower(int number, const int &base) {
        while (number > 1 && number % base == 0)
            number /= base;
        return number == 1;
    }

   public:
    int minPatches(const vector<int> &nums, int n) {
        using ll = long long;
        ll curMax = 0, ans = 0, i = 0;
        while (curMax < n) {
            ll needed = curMax + 1;
            if (i == nums.size()) {
                curMax += needed;
                ans++;
                continue;
            }
            ll num = nums[i];
            if (num == needed) {
                curMax += num;
                i++;
            } else if (num > needed) {
                curMax += needed;
                ans++;
            } else {
                curMax += num;
                i++;
            }
        }
        return ans;
    }
};

void solve() {
    Solution sol;
    cout << sol.minPatches({1, 2, 31, 33}, 2147483647);
}

int main() {
    solve();
}