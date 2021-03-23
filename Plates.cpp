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

//! Similar to knapsack problem
//! Quite difficult

void solve()
{

    ll i, j, n, m, k, p;
    ll temp = 0, flag = 0;
    cin >> n >> k >> p;
    ll A[n + 1][k + 1], prefix[n + 1][k + 1];
    clr(prefix);
    fo(i, 1, n + 1)
    {
        fo(j, 1, k + 1)
        {
            cin >> A[i][j];
            if (j == 1)
            {
                prefix[i][j] = A[i][j];
            }
            else
            {
                prefix[i][j] = A[i][j] + prefix[i][j - 1];
            }
            // cout << prefix[i][j] << " ";
        }
        // cout << endl;
    }
    ll dp[n + 1][p + 1];
    clr(dp);

    fo(i, 1, n + 1)
    {
        fo(j, 1, p + 1)
        {
            for (int x = 0; x <= min(j, k); x++)
            {
                dp[i][j] = max(dp[i][j], prefix[i][x] + dp[i - 1][j - x]);
                // deb2(prefix[i][x], j);
                // deb2(dp[i][j], x);
            }
            temp = max(temp, dp[i][j]);
        }
        // deb(temp);
    }
    cout << temp << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    int k = 1;
    while (t--)
    {
        cout << "Case #" << k << ": ";
        solve();
        k++;
    }
    return 0;
}

//=======================