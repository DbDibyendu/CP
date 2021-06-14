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

vl dp(19, 0);

//! Good implementaion, solved on my own
ll helper(ll n)
{
    if (n / 10 == 0)
    {
        return n;
    }
    ll m = n;
    ll a[2];
    ll flag = 0;
    while (m)
    {
        if (m / 10 == 0)
        {
            a[1] = m % 10;
        }
        if (flag == 0)
        {
            a[0] = m % 10;
            flag = 1;
        }
        m /= 10;
    }
    ll temp = 0;
    ll i, j;
    if (a[0] >= a[1])
    {
        temp++;
    }
    n /= 10;
    j = 0;
    i = 0;
    ll restsum = 0;
    while (n)
    {
        if (n / 10 == 0)
        {

            temp += ((n % 10) - 1) * pow(10, j);
            j++;
            break;
        }
        if (n % 10)
        {
            temp += (n % 10) * pow(10, j);
        }
        j++;
        n /= 10;
    }
    // deb2(temp, temp + dp[j]);

    return temp + dp[j];
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    ll l, r;
    cin >> l >> r;
    dp[1] = 9;
    dp[2] = 18;

    for (i = 3; i <= 18; i++)
    {
        dp[i] = 9 * pow(10, i - 2) + dp[i - 1];
        // deb(dp[i]);
    }
    ll right = helper(r);
    ll left = helper(l);
    ll a[2];
    flag = 0;
    while (l)
    {
        if (l / 10 == 0)
        {
            a[1] = l % 10;
        }
        if (flag == 0)
        {
            a[0] = l % 10;
            flag = 1;
        }
        l /= 10;
    }
    if (a[0] == a[1])
    {
        cout << right - left + 1;
    }
    else
    {
        cout << right - left;
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