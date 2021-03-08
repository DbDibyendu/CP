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
vl A(100 + 5);
ll dp[105][3] = {0};
ll ans = 0, n;
// ! 1 for contest done, 2 for gym done

// ! DP solution
void solve()
{

    int i, j, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    fo(i, 0, n)
    {
        cin >> A[i];
    }

    fo(i, 0, n)
    {
        if (A[i] == 0)
        {
            dp[i][1] = MOD;
            dp[i][2] = MOD;
            if (i > 0)
            {
                dp[i][0] += min({dp[i - 1][1], dp[i - 1][2], dp[i - 1][0]}) + 1;
            }
            else
                dp[i][0] += 1;
        }
        else if (A[i] == 1)
        {
            dp[i][2] = MOD;
            if (i > 0)
            {
                dp[i][1] += min({dp[i - 1][2], dp[i - 1][1] + 1, dp[i - 1][0]});
                dp[i][0] += min({dp[i - 1][1], dp[i - 1][2], dp[i - 1][0]}) + 1;
            }
            else
                dp[i][0] += 1;
        }
        else if (A[i] == 2)
        {
            dp[i][1] = MOD;
            if (i > 0)
            {
                dp[i][2] += min({dp[i - 1][1], dp[i - 1][2] + 1, dp[i - 1][0]});
                dp[i][0] += min({dp[i - 1][1], dp[i - 1][2], dp[i - 1][0]}) + 1;
            }
            else
                dp[i][0] += 1;
        }
        else if (A[i] == 3)
        {
            if (i > 0)
            {
                dp[i][1] += min({dp[i - 1][2], dp[i - 1][1] + 1, dp[i - 1][0]});
                dp[i][0] += min({dp[i - 1][1], dp[i - 1][2], dp[i - 1][0]}) + 1;
                dp[i][2] += min({dp[i - 1][1], dp[i - 1][2] + 1, dp[i - 1][0]});
            }
            else
                dp[i][0] += 1;
        }
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
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