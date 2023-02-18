#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = 0x7fffffff;
#define f(i, a, b) for (int i = a; i < b; i++)
#define fd(i, a, b) for (int i = a; i > b; i--)
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ret return
#define HACK                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define RT                                         \
    double rtime = 1.0 * clock() / CLOCKS_PER_SEC; \
    cout << "\nRuntime: " << rtime << " s.\n";
#define debug(x) cout << "target is " << x << endl
// #define LOCAL_JUDGE
// #pragma GCC optimize(2)

int main() {
    IOS;

    HACK;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        bool fg = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j] && (a[i] + a[j]) % 2 == 0) {
                    fg = 1;
                    break;
                }
            }
            if (fg) break;
        }

        if (!fg)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

#ifdef LOCAL_JUDGE
    RT;
#endif
    ret 0;
}
