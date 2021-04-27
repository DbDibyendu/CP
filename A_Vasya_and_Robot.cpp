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

    int i, j, n, m, k, l, r, Qr, Ql;
    ll temp = MOD, flag = 1;
    cin >> n >> l >> r >> Ql >> Qr;
    vi W(n);
    fo(i, 0, n)
    {
        cin >> W[i];
    }
    ll r_pick[n + 1], l_pick[n + 1];
    clr(r_pick), clr(l_pick);
    i = 0, j = n - 1;
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
            l_pick[i] = W[i - 1] * l;
        else
        {
            l_pick[i] = l_pick[i - 1] + W[i - 1] * l;
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            r_pick[i] = W[i] * r;
        else
        {
            r_pick[i] = r_pick[i + 1] + W[i] * r;
        }
    }
    for (i = 0; i <= n; i++)
    {
        // deb2(l_pick[i], r_pick[i]);
        int R = 0, L = 0;
        if ((n - i - i - 1) > 0)
            R = (n - 2 * i - 1) * Qr;
        if ((2 * i - n - 1) > 0)
            L = (2 * i - n - 1) * Ql;
        // deb2(L, R);
        temp = min(temp, r_pick[i] + R + L + l_pick[i]);
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