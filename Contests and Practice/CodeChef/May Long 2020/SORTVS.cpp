#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map> //prefer this over map
#include <vector>
using namespace std;
#define M 1000000007
#define M2 998244353
#define nl cout << '\n'
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
#define paus system("pause");
ll temp;
#define fok(i, k, n) for (ll i = k; i < n; i++)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define Fo(i, n) for (ll i = n; i >= 0; i--)
#define Sort(v) sort(v.begin(), v.end())
#define Sortg(v) sort(v.begin(), v.end(), greater<int>())
#define bs(v, val) binary_search(v.begin(), v.end(), val)
#define lb(v, val) lower_bound(v.begin(), v.end(), val)
#define ub(v, val) upper_bound(v.begin(), v.end(), val)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define inpt(v)      \
    {                \
        cin >> temp; \
        v.pb(temp);  \
    }
#define fastio ios_base::sync_with_stdio(false);
//cin.tie(NULL);                    \
//cout.tie(NULL); // to get output after all input is done
#define test    \
    ul tes;     \
    cin >> tes; \
    while (tes--)
//----------------------------------------------------------------------------------//
unsigned long long raand() //use raand() %x+y for numbers in (y,x)
{
    unsigned long long randnumber = 0;
    int digits[20];

    for (int i = 19; i >= 1; i--)
    {
        digits[i] = rand() % 10;
    }
    for (int i = 19; i >= 1; i--)
    {
        unsigned long long power = pow(10, i - 1);

        if (power % 2 != 0 && power != 1) //eliminates "bug" (which comes from long long power is not a float))
            power++;

        randnumber += power * digits[i];
    }
    return randnumber;
}
template <class T1, class T2, class T3>
constexpr ll mode_exp(ll a, ll b, ll c) //Precise Pow() (a^b)%c
{
    ll res = 1;
    a = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % c;
        }
        b /= 2;
        a = (a * a) % c;
    }
    return res;
}
constexpr ll pow2(ll a, ll b) //Precise Pow() for integers only
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a);
        }
        b /= 2;
    }
    return res;
}
bool prime[200001]; //Till n= 2*10^5
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int p = 2; p * p <= 200000; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= 200000; i += p)
                prime[i] = false;
        }
    }
    return;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
ll modinv(ll a, ll m) //Finding Mod inverse of a under mod m
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x % m + m) % m;
    return res;
}
//----------------------------------------------------------------------------------//

void DFS(bool dfs[], int node, vi &a, vi adj[], bool visited[])
{
    visited[node] = true;
    dfs[node] = true;
    a.pb(node);
    for (auto x : adj[node])
    {
        if (!visited[x])
        {
            DFS(dfs, x, a, adj, visited);
        }
    }
}
int w[19][19];
bool notvisited(int x, vi path)
{
    for (auto y : path)
        if (y == x)
            return false;
    return true;
}
vvi BFS(int node, vi adj[], int nf, int pl)
{
    vvi paths;
    vi path;
    path.pb(node);
    list<vi> q;
    q.push_back(path);
    int i = pl;
    while (!q.empty())
    {
        path = q.front();
        q.pop_front();
        int last = path[path.size() - 1];
        if (path.size() == pl + 1)
            paths.pb(path);
        else
        {
            for (auto x : adj[last])
            {
                if (notvisited(x, path))
                {
                    vi newpath(path);
                    newpath.pb(x);
                    q.push_back(newpath);
                }
            }
        }
    }
    return paths;
}
bool sets(int i, vi p)
{
    return (i == p[i]);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vi p;
        p.pb(0);
        bool dfs[n + 1] = {0};
        fo(i, n)
        {
            inpt(p);
        }
        vi adj[n + 1];
        fo(i, m)
        {
            int xx, yy;
            cin >> xx >> yy;
            adj[xx].pb(yy);
            adj[yy].pb(xx);
        }
        int cost = 0;
        vvi family;
        int fam[n + 1];
        for (int i = 1, k = 0; i <= n; i++)
        {
            if (!dfs[i])
            {
                vi a;
                bool visited[n + 1] = {0};
                DFS(dfs, i, a, adj, visited);
                Sort(a);
                family.pb(a);
                for (int j = 0; j < a.size(); j++)
                    fam[a[j]] = k;
                k++;
            }
        }
        int nf = family.size();
        vi adj2[nf];

        fo(i, nf)
            fo(j, nf)
                w[i][j] = 0;
        for (int i = 0; i < nf; i++)
        {
            vi temp;
            for (auto x : family[i])
            {
                if (fam[p[x]] != i)
                    temp.pb(fam[p[x]]);
            }
            Sort(temp);
            int xbef = -1;
            for (auto x : temp)
            {
                if (x != xbef)
                {
                    adj2[i].pb(x);
                    xbef = x;
                }
                w[i][x]++;
            }
        }
        for (int i = 0; i < nf; i++)
        {
            for (int j = 1; j < nf; j++)
            {
                vvi paths = BFS(i, adj2, nf, j);
                for (vi path : paths)
                {
                    int crawl = path.back();
                    int minw = 100000;
                    if (bs(adj2[crawl], i))
                    {
                        path.pb(i);
                        for (int cr = 0; cr < path.size() - 1; cr++)
                            minw = min(minw, w[path[cr]][path[cr + 1]]);
                        if (minw != 0)
                        {
                            for (int cr = 0; cr < path.size() - 1; cr++)
                            {
                                w[path[cr]][path[cr + 1]] -= minw;
                                cost += minw;
                            }
                            cost -= minw;
                        }
                    }
                }
            }
        }
        //Test Cases:
        /* 20 16
        8 7 11 9 12 10 14 13 18 19 17 20 15 16 4 6 5 2 3 1
        1 2 2 3 3 4 4 5 5 6 7 8 9 10 10 11 11 12 12 13 13 14 15 16 16 17 17 18 18 19 19 20 */
        /* 14 11
        6 5 4 1 10 14 12 11 13 3 2 8 7 9
        1 2 2 3 4 5 5 6 6 7 7 8 8 9 10 11 11 12 12 13 13 14 */
        /* 24 20
10 9 19 23 24 21 20 22 3 6 1 15 17 18 4 2 7 5 8 16 11 13 12 14
1 2 2 3 3 4 4 5 5 6 6 7 7 8 9 10 10 11 11 12 12 13 13 14 15 16 16 17 17 18 18 19 20 21 21 22 22 23 23 24 */
        /* 18 14
7 8 9 10 11 12 13 14 15 16 17 18 1 2 3 4 5 6
1 2 2 3 3 4 4 5 5 6 7 8 9 10 10 11 11 12 13 14 14 15 15 16 16 17 17 18 */
        /* 24 18
11 12 13 14 17 18 1 2 3 4 19 20 21 22 5 6 23 24 7 8 9 10 15 16
1 2 2 3 3 4 4 5 5 6 7 8 8 9 9 10 11 12 12 13 13 14 15 16 17 18 19 20 20 21 21 22 22 23 23 24 */
        cout << cost << endl;
    }
}