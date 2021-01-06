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
typedef vector<vi> vvi;
typedef vector<ll> vl;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

// The tube can be bent...like L
void solve()
{

    int i, j, n, m, k, rem = 0, cap;
    ll temp = 0, flag = 1;
    cin >> n >> m >> k;
    int x = 1, y = 1;
    int dir = -1;
    k--;
    cap = 2;
    rem = (n * m) - (cap * k);
    while (k--)
    {

        cout << cap << " ";
        if (y == 1 && dir == -1)
        {
            dir *= -1;
        }
        for (i = 0; i < cap; i++)
        {
            cout << x << " " << y << " ";
            if (y == 1 && dir == -1)
            {
                dir *= -1;
                x++;
            }
            else if (y == m && dir == 1)
            {
                dir *= -1;
                x++;
            }
            else
            {
                y += dir;
            }
        }
        cout << endl;
    }

    cout << rem << " ";
    if (y == 1 && dir == -1)
    {
        dir *= -1;
    }
    for (i = 0; i < rem; i++)
    {
        cout << x << " " << y << " ";
        if (y == 1 && dir == -1)
        {
            dir *= -1;
            x++;
        }
        else if (y == m && dir == 1)
        {
            dir *= -1;
            x++;
        }
        else
        {
            y += dir;
        }
    }
    cout << endl;
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