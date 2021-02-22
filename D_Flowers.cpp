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
const int N = 1e5 + 100, M = N;
//=======================

ll k;
vl dp(N + 1, 0);
vl prefix(N + 1, 0);

void cal()
{
    ll i;
    dp[0] = 1, dp[1] = 1;
    prefix[0] = 1;
    prefix[1] = 2;
    if (k == 1)
    {
        dp[0] = dp[1] = 2;
        prefix[0] = 2;
        prefix[1] = 4;
    }
    for (i = 2; i <= N; i++)
    {
        if (i >= k)
        {
            // !  All cases before + white Flowers
            dp[i] = dp[i - 1] % MOD + dp[i - k] % MOD;
        }
        else
        {
            // ! Only red flowers
            dp[i] = 1;
        }
        prefix[i] = prefix[i - 1] + dp[i];
    }
}
void solve()
{

    ll i, a, b;
    ll temp = 0, flag = 1;
    cin >> a >> b;
    temp += prefix[b] - prefix[a - 1];
    cout << temp % MOD << endl;
}

int main()
{
    int t = 1;
    cin >> t >> k;
    cal();
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================