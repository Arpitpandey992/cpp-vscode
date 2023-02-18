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

int main() {
    //srand(time(0));
    fastio;
    int t;
    cin >> t;
    clock_t tStart = clock();
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> *adj;
        adj = new vector<int>[n + 1];
        fo(i, m) {
            int xx, yy;
            /* xx = raand() % n + 1;
            yy = raand() % n + 1;
            while (yy == xx)
                yy = raand() % n + 1; */
            cin >> xx >> yy;
            adj[xx].pb(yy);
            adj[yy].pb(xx);
        }
        vector<vpii> fedges, nedges;  // free edges and not free edges
        vpii fedge, nedge;            //count of those edges
        int i, k = 0;
        vi singles;
        vb visited(n + 1, false);
        map<pii, bool> mm;
        for (i = 1; i <= n; i++) {
            if (adj[i].empty()) {
                singles.pb(i);
                //visited[i] = true;
            } else {
                if (!visited[i]) {
                    visited[i] = true;
                    list<int> q;
                    q.pb(i);
                    vpii fed, ned;
                    while (!q.empty()) {
                        int t = q.front();
                        q.pop_front();
                        for (auto x : adj[t]) {
                            if (!visited[x]) {
                                visited[x] = true;
                                q.pb(x);
                                ned.pb(mp(t, x));
                                mm[mp(t, x)] = true;
                            } else {
                                if (mm.find(mp(t, x)) == mm.end()) {
                                    if (mm.find(mp(x, t)) == mm.end()) {
                                        fed.pb(mp(t, x));
                                        mm[mp(t, x)] = true;
                                    }
                                } else
                                    fed.pb(mp(t, x));
                            }
                        }
                    }
                    if (fed.size() != 0)
                        fedge.pb(mp(fed.size(), k));
                    else
                        nedge.pb(mp(ned.size(), k));
                    fedges.pb(fed);
                    nedges.pb(ned);
                    k++;
                }
            }
        }
        // Reconstructing Free Edges :
        int ans = 0;
        if (fedge.size()) {
            int fno = fedge.back().ss;
            vpii p = fedges[fno];
            fedge.pop_back();
            while (!fedge.empty()) {
                int nno = fedge.back().ss;
                fedge.pop_back();
                pii p1 = p.back(), p2 = nedges[nno].back();
                fedges[fno].pop_back();
                nedges[nno].pop_back();
                p.pop_back();
                //Merging
                nedges[fno].pb(mp(p1.ff, p2.ff));
                nedges[fno].pb(mp(p1.ss, p2.ss));
                for (auto q : fedges[nno]) {
                    fedges[fno].pb(q);
                    p.pb(q);
                }
                fedges[nno].clear();
            }
            while (!p.empty() && !nedge.empty()) {
                int nno = nedge.back().ss;
                nedge.pop_back();
                pii p1 = p.back(), p2 = nedges[nno].back();
                fedges[fno].pop_back();
                nedges[nno].pop_back();
                p.pop_back();
                //Merging
                nedges[fno].pb(mp(p1.ff, p2.ff));
                nedges[fno].pb(mp(p1.ss, p2.ss));
            }
            while (!nedge.empty()) {
                int nno = nedge.back().ss;
                nedge.pop_back();
                pii p1 = nedges[fno].back(), p2 = nedges[nno].back();
                //Merging
                nedges[fno].pb(mp(p1.ff, p2.ff));
                ans += 2;
            }
            while (singles.size() >= 2 && !p.empty()) {
                int a = singles.back();
                singles.pop_back();
                int b = singles.back();
                singles.pop_back();
                pii p1 = p.back();
                fedges[fno].pop_back();
                p.pop_back();
                //Merging
                nedges[fno].pb(mp(p1.ff, a));
                nedges[fno].pb(mp(p1.ss, b));
                ans += 2;
            }
            while (!singles.empty()) {
                int a = singles.back();
                singles.pop_back();
                pii p1 = nedges[fno].back();
                nedges[fno].pb(mp(p1.ff, a));
                ans += 2;
            }
        } else if (nedge.empty()) {
            int a = singles.back();
            singles.pop_back();
            vpii p;
            while (!singles.empty()) {
                int b = singles.back();
                singles.pop_back();
                p.pb(mp(a, b));
                ans += 2;
            }
            if (!p.empty())
                nedges.pb(p);
            else {
                cout << 0 << " " << 0 << endl;
                return 0;
            }
        } else if (singles.empty()) {
            int fno = nedge.back().ss;
            nedge.pop_back();
            while (!nedge.empty()) {
                int nno = nedge.back().ss;
                nedge.pop_back();
                pii p1 = nedges[fno].back(), p2 = nedges[nno].back();
                //Merging
                nedges[fno].pb(mp(p1.ff, p2.ff));
                ans += 2;
            }
        } else {
            int fno = nedge.back().ss;
            nedge.pop_back();
            while (!nedge.empty()) {
                int nno = nedge.back().ss;
                nedge.pop_back();
                pii p1 = nedges[fno].back(), p2 = nedges[nno].back();
                //Merging
                nedges[fno].pb(mp(p1.ff, p2.ff));
                ans += 2;
            }
            while (!singles.empty()) {
                pii p1 = nedges[fno].back();
                int b = singles.back();
                singles.pop_back();
                nedges[fno].pb(mp(p1.ff, b));
                ans += 2;
            }
        }
        vpii ansp;
        for (auto x : fedges)
            ansp.insert(ansp.end(), x.begin(), x.end());
        for (auto x : nedges)
            ansp.insert(ansp.end(), x.begin(), x.end());
        cout << ans << " " << ansp.size() << endl;
        for (auto x : ansp) cout << x.ff << " " << x.ss << endl;
    }
    exectime(tStart);
}
/* 
Test Cases:
ans = 4 :
1
14 16
1 2 2 3 1 2 1 2 2 3 1 3 4 5 5 6 4 5 5 6 4 6 7 8 7 8 7 8 9 10 9 10 
ans = 0 :
1
6 5
1 2 1 2 3 4 3 4 5 6
ans = 4 :
1
14 11
1 2 2 3 1 2 1 3 4 5 6 5 7 5 10 9 9 11 11 9 8 14
ans = 8:
1
10 5
2 3 3 8 3 10 10 7 5 9
*/