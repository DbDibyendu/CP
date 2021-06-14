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

//! Easy peasy
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vector<string> A(n);
    read(A);
    vi col(n, 0);
    vi row(n, 0);
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            if (A[i][j] == '.')
            {
                col[j]++;
                row[i]++;
            }
        }
    }
    fo(i, 0, n)
    {
        if (col[i] == 0)
        {
            flag = 0;
        }
    }
    int flag2 = 1;
    fo(i, 0, n)
    {
        if (row[i] == 0)
        {
            flag2 = 0;
        }
    }
    if (flag == 0 && flag2 == 0)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        if (flag)
        {
            fo(j, 0, n)
            {
                fo(i, 0, n)
                {
                    if (A[i][j] == '.')
                    {
                        cout << i + 1 << " " << j + 1 << endl;
                        break;
                    }
                }
            }
        }
        else
        {
            fo(i, 0, n)
            {
                fo(j, 0, n)
                {
                    if (A[i][j] == '.')
                    {
                        cout << i + 1 << " " << j + 1 << endl;
                        break;
                    }
                }
            }
        }
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