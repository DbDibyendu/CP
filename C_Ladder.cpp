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

// * Attempt One
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    vi A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    vpll Pair;
    int x, y;
    fo(i, 0, m)
    {
        cin >> x >> y;
        Pair.pb(make_pair(x, y));
    }

    ll dp[n + 1][n + 1] = {0}; //dp[r][l]

    dp[0][0] = 1;
    int Inc = 1, dec = 1;
    fo(i, 1, n)
    {
        if (A[i] >= A[i - 1])
        {
            dp[i - 1][i] = 1;
            for (j = i - 1; j > 0; j--)
            {
                if (dp[0][j] == 1)
                {
                    dp[j][i] = 1;
                }
                deb(dp[j][i]);
                deb2(i, j);
            }
        }
        else
        {
            dp[i - 1][i] = -1;
            for (j = i - 1; j > 0; j--)
            {
                if (dp[0][j] == 1 || dp[0][j] == -1)
                {
                    dp[j][i] = -1;
                }
                deb(dp[j][i]);
                deb2(i, j);
            }
        }
        dp[i][i] = 1;
    }

    fo(i, 0, m)
    {
        if (dp[Pair[i].first - 1][Pair[i].second - 1] == 1 || dp[Pair[i].first - 1][Pair[i].second - 1] == -1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

// * DP approach

void solve2()
{
    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    vi A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    vpll Pair;
    int x, y;
    fo(i, 0, m)
    {
        cin >> x >> y;
        Pair.pb(make_pair(x, y));
    }

    // !  dp [j] [i] stores the value of the leftmost index of the ladder when ith index is having jth possibility.
    ll dp[3][n];
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;
    fo(i, 1, n)
    {
        /*
        if (A[i] >= A[i - 1])
        {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = i;
        }
        else if (A[i] < A[i - 1])
        {
            dp[1][i] = dp[1][i - 1];
            if (i - 2 >= 0 && A[i - 1] >= A[i - 2])
            {
                dp[1][i] = min(dp[1][i - 1], dp[0][i - 1]);
            }
            dp[0][i] = i;
        }
        */

        dp[0][i] = A[i] >= A[i - 1] ? dp[0][i - 1] : i;
        dp[1][i] = i + 1 < n && A[i] >= A[i - 1] && A[i] > A[i + 1] ? dp[0][i - 1] : i; // ! Pivot point
        dp[2][i] = A[i] <= A[i - 1] ? min(dp[2][i - 1], dp[1][i - 1]) : i;              // ! Min between Pivot and decreasing
            
    }

    fo(i, 0, m)
    {
        if (min(dp[2][Pair[i].second - 1], min(dp[0][Pair[i].second - 1], dp[1][Pair[i].second - 1])) <= Pair[i].first - 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
int main()
{
    int t = 1;
    /////// cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================