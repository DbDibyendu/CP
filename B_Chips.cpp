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

//! Easy question, just seemed tough in first glance
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    int X[n + 1], Y[n + 1];
    memset(X, 0, sizeof(X));
    clr(Y);

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        X[x] = 1;
        Y[y] = 1;
    }
    vi possible_x, possible_y;
    for (i = 2; i < n; i++)
    {
        if (X[i] == 0)
        {
            possible_x.pb(i);
        }
        if (Y[i] == 0)
        {
            possible_y.pb(i);
        }
    }
    if (n & 1)
    {
        int mid = (n + 1) / 2;
        if (X[mid] == 0 || Y[mid] == 0)
        {
            temp++;
        }
        for (auto x : possible_x)
        {
            if (x != mid)
            {
                temp++;
            }
        }
        for (auto y : possible_y)
        {
            if (y != mid)
            {
                temp++;
            }
        }
    }
    else
    {
        temp += possible_x.size();
        temp += possible_y.size();
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