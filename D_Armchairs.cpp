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
const int N = 5005, M = N;
//=======================

vi A, B;
int dp[5005][5005];

//! Very tricky dp

int helper(int i, int j, int n, int m)
{
    if (i == n)
    {
        dp[i][j] = 0;
        return 0;
    }
    int av = m - j;
    int req = n - i;
    if (req > av)
    {
        return MOD;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans1 = abs(B[j] - A[i]) + helper(i + 1, j + 1, n, m);
    int ans2 = helper(i, j + 1, n, m);

    dp[i][j] = min(ans1, ans2);
    // deb(dp[i][j]);
    return dp[i][j];
}
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    fo(i, 0, n)
    {
        cin >> k;
        if (k == 1)
        {
            A.push_back(i);
        }
        else
        {
            B.push_back(i);
        }
    }
    int n1 = A.size();
    int n2 = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if (n1 == 0)
    {
        cout << 0 << endl;
        return;
    }
    memset(dp, -1, sizeof(dp));
    cout << helper(0, 0, n1, n2) << endl;
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