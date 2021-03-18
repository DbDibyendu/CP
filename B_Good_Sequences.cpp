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
const int N = 1e5 + 10, M = N;
//=======================

// ! Good number theory problem
bool isPrime(int n)
{
    int i;
    if (n % 2 == 0 && n != 2)
    {
        return false;
    }
    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n);
    ll dp[N] = {0};

    fo(i, 0, n)
    {
        cin >> A[i];
    }
    fo(i, 0, n)
    {
        if (isPrime(A[i]))
        {
            dp[A[i]] = 1;
        }
        else
        {
            for (j = 2; j * j <= A[i]; j++)
            {
                if (A[i] % j == 0)
                {
                    dp[A[i]] = max(dp[A[i]], 1 + dp[j]);
                    dp[A[i]] = max(dp[A[i]], 1 + dp[A[i] / j]);
                }
            }

            for (j = 2; j * j <= A[i]; j++)
            {
                if (A[i] % j == 0)
                {
                    dp[j] = dp[A[i]];
                    dp[A[i] / j] = dp[A[i]];
                }
            }
        }
        // deb(dp[A[i]]);
    }
    fo(i, 0, n)
    {

        temp = max(dp[A[i]], temp);
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