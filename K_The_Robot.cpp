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
    string A;
    cin >> A;
    n = A.length();
    ll x = 0, y = 0;
    ll d = 0, u = 0, l = 0, r = 0;
    vector<pair<ll, ll>> poss;
    fo(i, 0, n)
    {
        if (A[i] == 'D')
        {
            y--;
            d++;
        }
        else if (A[i] == 'U')
        {
            y++;
            u++;
        }
        else if (A[i] == 'R')
        {
            x++;
            r++;
        }
        else
        {
            x--;
            l++;
        }
        poss.pb({x, y});
    }
    while (!poss.empty())
    {
        auto t = poss.back();
        int X = t.first;
        int Y = t.second;
        poss.pop_back();
        x = 0, y = 0;
        // deb2(X, Y);
        fo(i, 0, n)
        {
            if (A[i] == 'D')
            {
                if (y - 1 == Y && x == X)
                {
                }
                else
                    y--;
            }
            else if (A[i] == 'U')
            {

                if (y + 1 == Y && x == X)
                {
                }
                else
                    y++;
            }
            else if (A[i] == 'R')
            {

                if (y == Y && x + 1 == X)
                {
                }
                else
                    x++;
            }
            else
            {

                if (y == Y && x - 1 == X)
                {
                }
                else
                    x--;
            }
            // deb2(x, y);
        }
        if (x == 0 && y == 0)
        {
            cout << X << " " << Y << endl;
            return;
        }
    }
    cout << 0 << " " << 0 << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================