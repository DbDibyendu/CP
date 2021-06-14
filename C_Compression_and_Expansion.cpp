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
const int N = INT_MAX, M = N;
//=======================

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n);
    read(A);
    ll dp[n][n], v[n];
    clr(dp), clr(v);
    dp[0][0] = A[0];
    j = 0;
    for (i = 1; i < n; i++)
    {

        if (A[i] > A[i - 1])
        {
            for (k = j; k >= 0; k--)
            {
                if (A[i] == dp[i - 1][k] + 1)
                {
                    j = k;
                    break;
                }
            }
            for (k = 0; k < j; k++)
            {
                dp[i][k] = dp[i - 1][k];
            }
            dp[i][j] = A[i];
        }
        else
        {
            if (A[i] == 1)
            {
                for (k = 0; k <= j; k++)
                {
                    dp[i][k] = dp[i - 1][k];
                }
                j++;
                dp[i][j] = A[i]; //! Opening a new
            }
            else
            {
                int t;
                for (k = j; k >= 0; k--)
                {
                    if (A[i] == dp[i - 1][k] + 1)
                    {
                        j = k;
                        t = A[i];
                        break;
                    }
                }

                for (k = 0; k < j; k++)
                {
                    dp[i][k] = dp[i - 1][k];
                }
                dp[i][j] = A[i];
            }
        }
        v[i] = j;
    }

    for (i = 0; i < n; i++)
    {
        int j = 0;
        // deb(v[i]);
        for (j = 0; j <= v[i]; j++)
        {
            if (j == v[i])
            {
                // deb(dp[i][j]);
                cout << dp[i][j];
                // continue;
            }
            else
                cout << dp[i][j] << '.';
            // j++;
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================