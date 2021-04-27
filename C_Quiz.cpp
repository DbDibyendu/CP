//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯

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
const int MOD = 1'000'000'009;
const int N = INT_MAX, M = N;
//=======================

ll fast_pow(int a, int p)
{
    int res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = a * 1ll * a % MOD;
            p /= 2;
        }
        else
        {
            res = res * 1ll * a % MOD;
            p--;
        }
    }
    return res;
}

//! Solved on my own
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m >> k;
    ll t = n / k;
    ll t2 = n % k;
    temp = t * (k - 1) + t2;
    if (m > temp)
    {
        t = m - temp;
        temp -= t * (k - 1);
        ll ans = 0;
        /*
        for (i = 1; i <= t; i++)
        {
            ans += k;
            ans *= 2;
            ans %= MOD;
        }
        */
        //! the above for loob can be simply converted to, write down the expression on paper
        ans += 2 * k * ((fast_pow(2, t) - 1) % MOD);
        // deb(ans + temp);
        // deb2(ans, temp);
        cout << (temp + ans) % MOD << endl;
    }
    else
    {
        cout << m % MOD << endl;
        return;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================