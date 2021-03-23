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
    string A;
    cin >> A;
    n = A.length();
    ll z = 0, one = 0;
    ll dp[n][2];
    clr(dp);

    flag = -1;
    bool flag1 = 0;
    fo(i, 1, n)
    {
        if (A[i] == '0' && A[i - 1] == '0')
        {
            z++;
            if (flag1 == 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
        if (A[i] == '1' && A[i - 1] == '1')
        {
            one++;
            flag1 = 1;
        }
    }
    cout << "YES" << endl;
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