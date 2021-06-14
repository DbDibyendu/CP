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
const int N = 1e6, M = N;
//=======================

ll dp[N];

ll helper(string &A, int i, int n)
{
    int ans = 0, t1, t2;
    if (i >= n)
    {
        return 1;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    t1 = 1 * helper(A, i * 2 + 1, n);
    t2 = 1 * helper(A, i * 2 + 2, n);
    if (A[i] == '1')
    {
        ans = t1;
    }
    else if (A[i] == '0')
    {
        ans = t2;
    }
    else
    {
        ans = t1 + t2;
    }
    // deb2(ans, i);
    dp[i] = ans;
    return ans;
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> k;
    k = (1 << k) - 1;
    string A;
    cin >> A;
    reverse(A.begin(), A.end());
    memset(dp, -1, sizeof(dp));
    cin >> n;
    while (n--)
    {
        ll t;
        cin >> t;
        t = k - t;
        char c;
        cin >> c;
        //! Important Part, update the dp tree in log(n) time
        i = t;
        while (i > 0)
        {
            dp[i] = -1;
            i = (i - 1) / 2;
        }
        dp[0] = -1;
        A[t] = c;
        ll ans = helper(A, 0, k);
        cout << ans << endl;
    }
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