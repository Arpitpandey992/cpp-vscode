#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>  //prefer this over map
#include <vector>
using namespace std;
#define M 1000000007
#define M2 998244353
#define nl cout << '\n'
#define fout fflush(stdout)
#define us unsigned short
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ld long double
#define ul unsigned long
//#define endl '\n'
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define paus      \
    cout << endl; \
    system("pause");
ll temp;
#define fok(i, k, n) for (ll i = k; i < n; i++)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = n; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define Sort(v) sort(all(v))
#define Sortg(v) sort(all(v), greater<int>())
#define bs(v, val) binary_search(all(v), val)
#define lb(v, val) lower_bound(all(v), val)
#define ub(v, val) upper_bound(all(v), val)
#define watch(x) cout << endl \
                      << (#x) << " is " << (x) << endl
#define inpt(v)      \
    {                \
        cin >> temp; \
        v.pb(temp);  \
    }
#define fastio ios_base::sync_with_stdio(false);
//cin.tie(NULL);                    \
//cout.tie(NULL); // to get output after all input is done
#define test    \
    ui tes;     \
    cin >> tes; \
    while (tes--)
//--------------------------------------------------------------------//
unsigned long long raand()  //use raand() %x+y for numbers in (y,x)
{
    unsigned long long randnumber = 0;
    int digits[20];

    for (int i = 19; i >= 1; i--) {
        digits[i] = rand() % 10;
    }
    for (int i = 19; i >= 1; i--) {
        unsigned long long power = pow(10, i - 1);

        if (power % 2 != 0 && power != 1)  //eliminates "bug" (which comes from long long power is not a float))
            power++;

        randnumber += power * digits[i];
    }
    return randnumber;
}
template <class T1, class T2, class T3>
constexpr ll mode_exp(ll a, ll b, ll c)  //Precise Pow() (a^b)%c
{
    ll res = 1;
    a = a % c;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % c;
        }
        b /= 2;
        a = (a * a) % c;
    }
    return res;
}
constexpr ll pow2(ll a, ll b)  //Precise Pow() for integers only
{
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a);
        }
        b >>= 1;
        a = a * a;
    }
    return res;
}
bool prime[200001];  //Till n= 2*10^5
void SieveOfEratosthenes(ll n) {
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
ll modinv(ll a, ll m)  //Finding Mod inverse of a under mod m
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x % m + m) % m;
    return res;
}
struct hash_pair  //use like unordered_map <pii, int, hash_pair> m;
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
//--------------------------------------------------------------------//
int a[61][61];
void ch(int i1, int j1, int i2, int j2, int n) {
    if (i1 == i2 && j1 == j2) {
        a[i1][j1] = n;
        return;
    }
    if (n <= 0) {
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                a[i][j] = 0;
            }
        }
        return;
    }
    if (abs(i1 - i2) <= abs(j1 - j2)) {
        int mid = (j1 + j2) / 2, nt;
        cout << 1 << " " << i1 << " " << mid + 1 << " " << i2 << " " << j2 << endl;
        cin >> nt;
        if (nt == (i2 - i1 + 1) * (j2 - (mid + 1) + 1))
            for (int i = i1; i <= i2; i++)
                for (int j = mid + 1; j <= j2; j++)
                    a[i][j] = 1;
        else
            ch(i1, mid + 1, i2, j2, nt);
        if (n - nt == (i2 - i1 + 1) * (mid - j1 + 1))
            for (int i = i1; i <= i2; i++)
                for (int j = j1; j <= mid; j++)
                    a[i][j] = 1;
        else
            ch(i1, j1, i2, mid, n - nt);

        return;
    } else {
        int mid = (i1 + i2) / 2, nt;
        cout << 1 << " " << mid + 1 << " " << j1 << " " << i2 << " " << j2 << endl;
        cin >> nt;
        if (nt == (i2 - (mid + 1) + 1) * (j2 - j1 + 1))
            for (int i = mid + 1; i <= i2; i++)
                for (int j = j1; j <= j2; j++)
                    a[i][j] = 1;
        else
            ch(mid + 1, j1, i2, j2, nt);
        if (n - nt == (mid - i1 + 1) * (j2 - j1 + 1))
            for (int i = i1; i <= mid; i++)
                for (int j = j1; j <= j2; j++)
                    a[i][j] = 1;
        else
            ch(i1, j1, mid, j2, n - nt);

        return;
    }
}

int main() {
    test {
        int n, p;
        cin >> n >> p;

        fo(i, 61) fo(j, 61) a[i][j] = -1;
        int nt;
        cout << 1 << " " << 1 << " " << 1 << " " << n << " " << n << endl;
        cin >> nt;
        ch(1, 1, n, n, nt);
        cout << 2 << endl;
        fo(i, n) {
            fo(j, n) cout << a[i + 1][j + 1] << " ";
            cout << endl;
        }
        int x;
        cin >> x;
        if (x == -1) return 0;
    }
}