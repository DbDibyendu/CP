#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
//=======================
const int MOD = 1'000'000'007;
const int N = 100005, M = N;
//=======================

ll visited[N] = {0};
vl g[N];
ll Init[N], Goal[N];
vl ans;

void edge(int a, int b)
{
    //  undirected graph
    g[a].pb(b);
    g[b].pb(a);
}

void dfs(ll u)
{
    visited[u] = true;

    for (auto x : g[u])
    {
        if (visited[x] == false)
        {
            if (Init[x] != Goal[x])
            {
                ans.pb(x);
            }
            dfs(x);
        }
    }
}

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    fo(k, 1, n)
    {
        cin >> i >> j;
        edge(i, j);
    }
    fo(i, 1, n + 1)
    {
        cin >> Init[i];
        // deb(Init[i]);
    }

    fo(i, 1, n + 1)
    {
        cin >> Goal[i];
    }
    dfs(1);
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << endl;
    }
}

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