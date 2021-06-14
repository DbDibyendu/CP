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
    cin >> n >> m;
    string A, B;
    cin >> A;
    B = A;
    for (j = 0; j < min(n, m); j++)
    {
        for (i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (A[i] - '0' == 0)
                {
                    if (A[i + 1] - '0' == 1)
                    {
                        B[i] = '1';
                    }
                }
            }
            else if (i == n - 1)
            {
                if (A[i] - '0' == 0)
                {
                    if (A[i - 1] - '0' == 1)
                    {
                        B[i] = '1';
                    }
                }
            }
            else
            {
                if (A[i] - '0' == 0)
                {
                    if (A[i - 1] - '0' == 1 && A[i + 1] - '0' == 1)
                    {
                        continue;
                    }
                    else if (A[i - 1] - '0' == 1 || A[i + 1] - '0' == 1)
                    {
                        B[i] = '1';
                    }
                }
            }
            // deb(A);
        }
        A = B;
        // deb(A);
    }
    cout << A << endl;
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