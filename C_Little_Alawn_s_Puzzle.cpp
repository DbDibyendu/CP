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
const int N = 4e5, M = N;
//=======================

vector<bool> visited;
vector<vector<int>> g;

void dfs(int u)
{
    visited[u] = true;
    for (auto x : g[u])
    {
        if (visited[x] == false)
        {
            dfs(x);
        }
    }
}

void solve()
{
    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A1(n), A2(n);
    read(A1);
    read(A2);
    visited.assign(N, false);
    g.assign(n + 1, vector<int>());

    fo(i, 0, n)
    {
        g[A1[i]].push_back(A2[i]);
        g[A2[i]].push_back(A1[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (visited[A1[i]] == false)
        {
            dfs(A1[i]);
            flag *= 2;
            flag %= MOD;
        }
    }
    cout << flag << endl;
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