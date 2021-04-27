//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯

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
const int N = 1e5 + 5, M = N;
//=======================
int n, k;
int visited[N];
int dp[N];
vector<int> g[N];
int A[N];
vi leaves;
int ans = 0;
int t[N];

void dfs(int u)
{

    if (dp[u] > k)
    {
        return;
    }

    if (t[u] == 1 && u != 1)
    {
        ans++;
        return;
    }
    visited[u] = 1;
    for (auto x : g[u])
    {
        if (visited[x] == 0)
        {
            if (A[x] == 1)
            {
                dp[x] = dp[u] + 1;
            }
            dfs(x);
        }
    }
}

void solve()
{

    int i, j;
    ll temp = 0, flag = 1;
    cin >> n >> k;
    clr(visited), clr(dp), clr(t);
    fo(i, 1, n + 1)
    {
        cin >> A[i];
    }
    n--;
    while (n)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
        t[x]++;
        t[y]++;
        n--;
    }

    if (A[1] == 1)
    {
        dp[1]++;
    }
    dfs(1);

    cout << ans << endl;
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