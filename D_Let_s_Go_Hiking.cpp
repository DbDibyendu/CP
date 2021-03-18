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
    cin >> n;
    vl A(n);
    ll dp[n + 1][2] = {0};
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    ll count = 0;
    vl q1, q0;
    fo(i, 1, n)
    {

        if (A[i] > A[i - 1])
        {
            dp[i][0] = dp[i - 1][0] + 1;
        }

        q0.pb(dp[i][0]);
    }
    sort(q0.rbegin(), q0.rend());
    for (i = n - 1; i > 0; i--)
    {
        if (A[i - 1] > A[i])
        {
            dp[i - 1][1] = dp[i][1] + 1;
        }

        q1.pb(dp[i - 1][1]);
    }
    sort(q1.rbegin(), q1.rend());


    fo(i, 0, n)
    {
        // deb2(dp[i][0], dp[i][1]);
        if (dp[i][0] == q0[0] || dp[i][1] == q1[0])
        {
            if (dp[i][0] > dp[i][1])
            {

                if (q0[1] >= dp[i][1] || q1[1] >= dp[i][1] || q1[0] > dp[i][1])
                {
                }
                else
                {
                    // ! If even then Q will lose
                    if (dp[i][0] % 2 == 0)
                    {
                        if (dp[i][0] - 1 >= dp[i][1])
                        {
                        }
                        else
                        {
                            temp++;
                        }
                    }
                }
            }
            else
            {
                if (q1[1] >= dp[i][0] || q0[1] >= dp[i][0] || q0[0] > dp[i][0])
                {
                }
                else
                {
                    if (dp[i][0] == dp[i][1])
                    {
                        if (dp[i][0] != 0)
                            if (dp[i][0] % 2 == 0)
                            {
                                temp++;
                            }
                    }
                    else
                    {

                        if (dp[i][1] % 2 == 0)
                        {
                            if (dp[i][1] - 1 >= dp[i][0])
                            {
                            }
                            else
                            {
                                temp++;
                            }
                        }
                    }
                }
            }
        }
        // deb(temp);
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