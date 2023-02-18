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
void ans16(int &n, vi adj[], vi &a) {
    int q;
    cin >> q;
    int ans = 0;
    while (q--) {
        int d, x;
        cin >> x >> d;
        x ^= ans;
        d ^= ans;
        list<int> q;
        q.pb(x);
        vi dep(n + 1, 0);
        set<int> unq;
        while (!q.empty()) {
            int t = q.front();
            q.pop_front();
            if (dep[t] > d) break;
            unq.insert(a[t]);
            for (auto x : adj[t]) {
                q.pb(x);
                dep[x] = dep[t] + 1;
            }
        }
        ans = unq.size();
        cout << ans << endl;
    }
}

#define N 15
int *arr;
class wavelet_tree {
   public:
    int low, high;
    wavelet_tree *l, *r;
    vector<int> freq;
    wavelet_tree(int *from, int *to, int x, int y) {
        low = x, high = y;
        if (from >= to || high == low)
            return;
        int mid = (low + high) / 2;
        auto lessThanMid = [mid](int x) {
            return x <= mid;
        };
        freq.reserve(to - from + 1);
        freq.push_back(0);
        for (auto it = from; it != to; it++)
            freq.push_back(freq.back() + lessThanMid(*it));
        auto pivot = stable_partition(from, to, lessThanMid);
        l = new wavelet_tree(from, pivot, low, mid);
        r = new wavelet_tree(pivot, to, mid + 1, high);
    }
    int query(int l, int r, int k) {
        if ((l > r) || (k > high))
            return 0;
        if (low >= k)
            return r - l + 1;
        int LtCount = freq[l - 1];
        int RtCount = freq[r];
        return (this->l->query(LtCount + 1, RtCount, k) +
                this->r->query(l - LtCount, r - RtCount, k));
    }
};

void ans24(int &n, vi &a) {
    arr = new int[n + 1];
    vi m(n + 1, -1);
    for (int i = n; i >= 1; i--) {
        if (m[a[i]] == -1) {
            m[a[i]] = i;
            arr[i] = n + 1;
        } else {
            arr[i] = m[a[i]];
            m[a[i]] = i;
        }
    }
    wavelet_tree obj(arr + 1, arr + (n + 1), 1, n + 1);
    int q;
    cin >> q;
    int ans = 0;
    while (q--) {
        int d, x;
        cin >> x >> d;
        x ^= ans;
        d ^= ans;
        if (x + d > n) d = n - x;
        ans = obj.query(x, x + d, x + d + 1);
        cout << ans << endl;
    }
}

int main() {
    fastio;
    //srand(time(NULL));
    test {
        int n;
        cin >> n;
        vi adj[n + 1];
        fok(i, 2, n + 1) {
            int p;
            cin >> p;
            adj[p].pb(i);
        }
        vi a(n + 1);
        a[0] = 0;
        fok(i, 1, n + 1) cin >> a[i];

        bool flag = 1;
        int t = 1;
        while (!adj[t].empty()) {
            if (adj[t].size() > 1) {
                flag = 0;
                break;
            }
            t = adj[t][0];
        }
        if (flag)
            ans24(n, a);
        else
            ans16(n, adj, a);
    }
}