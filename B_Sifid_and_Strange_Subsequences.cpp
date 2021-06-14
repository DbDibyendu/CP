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
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    sort(A.begin(), A.end());
    vl diff(n + 1, 0);
    diff[0] = 2 * MOD;
    for (i = 1; i < n; i++)
    {
        diff[i] = min(diff[i - 1], abs(A[i] - A[i - 1]));
        // deb(diff[i]);
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << 1 << endl;
            return;
        }
        // deb2(diff[i], A[i]);
        if (diff[i] >= A[i])
        {
            cout << i + 1 << endl;
            return;
        }
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