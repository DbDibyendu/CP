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
const int MOD = 100000000;
const int N = INT_MAX, M = N;
//=======================

// ! Multiple Variation DP implementation
ll k1_limit, k2_limit;

ll dp[105][105][15][15];

int calc(int n1, int n2, int k1, int k2)
{
    int ans = 0;
    if (n1 + n2 == 0)
        return dp[n1][n2][k1][k2] = 1;

    if (dp[n1][n2][k1][k2] != -1)
        return dp[n1][n2][k1][k2];

    if (n1 > 0 && k1 > 0)
    {
        ans += calc(n1 - 1, n2, k1 - 1, k2_limit);
    }
    if (n2 > 0 && k2 > 0)
    {
        ans += calc(n1, n2 - 1, k1_limit, k2 - 1);
    }

    return dp[n1][n2][k1][k2] = ans % MOD;
}

void solve()
{

    ll i, j, n1, n2, k1, k2, m, i2, j2;
    ll temp = 0, flag = 1;
    cin >> n1 >> n2 >> k1 >> k2;
    k1_limit = k1, k2_limit = k2;

    for (i = 0; i <= n1; i++)
    {
        fo(j, 0, n2 + 1)
        {
            fo(i2, 0, k1 + 1)
            {
                fo(j2, 0, k2 + 1)
                {
                    dp[i][j][i2][j2] = -1;
                }
            }
        }
    }
    calc(n1, n2, k1, k2);
    cout << dp[n1][n2][k1][k2] % MOD;
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