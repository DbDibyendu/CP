#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = 10000100;
//===========================
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

bool visited[N] = {false};
vi adj[N];
ll siz[N] = {0};
vi v;

void dfs(ll u)
{
    for (auto x : adj[u])
    {
        if (!visited[x])
        {
            visited[x] = true;
            v.pb(x);
            dfs(x);
        }
    }
}

void solve()
{
    ll i, j, n, m, k,a;
    ll temp = 0, flag = 1;

    cin >> n >> m;
    // create the graph
    for (i = 1; i <= m; i++)
    {
        cin >> a;
        if (a != 0) cin >> temp;
        a--;
        for(j=0;j<a;j++)
        {
            cin >> k;
            adj[temp].pb(k);
            adj[k].pb(temp);

        }
    }
    // check each element
    for (i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i);
            v.pb(i);
            for (auto x : v)
            {
                siz[x] = v.size();
            }
            v.clear();
        }
    }
    for(i=1;i<=n;i++)cout<<max(siz[i],flag)<<" ";

}

//=======================

int main()
{
    int t = 1;
   // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
//=======================

