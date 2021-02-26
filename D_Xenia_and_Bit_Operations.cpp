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
const int N = (1 << 18), M = N;
//=======================
// ! Segment tree question, Update problem of segment tree

ll A[N], stree[4 * N];

void build(int si, int ss, int se, int depth)
{
    if (ss == se)
    {
        stree[si] = A[ss];
        return;
    }

    ll mid = (ss + se) / 2;

    build(2 * si + 1, mid + 1, se, depth + 1);
    build(2 * si, ss, mid, depth + 1);

    if (depth & 1)
        stree[si] = stree[2 * si + 1] | stree[2 * si];
    else
    {
        stree[si] = stree[2 * si + 1] ^ stree[2 * si];
    }
    // deb2(stree[si], si);
}

void update(int si, int ss, int se, int qi, int depth)
{
    if (ss == se)
    {
        stree[si] = A[ss];
        return;
    }

    ll mid = (ss + se) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi, depth + 1);
    else
        update(2 * si + 1, mid + 1, se, qi, depth + 1);

    if (depth & 1)
        stree[si] = stree[2 * si + 1] | stree[2 * si];
    else
    {
        stree[si] = stree[2 * si + 1] ^ stree[2 * si];
    }
    // deb2(stree[si], si);
}

void solve()
{
    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    for (i = 1; i <= (1 << n); i++)
    {
        cin >> A[i];
    }
    build(1, 1, (1 << n), n);
    ll x, y;
    fo(i, 0, m)
    {
        cin >> x >> y;
        A[x] = y;
        update(1, 1, (1 << n), x, n);
        cout << stree[1] << endl;
        // A[x] = k;
    }
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