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

    ll i, j, n, m, k, p;
    ll temp = 0, flag = 1;
    cin >> n >> m >> p;
    vector<string> A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    ll t[2][m];
    for (i = 0; i < m; i++)
    {
        t[0][i] = 1;
        t[1][i] = 1;
        // cout << t[0][i] << " ";
    }
    for (i = 0; i < (n + 1) / 2; i++)
    {
        fo(j, 0, m)
        {
            t[0][j] &= (int)A[i][j] - '0';
        }
    }
    for (i = (n - 1) / 2; i < n; i++)
    {
        fo(j, 0, m)
        {
            t[1][j] &= (int)A[i][j] - '0';
        }
    }
    ll temp1 = 0, temp2 = 0;
    for (auto x : t[0])
    {
        if (x)
        {
            temp1++;
        }
    }
    for (auto x : t[1])
    {
        if (x)
        {
            temp2++;
        }
    }
    if (temp1 > temp2)
    {
        for (auto x : t[0])
        {
            cout << x;
        }
    }
    else
    {
        for (auto x : t[1])
        {
            cout << x;
        }
    }
    cout << endl;
    // display(t[0]);
    // display(t[1]);
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