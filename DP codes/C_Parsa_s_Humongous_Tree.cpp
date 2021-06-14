#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)         \
    for (auto &aa : A)     \
        cout << aa << ' '; \
    cout << endl;
#define displayP(A)    \
    for (auto &aa : A) \
    {                  \
        display(aa);   \
    }
#define read(A)        \
    for (auto &aa : A) \
    {                  \
        cin >> aa;     \
    }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

//! DP and DFS problem
vector<vector<ll>> g, dp, val;
vector<bool> visited;

void edge(ll a, ll b)
{
    //  undirected graph
    g[a].push_back(b);
    g[b].push_back(a);
}

void dfs(ll u, ll p = -1)
{
    visited[u] = true;
    for (auto x : g[u])
    {
        //! Very important logic part, checks all the cases
        if (visited[x] == false)
        {
            dfs(x, u);
            dp[u][0] += max(dp[x][0] + abs(val[u][0] - val[x][0]), dp[x][1] + abs(val[u][0] - val[x][1]));
            dp[u][1] += max(dp[x][0] + abs(val[u][1] - val[x][0]), dp[x][1] + abs(val[u][1] - val[x][1]));
        }
    }
    // deb2(dp[u][1], dp[u][0]);
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    val.assign(n, vector<ll>(2, 0));
    dp.assign(n, vector<ll>(2, 0));
    g.assign(n, vector<ll>());

    for (i = 0; i < n; i++)
    {
        cin >> val[i][0] >> val[i][1];
    }
    for (i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge(x, y);
    }
    visited.assign(n, false);
    dfs(0);

    // temp = max(a1, a2);
    cout << max(dp[0][1], dp[0][0]) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================