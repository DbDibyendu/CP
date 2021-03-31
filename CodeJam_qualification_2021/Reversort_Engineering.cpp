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

    int i, j, c, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> c;
    if (c < n - 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vl A;
    c -= n - 1;
    for (i = n - 1; i >= 1; i--)
    {
        if (c - i >= 0)
        {
            A.pb(i);
            c -= i;
        }
    }
    if (c)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vi ans(n);
    fo(i, 0, n)
    {
        ans[i] = i + 1;
    }
    reverse(A.begin(), A.end());
    for (auto x : A)
    {
        // cout << x << " ";
        reverse(ans.end() - x - 1, ans.end());
    }
    // cout << endl;
    fo(i, 0, n)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    int k = 1;
    while (t--)
    {
        cout << "Case #" << k << ": ";
        solve();
        k++;
    }
    return 0;
}

//=======================