#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef vector<int> vi;
typedef vector<vi> vvi;
//=======================

// Simple pattern printing, focus on how to implement
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1, b = 0;
    cin >> n >> m;

    if (m > (2 * n + 2))
    {
        cout << -1;
        return;
    }
    if (n > (m + 1))
    {
        cout << -1;
        return;
    }
    if (n == m + 1)
    {
        cout << 0;
        n--;
    }

    while (m + n > 0)
    {
        if (n == m)
        {
            cout << 10;
            n--;
            m--;
        }
        else if (m == 2 && n == 0)
        {
            cout << 11;
            m -= 2;
        }
        else if (m == 1 && n == 0)
        {
            cout << 1;
            m--;
        }
        else 
        {
            cout << 110;
            m -= 2;
            n--;
        }
    }
}

int main()
{
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================