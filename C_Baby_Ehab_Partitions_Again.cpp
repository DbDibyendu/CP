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
const int N = INT_MAX, M = N;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vi A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
        temp += A[i];
    }
    if (temp % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }
    temp /= 2;
    ll dp[n + 1][temp + 1];
    clr(dp);
    for (i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= temp; j++)
        {

            if (j < A[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
            }
            // deb2(i, j);
            // deb(dp[i][j]);
        }
        // cout << endl;
    }
    if (dp[n][temp] == 0)
    {
        cout << 0 << endl;
        return;
    }

    for (i = 0; i <= 12; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[j] % 2 != 0)
            {
                cout << 1 << endl;
                cout << j + 1 << endl;
                return;
            }
            else
            {
                A[j] /= 2;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================