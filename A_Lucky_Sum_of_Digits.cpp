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
    m = n;
    if (n < 4)
    {
        cout << -1 << endl;
        return;
    }
    j = 0;
    while (n > 0)
    {

        if (n % 7 == 0)
        {
            for (i = 0; i < j; i++)
            {
                cout << 4;
            }
            k = n / 7;
            for (i = 0; i < k; i++)
            {
                cout << 7;
            }
            cout << endl;
            return;
        }
        n = n - 4;
        j++;
    }
    if (m % 4 == 0)
    {
        j = m / 4;
        for (i = 0; i < j; i++)
        {
            cout << 4;
        }
        cout<<endl;
        return;
    }
    cout << -1 << endl;
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