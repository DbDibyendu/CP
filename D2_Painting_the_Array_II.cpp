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

// Good problem of DP
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n), B;
    fo(i, 0, n)
    {
        cin >> A[i];
        if (i == 0)
        {
            B.pb(A[i]);
        }
        if (i > 0)
        {
            if (A[i] == A[i - 1])
            {
                continue;
            }
            else
            {
                B.pb(A[i]);
            }
        }
    }
    n = B.size();
    vl dp(n), last(1000000, -1);
    // last[a[i]] is the index of the last occurrence of this value in our array
    dp[0] = 1;
    last[B[0]] = 0;
    fo(i, 1, n)
    {
        if (last[B[i]] != -1)
        {
            dp[i] = min(dp[i - 1] + 1, dp[last[B[i]] + 1] + i - 1 - (last[B[i]] + 1));
            last[B[i]] = i;
        }
        else
        {
            dp[i] = dp[i - 1] + 1;
            last[B[i]] = i;
        }
    }
    cout << dp[n - 1] << endl;
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