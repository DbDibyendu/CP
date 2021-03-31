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
const int MOD = 1'000'000'007;
const int N = 2e5 + 10, M = N;
//=======================
const int e = 1e5;

// ! solved on my own
//! Logic is okay, TLE on test 11
//* Approach 1

int calc(int i, int r, int g, map<ll, ll> hash)
{
    int ans = 0;
    if (i == 1)
    {

        if (r >= 1 && g >= 1)
        {
            // dp[g][r] = 2;
            hash[(g * e + r)] = 2;
            return 2;
        }
        else if (r >= 1)
        {
            hash[(g * e + r)] = 1;
            return 1;
        }
        else
        {
            hash[(g * e + r)] = 1;
            return 1;
        }
    }
    if (hash[(g * e + r)] != 0)
    {
        return hash[(g * e + r)];
    }
    if (r - i >= 0)
    {
        ans += calc(i - 1, g, r - i, hash);
    }
    if (g - i >= 0)
    {
        ans += calc(i - 1, g - i, r, hash);
    }
    // deb(ans);
    hash[(g * e + r)] = ans % MOD;
    return hash[(g * e + r)];
}

//! Approach 2, scrolling dp problem
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    ll r, g;
    cin >> r >> g;
    ll t = r + g;
    flag = t;
    while (t)
    {
        k = (int)sqrt((2 * t));
        if (k * (k + 1) == 2 * t)
        {
            break;
        }
        t--;
    }
    // deb(t);
    // map<ll, ll> hash;
    // temp = calc(k, r, g, hash);
    ll dp[N];
    clr(dp);
    dp[0] = 1;
    for (i = 1; i <= k; i++)
    {
        for (j = r; j >= i; j--)
        {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
   
    }

    for (j = 0; j <= r; j++) //! starting with j=0 because, it includes the case when g is taken initially  
    {
        if (t - j <= g)
        {
            temp += dp[j];
            temp %= MOD;
        }
    }

    cout << temp << endl;
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