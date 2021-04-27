//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯

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
const int N = 1e3 + 10, M = N;
//=======================

ll A[N][N];
ll sum_row[1000005];
ll sum_col[1000005];
//! Tough multiset impelentation problem
void solve()
{

    ll i, j, n, m, k, p;
    ll temp = 0, flag = 1;
    cin >> n >> m >> k >> p;

    clr(sum_row), clr(sum_col);
    multiset<ll> rows, cols;

    fo(i, 0, n)
    {
        int sum_row = 0;
        fo(j, 0, m)
        {
            cin >> A[i][j];
            sum_row += A[i][j];
        }
        rows.insert(-sum_row);
    }

    fo(j, 0, m)
    {
        int sum_col = 0;
        fo(i, 0, n)
        {
            sum_col += A[i][j];
        }
        cols.insert(-sum_col);
    }

    ll srow = 0, scol = 0;
    for (i = 1; i <= k; i++)
    {
        temp = -(*rows.begin());
        rows.erase(rows.begin());
        rows.insert(-(temp - m * p));
        srow += temp;
        sum_row[i] = srow;

        flag = -(*cols.begin());
        cols.erase(cols.begin());
        cols.insert(-(flag - n * p));
        scol += flag;
        sum_col[i] = scol;
    }
    temp = -1e18;
    for (i = 0; i <= k; i++)
    {
        ll sum = (sum_row[i] + sum_col[k - i] - (ll)i * (k - i) * p);
        temp = max(temp, sum);
    }

    cout << temp << endl;
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