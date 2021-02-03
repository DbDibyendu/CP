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

    ll i, j, n, m, k;
    ll temp = 0, flag = 0;
    cin >> n >> k;
    vl P(n);
    vl Prefix(n, 0);
    fo(i, 0, n)
    {
        cin >> P[i];
        if (i > 0)
            Prefix[i] = P[i] + Prefix[i - 1];
        else
        {
            Prefix[i] = P[i];
        }
    }
    ll ans = 0;
    for (i = 1; i < n; i++)
    {
        // deb2(P[i] * 100, k * Prefix[i - 1]);
        if ((P[i] * 100) > k * (Prefix[i - 1] + ans))
        {
            ans = (P[i] * 100 - k * Prefix[i - 1] + k - 1) / k;
        }
        temp = max(ans, temp);
    }
    cout << temp << endl;
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