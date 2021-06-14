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
const int N = 2e5 + 10, M = N;
//=======================

ll A[N], dp[N];

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    sort(A, A + n);
    ll count[N];
    clr(count);
    ll ans = 0;
    fo(i, 0, n)
    {
        count[A[i]]++;
    }
    clr(dp);
    //! Concept of sieves of erasthoreses
    for (i = n - 1; i >= 0; i--)
    {
        if (dp[A[i]] == 0)
        {
            dp[A[i]] = count[A[i]];

            ll t = 0;
            for (j = 2 * A[i]; j < N; j += A[i])
            {
                if (dp[j])
                {
                    t = max(t, dp[j]);
                    // break;
                }
            }
            dp[A[i]] += t;
        }
        // deb(dp[A[i]]);
    }
    for (auto x : A)
    {
        temp = max(dp[x], temp);
    }
    cout << n - temp << endl;
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