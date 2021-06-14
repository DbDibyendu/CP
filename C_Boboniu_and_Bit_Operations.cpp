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

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    vi A(n), B(m), C(n);
    read(A);
    read(B);
    for (k = 0; k < pow(2, 9); k++)
    {
        flag = 1;
        for (i = 0; i < n; i++)
        {
            int flag2 = -1;
            for (j = 0; j < m; j++)
            {
                // deb(((A[i] & B[j]) | k));
                if (((A[i] & B[j]) | k) == k)
                {
                    flag2 = 0;
                    break;
                }
            }
            // deb(flag2);
            if (flag2 == -1)
            {
                flag = -1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << k << endl;
            break;
        }
    }

    // cout << temp << endl;
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