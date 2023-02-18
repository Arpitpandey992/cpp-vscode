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
#include <vector>
using namespace std;
#define M 1000000007
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
#define pb push_back
#define paus system("pause");
ll i, j, temp;
#define fok(i, k, n) for (i = k; i < n; i++)
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n; i >= 0; i--)
#define Sort(v) sort(v.begin(), v.end())
#define Sortg(v) sort(v.begin(), v.end(), greater<int>())
#define lb(v, val) lower_bound(v.begin(), v.end(), val)
#define ub(v, val) upper_bound(v.begin(), v.end(), val)
#define inpt(v)      \
    {                \
        cin >> temp; \
        v.pb(temp);  \
    }
#define fastio ios_base::sync_with_stdio(false);
//cin.tie(NULL);                    \
//cout.tie(NULL); // to get output after all input is done
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
constexpr ll pow2(ll b, ll e)
{
    return (e == 0) ? 1 : b * pow2(b, e - 1);
}
//----------------------------------------------------------------------------------//
// Include lines And Stuff Above

int main()
{
    test
    {
        int n, k;
        cin >> n >> k;
        vi adj[n];
        string s;
        cin >> s;
        fo(i, n)
        {
            if (i < n / 2 && i + k < n)
            {
                if (n-i-1 > i + k)
                {
                    adj[i].pb(i + k);
                    adj[i + k].pb(i);
                    adj[i].pb(n-i-1);
                    adj[n-i-1].pb(i);
                }
                else if (n-i-1 < i + k)
                {
                    adj[i].pb(n-i-1);
                    adj[n-i-1].pb(i);
                    adj[i].pb(i + k);
                    adj[i + k].pb(i);
                }
                else
                {
                    adj[i].pb(n-i-1);
                    adj[n-i-1].pb(i);
                }
            }
            else if (i < n / 2)
            {
                adj[i].pb(n-i-1);
                adj[n-i-1].pb(i);
            }
            else if(i + k < n)
            {
                adj[i].pb(i + k);
                adj[i + k].pb(i);
            }
        }
        bool visited[n] = {0};
        ll sum = 0;
        fo(i,n)
        {
            if(!visited[i])
            {
                list<int> q;
                q.pb(i);
                map<char, int> m;
                while(!q.empty())
                {
                    int t = q.front();
                    q.pop_front();
                    if(m.find(s[t])!=m.end())
                    {
                        m[s[t]]++;
                    }
                    else
                        m[s[t]] = 1;
                    for(auto x:adj[t])
                    {
                        if(!visited[x])
                        {
                            visited[x] = true;
                            q.push_front(x);
                        }
                    }
                }
                vi tp;
                for (auto it = m.begin(); it != m.end();it++)
                {
                    tp.pb((it)->second);
                }
                Sort(tp);
                fo(j, tp.size() - 1)
                    sum += tp[j];
            }
        }
        cout << sum << endl;
    }
}