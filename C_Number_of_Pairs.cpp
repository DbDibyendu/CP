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

    ll i, j, n, m, k, l, r;
    ll temp = 0, flag = 1;
    cin >> n >> l >> r;
    vl A(n);
    read(A);
    // map<ll, ll> hash;
    sort(A.begin(), A.end());
    fo(i, 0, n)
    {
        ll x = (l - A[i]);
        // deb(x);
        auto it = lower_bound(A.begin(), A.end(), x);
        auto it2 = upper_bound(A.begin(), A.end(), (r - A[i]));
        // deb(it - A.begin());
        ll t = max((int)i + 1, (int)(it - A.begin()));
        ll t2 = (int)(it2 - A.begin());
        if (t2 - t > 0)
            temp += t2 - t;
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