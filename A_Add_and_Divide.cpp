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

    ll i, j, n, m, k, a, b;
    ll temp = MOD, flag = 1;
    cin >> a >> b;
    temp = a + 1;
    m = a;
    if (b > a)
    {
        cout << 1 << endl;
    }
    else if (b == a)
    {
        cout << 2 << endl;
    }
    else
    {

        for (i = b; i <= b + 10; i++)
        {

            for (j = 0; j <= 100; j++)
            {
                if (pow(i, j) > a)
                {
                    // deb(j);
                    temp = min(i - b + j, temp);
                }
            }
        }
        cout << temp << endl;

    } // ll l = b, r = a;

    // cout << temp << endl;
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