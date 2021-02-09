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
    cin >> n >> k;
    if (n == 1)
    {
        if (k == 0)
        {
            cout << 1 << endl;
            return;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    m = n / 2;
    j = k - (m - 1);
    if (j > 0)
    {
        fo(i, 0, n)
        {
            if (i == 0)
            {
                cout << j << " ";
            }
            else if (i == 1)
            {
                cout << j * 2 << " ";
            }
            else
            {
                cout << j * 2 + i - 1 << " ";
            }
        }
    }
    else
    {
        cout << -1 << endl;
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