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
const ll N = 1e18, M = N;
//=======================

//! Good question, 3 variable DP
void solve()
{
    ll i, j, n, m, k, i2, j2;
    ll temp = N, flag = 1;
    cin >> n >> m >> k;
    ll P[n + 1][m + 1] = {0}, tree[n + 1] = {0};
    bool t = 1;
    fo(i, 1, n + 1)
    {
        cin >> tree[i];
    }

    fo(i, 1, n + 1)
    {
        fo(j, 1, m + 1)
        {
            cin >> P[i][j];
        }
    }

    ll dp[n + 1][m + 1][k + 1];

    fo(i, 0, n + 1)
    {
        fo(j, 0, m + 1)
        {
            fo(i2, 0, k + 1)
            {
                dp[i][j][i2] = N;
            }
        }
    }

    if (tree[1] == 0)
    {
        fo(j, 1, m + 1)
        {
            dp[1][j][1] = P[1][j];
        }
    }
    else
    {
        dp[1][tree[1]][1] = 0;
    }
    ll t1, t2;
    fo(i, 2, n + 1)
    {
        fo(i2, 1, k + 1)
        {
            if (tree[i] == 0)
            {
                fo(t1, 1, m + 1)
                {
                    dp[i][t1][i2] = min(dp[i][t1][i2], dp[i - 1][t1][i2] + P[i][t1]);
                    fo(t2, 1, m + 1)
                    {
                        if (t1 != t2)
                        {
                            if (i2 - 1 >= 1)
                                dp[i][t1][i2] = min(dp[i][t1][i2], dp[i - 1][t2][i2 - 1] + P[i][t1]);
                        }
                    }
                    // deb(dp[i][t1][i2]);
                }
            }
            else
            {
                dp[i][tree[i]][i2] = min(dp[i][tree[i]][i2], dp[i - 1][tree[i]][i2]);
                fo(t2, 1, m + 1)
                {

                    if (t2 != tree[i])
                    {
                        if (i2 - 1 >= 1)
                            dp[i][tree[i]][i2] = min(dp[i][tree[i]][i2], dp[i - 1][t2][i2 - 1]);
                    }
                }
            }
        }
    }

    fo(i, 1, m + 1)
    {
        temp = min(temp, dp[n][i][k]);
    }

    printf("%lld", temp < N ? temp : -1);
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