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
const int N = INT_MAX, M = N;
//=======================

int r[505][505];
int down[505][505];
int dp[505][505][25];
int n, m;

//! Good implementation dp
int find(int i, int j, int K)
{
    if (K == 0)
    {
        return 0;
    }
    if (dp[i][j][K] != -1)
    {
        return dp[i][j][K];
    }
    int t = INT_MAX;
    if (j > 1)
    {
        t = min(t, find(i, j - 1, K - 1) + r[i][j - 1]);
    }
    if (j < m)
    {
        t = min(t, find(i, j + 1, K - 1) + r[i][j]);
    }
    if (i > 1)
    {
        t = min(t, find(i - 1, j, K - 1) + down[i - 1][j]);
    }
    if (i < n)
    {
        t = min(t, find(i + 1, j, K - 1) + down[i][j]);
    }
    dp[i][j][K] = t;
    return t;
}

void solve()
{

    int i, j, k;
    ll temp = 0, flag = 1;
    cin >> n >> m >> k;

    int A[505][505];
    memset(dp, -1, sizeof(dp));

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m - 1; j++)
        {
            cin >> r[i][j];
        }
    }
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> down[i][j];
        }
    }

    if (k & 1)
    {
        fo(i, 0, n)
        {
            fo(j, 0, m)
            {
                cout << -1 << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                cout << find(i, j, k / 2) * 2 << " ";
            }
            cout << endl;
        }
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