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

int flag = 0;

int check(int n, int d)
{

    if (n % d == 0)
    {
        // cout << "YES" << endl;
        flag = 1;
        return 1;
    }
    if (n > 0)
    {
        int m = n;
        while (m > 1)
        {

            if (m % 10 == d)
            {
                flag = 1;
                return 1;
            }
            else
            {
                m /= 10;
            }
        }

        check(n - d, d);
    }
    return 0;
}

void solve()
{

    int i, j, n, m, k, q, d;
    ll temp = 0;
    cin >> q >> d;
    vl A(q);
    fo(i, 0, q)
    {
        cin >> A[i];
    }
    fo(i, 0, q)
    {
        // deb(check(A[i], d));
        if (check(A[i], d) || flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        flag = 0;
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