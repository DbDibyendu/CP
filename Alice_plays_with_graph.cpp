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

vector<bool> visited;
vector<vector<int>> g;

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
            dfs(x);
        }
    }
}


void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    ll A[n + 1];
    clr(A);
    while (m--)
    {
        cin >> i >> j;
        if (A[i] == 0)
        {
            A[i] = 1;
            if (A[j] == 0 || A[j] == 2)
            {
                A[j] = 2;
                temp++;
            }
            else
            {
                break;
            }
        }
        else if (A[i] == 1)
        {
            if (A[j] == 0 || A[j] == 2)
            {
                A[j] = 2;
                temp++;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (A[j] == 0 || A[j] == 2)
            {
                A[j] = 1;
                temp++;
            }
            else
            {
                break;
            }
        }
    }
    cout << temp << endl;
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