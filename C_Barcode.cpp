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

// ! Attempt 1 DP approach, Got right answer for first time in DP( above 1700 rating)
// ? Always check for OUT of Bound errors
void solve()
{

    ll i, j, n, m, k, x, y, t = 0;
    cin >> n >> m >> x >> y;
    char Barcode[n][m];
    ll dp[n + 1][m + 1][2];
    clr(dp);

    fo(i, 0, n)
        fo(j, 0, m)
    {
        cin >> Barcode[i][j];
    }
    fo(j, 0, m)
    {
        for (i = 1; i <= n; i++)
        {
            dp[i][j][0] = Barcode[i - 1][j] == '#' ? dp[i - 1][j][0] : dp[i - 1][j][0] + 1;
            // deb(dp[i][j][0]);
            dp[i][j][1] = Barcode[i - 1][j] == '.' ? dp[i - 1][j][1] : dp[i - 1][j][1] + 1;
        }
    }

    ll temp[m + 1][2];
    clr(temp);
    fo(j, 1, m + 1)
    {
        temp[j][0] = 10000000;
        temp[j][1] = 10000000;
    }
    ll sumX, sumY, ans = 0;

    fo(j, 1, m + 1)
    {
        sumX = 0;
        sumY = 0;
        for (i = 1; i <= y; i++)
        {
            if (j - i >= 0 && j - i <= m - 1)
            {
                sumX += dp[n][j - i][0];
                sumY += dp[n][j - i][1];
                if (i >= x && i <= y)
                {
                    temp[j][0] = min(sumX + temp[j - i][1], temp[j][0]);
                    temp[j][1] = min(sumY + temp[j - i][0], temp[j][1]);
                }
            }
        }
        // deb(min(temp[j][0], temp[j][1]));
    }

    cout << min(temp[m][0], temp[m][1]) << endl;
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