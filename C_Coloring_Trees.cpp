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
const ll N = 1e18, M = N;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m >> k;
    ll P[n + 1][m + 1] = {0}, tree[n + 1] = {0};
    fo(i, 1, n + 1)
    {
        cin >> tree[i];
    }
    fo(i, 1, n + 1)
    {
        fo(j, 1, m + 1)
        {
            cin >> P[i][j];
        }
    }
    ll t = 1;
    ll dp[n + 1][m + 1] = {0};
    fo(j, 1, m + 1)
        dp[1][j] = P[1][j];
    
    fo(i, 1, n)
    {
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