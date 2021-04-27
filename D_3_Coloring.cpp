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

    vector<pair<int, int>> even;
    vector<pair<int, int>> odd;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if ((i + j) % 2 == 1)
            {
                odd.pb({i, j});
            }
            else
            {
                even.pb({i, j});
            }
        }
    }

    fo(i, 1, n + 1)
    {
        fo(j, 1, n + 1)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                if (odd.size())
                {
                    cout << "2 " << odd.back().first << " " << odd.back().second << endl;
                    odd.pop_back();
                }
                else
                {
                    cout << "3 " << even.back().first << " " << even.back().second << endl;
                    even.pop_back();
                }
            }
            else if (x == 2)
            {
                if (even.size())
                {
                    cout << "3 " << even.back().first << " " << even.back().second << endl;
                    even.pop_back();
                }
                else
                {
                    cout << "1 " << odd.back().first << " " << odd.back().second << endl;
                    odd.pop_back();
                }
            }
            else
            {
                if (odd.size())
                {
                    cout << "2 " << odd.back().first << " " << odd.back().second << endl;
                    odd.pop_back();
                }
                else
                {
                    cout << "1 " << even.back().first << " " << even.back().second << endl;
                    even.pop_back();
                }
            }
        }
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