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

ll dp[5005][5005];
ll A[5005], B[5005], n;

//! Implementation part very difficult
ll recur(int i, int j)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        dp[i][j] = A[i] * B[j];
        return dp[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = recur(i + 1, j - 1) + A[j] * B[i] + A[i] * B[j];
    return dp[i][j];
}
void solve()
{

    int i, j, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    fo(j, 0, n)
    {
        cin >> B[j];
    }

    recur(0, n - 1);
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            recur(i, j);
        }
    }
    ll p[5005], s[5005];
    p[0] = 0;
    for (i = 0; i < n; i++)
    {
        p[i + 1] = A[i] * B[i] + p[i];
    }

    s[n] = 0;
    for (i = n - 1; i >= 0; i--)
    {
        s[i] = A[i] * B[i] + s[i + 1];
    }

    fo(i, 0, n)
    {
        fo(j, i, n)
        {
            temp = max(temp, p[i] + s[j + 1] + dp[i][j]);
            // deb(temp);
        }
    }
    cout << temp << endl;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================