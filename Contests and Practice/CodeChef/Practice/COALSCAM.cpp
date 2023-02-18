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
#define INF 922337203
#define nl cout << '\n'
#define fout fflush(stdout)
#define us unsigned short
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ld long double
#define ul unsigned long
#define endl '\n'
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
int finnd(int u, vi &par) {
    if (par[u] != u)
        par[u] = finnd(par[u], par);
    return par[u];
}
void unnion(int u, int v, vi &par, vi &rank) {
    int paru = finnd(u, par), parv = finnd(v, par);
    if (rank[paru] > rank[parv]) {
        par[parv] = paru;
    } else if (rank[paru] < rank[parv]) {
        par[paru] = parv;
    } else {
        par[paru] = parv;
        rank[parv]++;
    }
}

int main() {
    fastio;
    test {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        vector<pair<ll, pair<int, int>>> v1, v2;
        fo(i, m1) {
            ll c, u, v;
            cin >> u >> v >> c;
            v1.pb(mp(c, mp(u, v)));
        }
        fo(i, m2) {
            ll c, u, v;
            cin >> u >> v >> c;
            v2.pb(mp(c, mp(u, v)));
        }
        sort(all(v1));
        sort(all(v2));
        reverse(all(v2));
        ll ans1 = 0, ans2 = 0;
        vector<int> par(n), rank(n, 0);
        fo(i, n) par[i] = i;
        for (auto x : v2) {
            ll c = x.ff;
            int u = (x.ss).ff, v = (x.ss).ss;
            if (finnd(u, par) != finnd(v, par)) {
                unnion(u, v, par, rank);
                ans1 += c;
            }
        }
        ans2 = ans1;
        for (auto x : v1) {
            ll c = x.ff;
            int u = (x.ss).ff, v = (x.ss).ss;
            if (finnd(u, par) != finnd(v, par)) {
                unnion(u, v, par, rank);
                ans2 += c;
            }
        }
        bool flag = 1;
        int part = finnd(0, par);
        for (int i = 1; i < n; i++) {
            if (finnd(i, par) != part) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << ans1 << " " << ans2 << endl;
        } else
            cout << "Impossible\n";
    }
}