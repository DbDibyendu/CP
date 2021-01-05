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
typedef vector<vi> vvi;
typedef vector<ll> vl;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================
    
void solve()
{

    ll i, j, n, m, k, d;
    ll temp = 0, flag = 1;
    cin >> n >> k >> d;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    dp[0][0] = 1;
    dp[0][1] = 0;

    for (i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
        for (j = 1; j <= k && (i - j) >= 0; j++)
        {

            if (j < d)
            {
                dp[i][0] += dp[i - j][0] % MOD;
                dp[i][1] += dp[i - j][1] % MOD;
            }
            else if (j >= d)
            {
                dp[i][1] += dp[i - j][0] % MOD;
                dp[i][1] += dp[i - j][1] % MOD;
            }
        }
    }
    cout << dp[n][1] % MOD;
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