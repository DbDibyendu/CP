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
const ll MOD = 1e18;
const int N = INT_MAX, M = N;
//=======================

//! GOOD DP problem solved on my own
void solve()
{
    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n + 1);
    ll value[n + 1][2] = {0};
    vector<pair<string, string>> B(n + 1);
    string x;
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    fo(i, 0, n)
    {
        cin >> x;
        B[i].first = x;
        reverse(x.begin(), x.end());
        B[i].second = x;
    }

    ll dp[n + 1][2] = {0};

    dp[0][0] = 0;
    dp[0][1] = A[0];

    ll t1, t2, t3, t4, s1, s2, s3, s4;
    fo(i, 1, n)
    {
        t1 = t2 = s1 = s2 = MOD;
        if (B[i].first >= B[i - 1].first)
        {
            t1 = dp[i - 1][0];
        }
        if (B[i].first >= B[i - 1].second)
        {
            t2 = dp[i - 1][1];
        }
        if (B[i].second >= B[i - 1].first)
        {
            s1 = dp[i - 1][0] + A[i];
        }
        if (B[i].second >= B[i - 1].second)
        {
            s2 = dp[i - 1][1] + A[i];
        }
        dp[i][0] = min(t1, t2);
        dp[i][1] = min(s1, s2);
    }

    printf("%lld", min(dp[n - 1][0], dp[n - 1][1]) != 1e18 ? min(dp[n - 1][0], dp[n - 1][1]) : -1);
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