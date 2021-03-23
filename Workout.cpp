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
const int N = 1e5 + 10, M = N;
//=======================

//! Test case 1 is passed

void solve()
{

    ll i, j, n, m, k, p;
    ll temp = 0, flag = 0;
    cin >> n >> k;
    vl A(n), diff(n, 0);
    // clr(diff);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    fo(i, 1, n)
    {
        diff[i] = A[i] - A[i - 1];
    }
    sort(diff.rbegin(), diff.rend());
    m = diff[0];
    p = diff[1];
    if (m & 1)
    {
        cout << max((m + 1) / 2, p) << endl;
    }
    else
        cout << max(m / 2, p) << endl;
}

//! Code for test case 2

ll A[N];
ll check(int n, int mid)
{
    ll ans = 0, i;
    fo(i, 1, n)
    {
        ans += (A[i] - A[i - 1] - 1) / mid;
    }
    return ans;
}
void solve2()
{

    ll i, j, n, m, k, p;
    ll temp = 0, flag = 0;
    cin >> n >> k;
    // clr(diff);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    ll l = 1, r = 1e9;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        // deb(mid);
        if (check(n, mid) <= k)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl; //! l==r
}

int main()
{
    int t = 1;
    cin >> t;
    int k = 1;
    while (t--)
    {
        cout << "Case #" << k << ": ";
        solve2();
        k++;
    }
    return 0;
}

//=======================