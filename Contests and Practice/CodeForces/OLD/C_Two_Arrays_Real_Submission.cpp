#include <bits/stdc++.h>
#define fors for (int i = 0; i < s.size(); i++)
#define lli long long int
#define mod 1000000007
#define ull unsigned long long
#define forin for (lli i = 0; i < n; i++)
#define testcase \
    int t;       \
    cin >> t;    \
    while (t--)
#define mp make_pair
#define ff first
#define ss second
using namespace std;
const int M = 1000000007;
int modadd(int a, int b, int m = M) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
int modsub(int a, int b, int m = M) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
//start with 1,1

int DP[1001][1001][11];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            DP[i][j][1] = 1;
        }
    }  // initialising first layer
    for (int k = 2; k <= m; k++) {
        int colsum[n + 1] = {0};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                colsum[i] = modadd(colsum[i], DP[j][i][k - 1]);
            }
        }
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = 1; j <= n; j++) {
                sum = modadd(sum, colsum[j]);
                colsum[j] = modsub(colsum[j], DP[i][j][k - 1]);
                DP[i][j][k] = sum;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum = modadd(sum, DP[i][j][m]);
        }
    }
    cout << sum << endl;
}