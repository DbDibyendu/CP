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

//! A bit tricky question, but solvend on my own 
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 0;
    cin >> n;
    vi A(n);
    read(A);
    m = n;
    vi check;
    for (i = 2; i <= m; i++)
    {
        if (i >= 3 && m % i == 0)
        {
            check.push_back(i);
            m /= i;
        }
    }
    for (auto x : check)
    {
        int f2 = 1;
        for (j = 0; j < (n / x); j++) //! This step is a bit tricky, I figured out on my own (n/x)
        {
            f2 = 1;
            for (i = j; i < n; i += (n / x))
            {
                // deb2(i, A[i]);
                if (A[i] == 0)
                {
                    f2 = 0;
                    break;
                }
            }
            // deb2(f2, j);
            if (f2 == 1)
            {
                break;
            }
        }
        if (f2 == 1)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================