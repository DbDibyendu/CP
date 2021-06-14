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
const int N = 2e9 + 2, M = N;
//=======================

bool isP(ll x, ll y, ll a, ll b, ll n)
{
    x -= a * n;
    y -= a * n;
    if (x < 0 || y < 0)
    {
        return false;
    }

    ll t = x / (b - a) + y / (b - a);
    if (t >= n)
    {
        return true;
    }
    return false;
}
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a == b)
    {
        cout << min(x, y) / a << endl;
        return;
    }
    ll l = 1, r = 1e9;
    if (a > b)
    {
        swap(a, b);
    }
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (!isP(x, y, a, b, mid))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l - 1 << endl;
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