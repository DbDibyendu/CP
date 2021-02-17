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

void solve2()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    if (n & 1)
    {
        for (i = 1; i <= (n * (n - 1)) / 2; i++)
        {
            if (i & 1)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
        // cout << endl;
    }
    else
    {

        for (i = 1; i < n; i++)
        {
            for (j = 1; j <= n - i; j++)
            {
                if (i & 1 && j == 1)
                {
                    cout << 0 << " ";
                }
                else
                {
                    if (j & 1)
                    {
                        cout << -1 << " ";
                    }
                    else
                    {
                        cout << 1 << " ";
                    }
                }
            }
            // deb(i);
        }
    }
    cout << endl;
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    if (n & 1)
    {
        for (i = 1; i <= (n * (n - 1)) / 2; i++)
        {
            if (i & 1)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
        // cout << endl;
    }
    else
    {
        m = k = n - 1;
        j = 1;
        for (i = 1; i <= (n * (n - 1)) / 2; i++)
        {
            if (i == k)
            {
                // deb(i);
                cout << 0 << " ";
                k += m - 1;
                m--;
                j = 1;
            }
            else
            {
                if (j & 1)
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << -1 << " ";
                }
                j++;
            }
        }
    }
    cout << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================