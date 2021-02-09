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


void solve()
{

    ll i, j, n, m, k, P, H;
    ll temp = 0, flag = 1;
    cin >> P >> H >> n;
    vl Pmons(n), Hmons(n);
    vpll mons;
    fo(i, 0, n) cin >> Pmons[i];
    fo(i, 0, n) cin >> Hmons[i];
    fo(i, 0, n)
    {
        mons.pb(make_pair(Pmons[i], Hmons[i]));
    }
    sort(mons.begin(), mons.end());

    ll k2;
    for (i = 0; i < n; i++)
    {
        k = (mons[i].second + P - 1) / P;
        k2 = (H + mons[i].first - 1) / mons[i].first;
        if (k <= k2)
        {
            H -= k * mons[i].first;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
        if (H < 0 && i != n - 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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