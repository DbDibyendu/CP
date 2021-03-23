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
    ll temp = 0, flag = 0;
    ll a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << -1 << endl;
        return;
    }
    temp = abs(b - a);
    for (i = 1; i * i <= temp; i++)
    {
        if (temp % i == 0)
        {
            if (temp / i == i)
            {
                flag++;
            }
            else
            {
                flag += 2;
            }
            // cout << i << " " << temp / i << " ";
        }
    }
    cout << flag << endl;
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