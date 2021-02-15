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

int factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * 1ll * i % MOD;
    }
    return res;
}

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    ll t = 720720;
    ll A[n][m], B[n][m];
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            cin >> A[i][j];
            if ((i + j) & 1)
            {
                cout << t + pow(A[i][j], 4) << " ";
            }
            else
            {
                cout << t << " ";
            }
        }
        cout << endl;
    }
    // cout << (3 * 3 * 4 * 5 * 7 * 4 * 11 * 13);
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================