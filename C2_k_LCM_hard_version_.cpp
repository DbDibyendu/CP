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

    if (k > 3)
    {
        fo(i, 0, k - 3)
        {
            cout << 1 << " ";
            n--;
        }
    }
    k = 3;
    if (n % k == 0)
    {
        fo(i, 0, 3)
        {
            cout << n / k << " ";
        }
        cout << endl;
        return;
    }
    ll mid;
    if (n & 1)
    {
        mid = n / 2;
        cout << mid << " " << mid << " " << 1 << endl;
    }
    else
    {
        mid = n / 2;
        if (mid % 2 == 0)
        {
            cout << mid / 2 << " " << mid / 2 << " " << mid << endl;
        }
        else
        {
            cout << mid - 1 << " " << mid - 1 << " " << 2 << endl;
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