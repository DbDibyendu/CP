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
typedef vector<vi> vvi;
typedef vector<ll> vl;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================


/******* Solve carefully *******/

void solve()
{

    int i, j, n, m, k;
    string A;
    ll ans = 0, temp = 0;
    int Min = N, Max = 0;
    int MinAlpha = 0;

    cin >> n >> m >> A;
    vi check(n, 0);

    for (i = 0; i < (n / 2); i++)
    {

        if (A[i] == A[n - i - 1])
        {
            check[i] = 1;
            check[n - i - 1] = 1;
            temp++;
        }
    }
    if (2 * temp == n || 2 * temp + 1 == n)
    {
        cout << 0 << endl;
        return;
    }
    if (m <= n / 2)
    {

        for (i = 0; i < n / 2; i++)
        {
            if (check[i] == 0)
            {
                Min = min(Min, i);
                Max = max(Max, i);
                MinAlpha = min(abs(A[n - 1 - i] - A[i]), 26 - abs(A[n - 1 - i] - A[i]));
                ans += MinAlpha;
            }
        }
        if (Min == Max)
        {
            ans += abs(Max - (m - 1));
        }
        else if (abs(Min - (m - 1)) > abs(Max - (m - 1)))
        {
            if ((Min - (m - 1)) * (Max - (m - 1)) < 0)
            {

                ans += 2 * abs(Max - (m - 1));
                ans += abs(Min - (m - 1));
            }
            else
            {
                ans += abs(Min - (m - 1));
            }
        }
        else
        {
            if ((Min - (m - 1)) * (Max - (m - 1)) < 0)
            {
                ans += 2 * abs(Min - (m - 1));
                ans += abs(Max - (m - 1));
            }
            else
            {
                ans += abs(Max - (m - 1));
            }
        }
    }
    else
    {
        if (n % 2 == 0)
        {
            for (i = (n / 2); i < n; i++)
            {
                if (check[i] == 0)
                {
                    Min = min(Min, i);
                    Max = max(Max, i);
                    MinAlpha = min(abs(A[n - 1 - i] - A[i]), 26 - abs(A[n - 1 - i] - A[i]));
                    ans += MinAlpha;
                }
            }
        }
        else
        {

            for (i = (n / 2) + 1; i < n; i++)
            {
                if (check[i] == 0)
                {
                    Min = min(Min, i);
                    Max = max(Max, i);
                    MinAlpha = min(abs(A[n - 1 - i] - A[i]), 26 - abs(A[n - 1 - i] - A[i]));
                    ans += MinAlpha;
                }
            }
        }

        if (Min == Max)
        {
            ans += abs(Min - (m - 1));
        }
        else if (abs(Min - (m - 1)) > abs(Max - (m - 1)))
        {
            if ((Min - (m - 1)) * (Max - (m - 1)) < 0)
            {

                ans += 2 * abs(Max - (m - 1));
                ans += abs(Min - (m - 1));
            }
            else
            {
                ans += abs(Min - (m - 1));
            }
        }
        else
        {
            if ((Min - (m - 1)) * (Max - (m - 1)) < 0)
            {
                ans += 2 * abs(Min - (m - 1));
                ans += abs(Max - (m - 1));
            }
            else
            {
                ans += abs(Max - (m - 1));
            }
        }
    }
    cout << ans << endl;
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