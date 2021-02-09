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

    ll i, j, n, m, k;
    ll temp = 0, flag = 0;
    ll x, y;
    cin >> x >> y;
    ll r = 0, l = 0, d = 0, u = 0;
    string A;
    cin >> A;
    fo(i, 0, A.length())
    {
        if (A[i] == 'R')
        {
            r++;
        }
        else if (A[i] == 'L')
        {
            l++;
        }
        else if (A[i] == 'U')
        {
            u++;
        }
        else if (A[i] == 'D')
        {
            d++;
        }
    }

    if (x >= 0 && y >= 0)
    {
        if (r >= x && u >= y)
        {

            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (x >= 0 && y <= 0)
    {
        if (r >= x && -d <= y)
        {

            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (x <= 0 && y <= 0)
    {
        if (-l <= x && -d <= y)
        {

            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (x <= 0 && y >= 0)
    {
        if (-l <= x && u >= y)
        {

            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
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