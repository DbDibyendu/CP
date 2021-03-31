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
const int N = 5e3 + 2, M = N;
//=======================

//! Correct logic, TLE on test case 20
void solve()
{

    int i, j, n, m, k;
    int temp = 0, flag = 1;
    cin >> n >> m;
    int A[N][N];
    // clr(A);
    string c;
    int dp[N][N];
    //! Good logic, tough implementation
    // clr(dp);
    fo(i, 0, n)
    {
        cin >> c;
        fo(j, 0, m)
        {
            A[i][j] = c[j] - '0';
        }

        for (j = m - 1; j >= 0; j--)
        {
            if (A[i][j])
                if (j < m - 1)
                {

                    dp[j][i] += dp[j + 1][i] + 1;
                }
                else
                {
                    dp[j][i] = A[i][j];
                }
        }
    }

    fo(j, 0, m)
    {
        sort(dp[j], dp[j] + n);
        fo(i, 0, n)
        {
            temp = max(temp, (n - i) * dp[j][i]);
        }
        // deb(temp);
        // cout << endl;
    }
    cout << temp << endl;
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