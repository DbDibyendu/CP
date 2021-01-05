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

void solve()
{

    int i, j, n, m, k, l, t, init;
    ll temp = 0, flag = 1;
    cin >> n >> m >> k;
    init = n * m / k;
    l = k;
    i = 0;
    while (l--)
    {
        cout << init << " ";
        i++;
        if (flag == 1)
        {
            for (j = 1; j <= m; j++)
            {
                cout << i << " " << j<<" ";
            }
            flag = 0;
        }
        else
        {
            for (j = m; j > 0; j--)
            {
                cout << i << " " << j<<" ";
            }
            flag = 1;
        }
        cout << endl;
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