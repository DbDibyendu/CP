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

int dp[5005][5005];

//! GOOD dp problem, I couldn't figure out a simple observation
int LCS(int i, int j, string &A, string &B)
{
    int ans = 0;
    if (i < 0)
    {
        return 0;
    }
    if (j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (A[i] == B[j])
    {
        ans = 2 + LCS(i - 1, j - 1, A, B);
        ans = max(2, ans);
    }
    else
    {
        ans = max(LCS(i - 1, j, A, B), LCS(i, j - 1, A, B)) - 1;
        ans = max(0, ans);
    }

    dp[i][j] = ans;
    return ans;
}

void solve()
{

    int i, j, n, m, k;
    int temp = 0, flag = 1;
    cin >> n >> m;
    string A, B;
    cin >> A >> B;
    memset(dp, -1, sizeof(dp));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            temp = max(temp, LCS(i, j, A, B));

    cout << temp << endl;
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