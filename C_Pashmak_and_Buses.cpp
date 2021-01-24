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

// calculate a^b in log(b) time
ll bin_pow(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y % 2)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

void solve()
{

    int i, j, n, m, k, d;
    ll temp = 0, flag = 1;
    cin >> n >> k >> d;
    if (bin_pow(k, d) >= n)
    {
        int count = 0, p = 1;
        for (j = 0; j < d; j++)
        {
            count = 0;
            i = 1;
            int t = 0;
            while (count < n)
            {
                if (i == k + 1)
                    i = 1;
                while (t < p)
                {
                    cout << i << " ";
                    count++;
                    t++;
                    if (count == n)
                    {
                        break;
                    }
                }
                t = 0;
                i++;
            }
            cout << endl;
            p *= k;
        }
    }

    else
    {
        cout << -1 << endl;
    }
}

void solve2()
{

    ll i, j, n, m, k, d;
    ll temp = 0, flag = 1;
    cin >> n >> k >> d;
    if (bin_pow(k, d) >= n)
    {
        ll p = 1;
        for (j = 0; j < d; j++)
        {
            ll l = 0;
            for (i = 1; i <= n; i++)
            {
                cout << l + 1 << " ";
                if (i % p == 0)
                {
                    l++;
                    l = l % k;
                }
            }
            cout << endl;
            p = min(n, p * k);
        }
    }

    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================