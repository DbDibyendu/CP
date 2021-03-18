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

//! Bit wise logic..... just needed to think a bit
void solve()
{

    ll temp = 0, flag = 1;
    ll l, r;
    cin >> l >> r;
    ll i, j, k;
    if (l == r)
    {
        cout << (l ^ r) << endl;
        return;
    }
    i = 0;
    while (l > 0 || r > 0)
    {
        if (l % 2 != r % 2)
        {
            k = i;
        }
        i++;
        l /= 2;
        r /= 2;
    }
    ll answer = pow(2, k + 1);
    // deb(answer);
    cout << answer - 1 << endl;
    // deb(temp);
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

/*
if ((i >> 1) % 2 == 1 && (j >> 1) % 2 == 1)
{
    i /= 2;
    j /= 2;
}
*/