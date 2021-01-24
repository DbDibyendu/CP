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
    string b;
    cin >> n;
    cin >> b;
    int sum[n] = {};
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    cout << 1;
    sum[0] = 1 + (int)b[0] - '0';
    for (i = 1; i < n; i++)
    {
        if (sum[i - 1] == 1)
        {
            if ((int)b[i] - '0' == 1)
            {
                cout << 1;
                sum[i] = 1 + (int)b[i] - '0';
            }
            else if ((int)b[i] - '0' == 0)
            {
                cout << 0;
                sum[i] = 0 + (int)b[i] - '0';
            }
        }
        else if (sum[i - 1] == 2)
        {
            if ((int)b[i] - '0' == 1)
            {
                cout << 0;
                sum[i] = 0 + (int)b[i] - '0';
            }
            else if ((int)b[i] - '0' == 0)
            {
                cout << 1;
                sum[i] = 1 + (int)b[i] - '0';
            }
        }
        else if (sum[i - 1] == 0)
        {
            if ((int)b[i] - '0' == 1)
            {
                cout << 1;
                sum[i] = 1 + (int)b[i] - '0';
            }
            else if ((int)b[i] - '0' == 0)
            {
                cout << 1;
                sum[i] = 1 + (int)b[i] - '0';
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