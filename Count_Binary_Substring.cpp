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

//! Solved on my own
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    // cin >> n;
    string A;
    cin >> A;
    n = A.length();
    ll dp[n + 1][2];
    dp[0][1] = 0;
    dp[0][0] = 0;
    for (i = 1; i <= n; i++)
    {
        if (A[i - 1] == '0')
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = 0;

            if (dp[i - dp[i][0]][1] >= dp[i][0])
            {
                temp += 1;
            }
        }
        else
        {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][0] = 0;
            if (dp[i - dp[i][1]][0] >= dp[i][1])
            {
                temp += 1;
            }
        }
        // deb(temp);
    }
    cout << temp << endl;
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