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
typedef pair<int, int> pi;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

vector<bool> visited(1000010, false);
vector<ll> g[1000010];
char A[1001][1001], B[1001][1001];

void dfs(int u)
{
    visited[u] = true;
    for (auto x : g[u])
    {

        if (visited[x] == false)
        {
            cout << x << " ";
            dfs(x);
        }
    }
}

void solve()
{

    int i, j, n, m, k, prev, cur;
    ll temp = 0, flag = 1;
    cin >> n >> m >> k;

    fo(i, 1, n + 1)
    {
        fo(j, 1, m + 1)
        {
            cin >> A[i][j];
        }
    }
    fo(i, 1, n + 1)
    {
        fo(j, 1, m + 1)
        {
            if (i - 1 >= 1 && A[i][j] == '.' && A[i - 1][j] == '.')
            {

                cur = i * 10 + j;
                prev = (i - 1) * 10 + j;
                g[cur].pb(prev);
                g[prev].push_back(cur);
                // deb2(prev, cur);
            }
            if (j - 1 >= 1 && A[i][j] == '.' && A[i][j - 1] == '.')
            {
                cur = i * 10 + j;
                prev = (i)*10 + j - 1;
                g[cur].pb(prev);
                g[prev].push_back(cur);
                // deb2(prev, cur);
            }
        }
    }
    dfs(12);
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