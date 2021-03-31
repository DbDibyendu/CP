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
const int N = 1e3 + 1, M = N;
//=======================

ll dp[N][N];
ll ntotal, ktotal;
//! My dp appraoch..... pretty simple
ll recur(int n, int k)
{
    if (dp[n][k] != 0)
    {
        return dp[n][k];
    }
    if (n == 0 || k == 1)
    {
        dp[n][k] = 1;
        return 1;
    }
    return dp[n][k] = (recur(n - 1, k) % MOD + recur(ntotal - n, k - 1) % MOD) % MOD;
}

void solve()
{

    int i, j, m;
    ll temp = 0, flag = 1;
    cin >> ntotal >> ktotal;
    clr(dp);
    // temp = recur(ntotal, ktotal);
    for (i = 0; i <= ntotal; i++)
    {
        dp[1][i] = 1;
    }
    for (i = 1; i <= ktotal; i++)
    {
        for (j = 1; j <= ntotal; j++)
        {
            dp[i][j] += dp[i][j - 1];
            dp[i][j] += dp[i - 1][ntotal - j];
        }
    }
    cout << dp[ktotal][ntotal] << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================