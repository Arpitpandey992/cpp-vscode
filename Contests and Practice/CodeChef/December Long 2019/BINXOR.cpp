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
#include <unordered_set>
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
#define exectime(t) cout << "Total Time taken: "                   \
                         << (double)(clock() - t) / CLOCKS_PER_SEC \
                         << "s" << endl;
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

ull bitw(string a) {
    ull temp = 0;
    for (ull i = 0; i <= (a.size() - 1); i++) {
        ull t1 = long(a[i] - '0');
        //cout << t1 << endl;
        temp += (t1 * pow(2, (a.size() - i - 1)));
    }
    return temp;
}
ull add(ull a, ull b) {
    ull ct = 0;
    while (b > 0) {
        ull u = a ^ b;
        ull v = a & b;
        a = u;
        b = (v * 2);
        ct++;
    }
    return ct;
}

int main() {
    srand(NULL);
    test {
        string a, b;
        fo(i, 32) {
            int x = rand() % 2, y = rand() % 2;
            char aa = '0' + x, bb = '0' + y;
            a += aa;
            b += bb;
        }
        ull b1 = bitw(b), a1 = bitw(a);
        ll ans1 = add(a1, b1) << endl;

        int n = a.size(), m = b.size();
        ll ans = 0, flag = 0;
        reverse(all(a));
        reverse(all(b));
        fo(i, m) if (b[i] == '1') {
            flag = 1;
            break;
        }
        if (n > m) {
            for (int i = n; i > m; i--)
                b.pb('0');
        } else if (n < m)
            for (int i = m; i > n; i--)
                a.pb('0');
        n = max(n, m);
        m = n;
        int ans2;
        if (flag) {
            ans = 1;
            vll anss(1, 1);
            flag = 0;
            for (int i = 0, j = 0; i < n; i++, j++) {
                if (flag == 1) {
                    if (a[i] == b[i]) {
                        anss.pb(ans);
                        ans = 1;
                        flag = 0;
                    } else {
                        ans++;
                    }
                } else {
                    if (a[i] == '1' && b[j] == '1') {
                        ans++;
                        flag = 1;
                    }
                }
            }
            anss.pb(ans);
            ans2 = *(max_element(all(anss)));
        } else {
            ans2 = 0;
        }
        cout << ans1 << " " << ans2 << endl;
        if (ans1 != ans2) {
            cout << a << endl
                 << b << endl;
        }
    }
}