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
const int N = INT_MAX, M = N;
//=======================

//! Attempt 1, I didn't figure out the flaw in this, a bit clumsy approach....should have though in terms of min and max
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> k;
    vl A(n + 1);
    ll dp[n + 1][2];
    clr(dp);

    fo(i, 0, n)
    {
        cin >> A[i];
    }

    for (i = 1; i < n; i++)
    {
        if (i == 1)
        {
            if (abs(A[i] - A[i - 1]) < k)
            {
                dp[i][0] = 1;
            }
            if (abs((A[i] + k - 1) - A[i - 1]) < k)
            {
                dp[i][1] = 1;
            }
        }
        else if (i == n - 1)
        {

            if (dp[i - 1][0] == 1)
            {
                if (abs(A[i] - A[i - 1]) < k)
                {
                    dp[i][0] = 1;
                }
            }
            if (dp[i - 1][1] == 1)
            {
                if (abs(A[i] - (A[i - 1] + k - 1)) < k)
                {
                    dp[i][0] = 1;
                }
            }
        }
        else
        {
            if (dp[i - 1][0] == 1)
            {
                if (abs(A[i] - A[i - 1]) < k)
                {
                    dp[i][0] = 1;
                }
                if (abs((A[i] + k - 1) - A[i - 1]) < k)
                {
                    dp[i][1] = 1;
                }
            }
            if (dp[i - 1][1] == 1)
            {
                if (abs(A[i] - (A[i - 1] + k - 1)) < k)
                {
                    dp[i][0] = 1;
                }
                if (abs((A[i] + k - 1) - (A[i - 1] + k - 1)) < k)
                {
                    dp[i][1] = 1;
                }
            }
        }

        if (dp[i][0] == 0 && dp[i][1] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

//! Correct solution

void solve2()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> k;
    vl A(n + 1);
    ll dp[n + 1][2];
    clr(dp);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    dp[0][0] = A[0];
    dp[0][1] = A[0];

    for (i = 1; i < n - 1; i++)
    {
        dp[i][0] = max(dp[i - 1][0] - (k - 1), A[i]);
        dp[i][1] = min(dp[i - 1][1] + k - 1, A[i] + k - 1);
        if (dp[i][0] > dp[i][1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (A[n - 1] >= dp[i - 1][0] - (k - 1) && A[n - 1] <= dp[i - 1][1] + k - 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================