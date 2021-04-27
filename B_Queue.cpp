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
    vl A(n + 1);
    vl dp(n, 0);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            dp[i] = A[i];
        else
        {
            dp[i] = A[i];
            dp[i] = min(dp[i], dp[i + 1]);
        }
    }

    fo(i, 0, n - 1)
    {
        auto it = lower_bound(dp.begin(), dp.end(), A[i]);
        int index = it - dp.begin();
        if (index - i - 2 < 0)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << index - i - 2 << " ";
        }
        // deb(index - i - 2);
    }
    cout << -1;
}

int main()
{
    int t = 1;

    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================
