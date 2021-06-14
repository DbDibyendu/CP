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
const ll N = 2e5 + 10, M = N;
//=======================

vl Size;
vector<bool> visited;
vector<vector<ll>> g;
vl T;
ll dfs1(ll u)
{
    ll ans = 1;
    visited[u] = true;
    for (auto x : g[u])
    {
        if (visited[x] == false)
        {
            ans += dfs1(x);
        }
    }
    Size[u] = ans;
    return ans;
}

void dfs2(ll u, ll depth)
{
    // ll ans = 1;
    visited[u] = true;
    T.push_back(Size[u] - depth);
    for (auto x : g[u])
    {
        if (visited[x] == false)
        {
            dfs2(x, depth + 1);
        }
    }

    return;
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> k;
    m = n;
    n--;
    visited.assign(m, false);
    Size.assign(m + 1,0);
    g.assign(m, vector<ll>());
    while (n--)
    {
        cin >> i >> j;
        i--;
        j--;
        g[j].push_back(i);
        g[i].push_back(j);
    }

    dfs1(0);

    visited.assign(n + 1, false);
    dfs2(0, 1);
    sort(T.rbegin(), T.rend());
    for (i = 0; i < (m - k); i++)
    {
        temp += T[i];
    }
    if (temp >= 0)
    {
        cout << temp << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================