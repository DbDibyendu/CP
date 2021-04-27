//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯

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
//! Good question based on segment trees

ll n;
ll A[200000], stree_min[800004], stree_max[800004];

// ? Segment Trees

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        stree_max[si] = A[ss];
        stree_min[si] = A[ss];
        return;
    }

    ll mid = (ss + se) / 2;

    build(2 * si + 1, mid + 1, se);
    build(2 * si, ss, mid);

    stree_min[si] = min(stree_min[2 * si + 1], stree_min[2 * si]);
    stree_max[si] = max(stree_max[2 * si + 1], stree_max[2 * si]);
}

ll query_min(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs) // !Completely Outside
        return MOD;
    if (qs <= ss && qe >= se) // ! Completely Inside
        return stree_min[si];

    ll mid = (ss + se) / 2;
    return min(query_min(2 * si, ss, mid, qs, qe), query_min(2 * si + 1, mid + 1, se, qs, qe));
}

ll query_max(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs) // !Completely Outside
        return -MOD;
    if (qs <= ss && qe >= se) // ! Completely Inside
        return stree_max[si];

    ll mid = (ss + se) / 2;
    return max(query_max(2 * si, ss, mid, qs, qe), query_max(2 * si + 1, mid + 1, se, qs, qe));
}

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    string s;
    cin >> s;
    int prefix_value[n + 1];
    clr(prefix_value);
    int x = 0;
    prefix_value[0] = 0;
    fo(i, 1, n + 1)
    {
        if (s[i - 1] == '+')
        {
            x++;
            prefix_value[i] += prefix_value[i - 1] + 1;
        }
        else
        {
            prefix_value[i] += prefix_value[i - 1] - 1;
            x--;
        }
        // deb(prefix_value[i]);
        A[i] = x;
    }
    build(1, 1, n);
    int Pmin = MOD, Pmax = -MOD, Smin = MOD, Smax = -MOD;

    j = 1;

    fo(i, 0, m)
    {
        int l, r;
        cin >> l >> r;
        flag = 1;
        int val = prefix_value[r] - prefix_value[l - 1];
        int mx = 0, mn = 0;
        if (l > 1)
        {
            mn = min((ll)mn, query_min(1, 1, n, 1, l - 1));
            mx = max((ll)mx, query_max(1, 1, n, 1, l - 1));
        }

        if (r < n)
        {
            mn = min((ll)mn, query_min(1, 1, n, r + 1, n) - val);
            mx = max((ll)mx, query_max(1, 1, n, r + 1, n) - val);
        }
        // deb(val);
        cout << mx - mn + 1 << endl;
    }
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