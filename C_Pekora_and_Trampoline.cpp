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
const int N = 5010, M = N;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    ll A[N] = {0};
    ll pre[N] = {0};
    fo(i, 1, n + 1)
    {
        cin >> A[i];
    }
    for (i = 1; i <= n; i++)
    {
        if (A[i] == 1)
        {
            continue;
        }
        else
        {
            if (i + A[i] >= n)
            {
                for (j = i + 2; j <= n; j++)
                {
                    pre[j]++;
                }
            }
            else
            {
                for (j = i + 2; j <= (i + A[i]); j++)
                {
                    pre[j]++;
                }
            }
        }
    }

    fo(i, 1, n + 1)
    {
        if (A[i] - pre[i] > 1)
        {
            temp += A[i] - pre[i] - 1;
        }
        else
        {
            pre[i + 1] += pre[i] - A[i] + 1;
        }
        // deb2(temp, pre[i]);
    }

    cout << temp << endl;
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