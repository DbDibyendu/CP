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

//! Good Implementation
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    ll dp1[11];
    ll dp2[11];
    ll ans[N + 10];
    clr(dp1), clr(dp2);
    dp1[0] = 1;
    for (i = 1; i <= N; i++)
    {
        ll sum = 0;
        if (i & 1)
        {
            for (j = 9; j >= 0; j--)
            {
                if (dp1[j])
                {
                    if (j == 9)
                    {
                        dp2[0] += dp1[j] % MOD;
                        dp2[1] += dp1[j] % MOD;
                    }
                    else
                    {
                        dp2[j + 1] += dp1[j] % MOD;
                    }
                }
            }
            for (j = 0; j <= 9; j++)
            {
                sum += dp2[j];
            }
            clr(dp1);
        }
        else
        {
            for (j = 9; j >= 0; j--)
            {
                if (dp2[j])
                {
                    if (j == 9)
                    {
                        dp1[0] += dp2[j] % MOD;
                        dp1[1] += dp2[j] % MOD;
                    }
                    else
                    {
                        dp1[j + 1] += dp2[j] % MOD;
                    }
                }
            }
            for (j = 0; j <= 9; j++)
            {
                sum += dp1[j];
            }
            clr(dp2);
        }
        ans[i] = sum % MOD; // ! i Operations on 0
    }

    cin >> t;
    //! This is the main part which I should have given a thought
    while (t--)
    {
        cin >> n >> m;
        ll res = 0;
        while (n)
        {
            res += ans[m + n % 10];
            n /= 10;
        }
        cout << res % MOD << endl;
    }
    return 0;
}

//=======================