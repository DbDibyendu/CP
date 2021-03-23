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
const int N = INT_MAX, M = N;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    ll k1, k2, w, b, t1, t2;
    cin >> n >> k1 >> k2 >> w >> b;
    t1 = (n - k1), t2 = n - k2;
    if (k1 > k2)
    {
        if (w > k2)
        {
            k1 -= k2;
            w -= k2;
            if (2 * w > k1)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    else
    {
        if (w > k1)
        {
            k2 -= k1;
            w -= k1;
            if (2 * w > k2)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    if (t1 > t2)
    {
        if (b > t2)
        {
            t1 -= t2;
            b -= t2;
            if (2 * b > t1)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    else
    {
        if (b > t1)
        {
            t2 -= t1;
            b -= t1;
            if (2 * b > t2)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================