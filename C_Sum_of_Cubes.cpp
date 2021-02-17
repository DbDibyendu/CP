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

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;

    for (i = 1; i <= 100000; i++)
    {
        if (n - pow(i, 3) > 0)
        {
            m = n - pow(i, 3);
            for (j = (ll)cbrt(m); j <= (ll)cbrt(m)+5; j++)
            {
                if (pow(j, 3) == m)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }

    // deb((ll)cbrt(26));
    cout << "NO" << endl;
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