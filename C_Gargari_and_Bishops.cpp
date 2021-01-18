
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
    int i,j;
    ll n;
    cin >> n;
    ll a[n][n];
    vl d1(4 * n, 0), d2(4 * n, 0);
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            cin >> a[i][j];
            d1[i - j + n] += a[i][j];
            d2[i + j] += a[i][j];
        }
    }
    vl ans(2, -1);
    std::vector<pll> res(2);
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            int c = (i + j) % 2;
            if (ans[c] < d1[i - j + n] + d2[i + j] - a[i][j])
            {
                ans[c] = d1[i - j + n] + d2[i + j] - a[i][j];
                res[c].first = i + 1;
                res[c].second = j + 1;
            }
        }
    }
    cout << ans[0] + ans[1] << '\n';
    fo(i, 0, 2)
    cout << res[i].first << ' ' << res[i].second << ' ';
 
 
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