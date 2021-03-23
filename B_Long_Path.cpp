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

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    ll dp[n + 1];
    clr(dp);
    //! Good question solved on my own, DP logic problem
    fo(i, 1, n + 1)
    {
        cin >> k;
        if (k == i)
        {
            temp += 2;
            dp[i] = 2;
            continue;
        }
        dp[i] += 2;
        fo(j, k, i)
        {
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
        temp += dp[i];
        temp %= MOD;
        // deb(dp[i]);
    }
    cout << temp << endl;
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