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
const int N = INT_MAX, M = N;
//=======================
ll n;
ll A[100000], stree[400004];

// ? Segment Trees

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        stree[si] = A[ss];
        return;
    }

    ll mid = (ss + se) / 2;

    build(2 * si + 1, mid + 1, se);
    build(2 * si, ss, mid);

    stree[si] = min(stree[2 * si + 1], stree[2 * si]);
}

ll query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)     // !Completely Outside
        return MOD; 
    if (qs <= ss && qe >= se)    // ! Completely Inside
        return stree[si];

    ll mid = (ss + se) / 2;
    return min(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
}

void solve()
{

    int i, j, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    fo(i, 1, n + 1)
    {
        cin >> A[i];
    }
    build(1, 1, n);

    cin >> k;
    while (k--)
    {
        cin >> i >> j;
        cout << query(1, 1, n, i + 1, j + 1) << endl;
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