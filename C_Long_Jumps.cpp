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

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n), dp(n, 0);
    fo(i, 0, n)
    {
        cin >> A[i];
    }

    dp[n - 1] = A[n - 1];
    temp = max(temp, dp[n - 1]);

    for (i = n - 2; i >= 0; i--)
    {
        if (A[i] + i > n - 1)
        {
            dp[i] = A[i];
        }
        else
        {
            dp[i] += A[i] + (dp[i + A[i]]);
        }
        temp = max(temp, dp[i]);
    }
    cout << temp << endl;
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