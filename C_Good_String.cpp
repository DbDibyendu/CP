#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)         \
    for (auto &aa : A)     \
        cout << aa << ' '; \
    cout << endl;
#define displayP(A)    \
    for (auto &aa : A) \
    {                  \
        display(aa);   \
    }
#define read(A)        \
    for (auto &aa : A) \
    {                  \
        cin >> aa;     \
    }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A;
    cin >> A;
    n = A.length();
    //! For all equal
    for (i = 0; i < 10; i++)
    {
        ll t = 0;
        for (j = 0; j < n; j++)
        {
            if (A[j] - '0' == i)
            {
                t++;
            }
        }
        temp = max(t, temp);
    }
    int chance = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (j != i)
            {
                ll t = 0;
                chance = 0;
                for (k = 0; k < n; k++)
                {
                    if (A[k] - '0' == i && chance == 0)
                    {
                        t++;
                        chance = 1;
                    }
                    else if (A[k] - '0' == j && chance == 1)
                    {
                        t++;
                        chance = 0;
                    }
                }

                if (t & 1)
                {
                    temp = max(t - 1, temp);
                }
                else
                {
                    temp = max(t, temp);
                }
            }
        }
    }
    cout << n - temp << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================