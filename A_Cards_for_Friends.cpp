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

    ll i, j, n, m, k, w, h;
    ll temp = 1, flag = 1;
    cin >> w >> h >> n;

    while (1)
    {
        if (w % 2 == 0)
        {
            temp *= 2;
            w /= 2;
        }
        else if (h % 2 == 0)
        {
            temp *= 2;
            h /= 2;
        }
        else
        {
            break;
        }
    }
  
    if (temp >= n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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