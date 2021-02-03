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

// 2 Pointer problem
// A really nice approach, which I couldn't figure out
void solve()
{

    ll i, j, n, m, k, one = 0, two = 0;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    ll cost1 = 0;
    vl A(n);
    vl Apps1;
    vl Apps2;
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    int x;
    fo(i, 0, n)
    {
        cin >> x;
        if (x == 1)
        {
            Apps1.pb(A[i]);
        }
        else
        {
            Apps2.pb(A[i]);
        }
    }

    sort(Apps1.rbegin(), Apps1.rend());
    sort(Apps2.rbegin(), Apps2.rend());
    j = Apps2.size();
    ll cost2 = accumulate(Apps2.begin(), Apps2.end(), 0ll);
    temp = INT_MAX;

    fo(i, 0, Apps1.size() + 1)
    {
        while (j > 0 && cost2 + cost1 - Apps2[j - 1] >= m)
        {
            cost2 -= Apps2[j - 1];
            j--;
        }
        if (cost1 + cost2 >= m)
        {
            temp = min(temp, 2 * j + i);
        }
        if (i < Apps1.size())
            cost1 += Apps1[i];
    }
    if (temp == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << temp << endl;
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