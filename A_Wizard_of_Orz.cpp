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
    k = 0;
    if (n == 1)
    {
        cout << 9 << endl;
        return;
    }
    else if (n == 2)
    {
        cout << 98 << endl;
        return;
    }
    else if (n == 3)
    {
        cout << 989 << endl;
        return;
    }
    else
    {
        cout << 989;
        fo(i, 0, n - 3)
        {

            if (k == 9)
            {
                cout << k;
                k = 0;
            }
            else{
                cout<<k;
                k++;
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
        solve();
    }
    return 0;
}

//=======================