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

// ! Implementation of floyd's algorthim
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    ll A[n + 1][n + 1];
    ll B[n + 1];
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            cin >> A[i][j];
        }
    }

    fo(i, 0, n)
    {
        cin >> B[i];
    }
    ll t, q;
    ll c[n + 1] = {0};
    ll ans[n] = {0};

    for (k = n - 1; k >= 0; k--)
    {
        t = B[k] - 1;
        c[t]++;
        ans[k] = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                A[i][j] = min(A[i][j], A[i][t] + A[t][j]);
                if (c[i] && c[j])
                    ans[k] += A[i][j];
            }
        }
    }
    fo(i, 0, n)
    {
        cout << ans[i] << " ";
    }
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