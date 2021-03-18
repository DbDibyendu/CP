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

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = MOD;
    cin >> n >> m;
    ll A[n + 2][m + 2];
    ll i1, j1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> A[i][j];
        }
    }

    ll dp[n + 2][m + 2][4] = {0};
    clr(dp);
    // ! down and right till n & m
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + A[i][j];
        }
    }
    for (i = n; i >= 1; i--)
    {
        for (j = m; j >= 1; j--)
        {
            dp[i][j][2] = max(dp[i + 1][j][2], dp[i][j + 1][2]) + A[i][j];
        }
    }
    //! right and up till 1 & m
    for (i = 1; i <= n; i++)
    {
        for (j = m; j >= 1; j--)
        {
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j + 1][1]) + A[i][j];
        }
    }

    for (i = n; i >= 1; i--)
    {
        for (j = 1; j <= m; j++)
        {
            dp[i][j][3] = max(dp[i + 1][j][3], dp[i][j - 1][3]) + A[i][j];
        }
    }

    ll ans = 0;

    for (i = 2; i < n; i++)
    {
        for (j = 2; j < m; j++)
        {
            temp = max(dp[i][j - 1][0] + dp[i][j + 1][2] + dp[i + 1][j][3] + dp[i - 1][j][1], dp[i - 1][j][0] + dp[i + 1][j][2] + dp[i][j - 1][3] + dp[i][j + 1][1]);
            ans = max(temp, ans);
            // cout << temp << " ";
        }
        // cout << endl;
    }
    cout << ans << endl;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================