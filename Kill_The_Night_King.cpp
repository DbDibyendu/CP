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
// const int MOD = 1'000'000'007;
const int N = 1000010, M = N;
//=======================

//! Failed approach
// ll dp[N];
// bool isPrime(int n)
// {
//     int i;
//     if (n % 2 == 0 && n != 2)
//     {
//         return false;
//     }
//     for (i = 3; i * i <= n; i += 2)
//     {
//         if (n % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// ll helper(ll n)
// {
//     ll i, j;

//     if (n == 0 || n == 1)
//     {
//         dp[n] = n;
//         return n;
//     }
//     if (dp[n] != 0)
//     {
//         return dp[n];
//     }
//     if (isPrime(n))
//     {
//         dp[n] = helper(n - 1) + 1;
//         return dp[n];
//     }
//     j = sqrt(n);
//     if (j * j == n)
//     {
//         dp[n] = helper(j) + 1;
//         return dp[n];
//     }
//     ll t;
//     dp[n] = helper(n - 1) + 1;
//     ll k = 0;
//     for (i = n; i > j; i--)
//     {
//         if (n % i == 0)
//         {
//             t = i;
//             dp[n] = min(dp[n], helper(t) + 1);
//             // break;
//         }
//     }

//     return dp[n];
// }

//! One of the good questions,

//! Must follow bottom up approach
void solve()
{

    ll i, j, n, m, k;
    // ll temp = 0, flag = 1;
    cin >> n;
    vl dp(n + 1, 1e7 + 5);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + 1);

        for (j = 2 * i; j <= i * i && j <= n; j += i)
        {
            // deb2(i, j);
            dp[j] = min(dp[j], dp[i] + 1);
        }
        // deb(dp[i]);
    }
    // deb(dp[4]);
    cout << dp[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================