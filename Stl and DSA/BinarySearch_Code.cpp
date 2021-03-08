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

//! Binary search 
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> k;
    vl A(n + 1);
    fo(i, 1, n + 1)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    ll l = 1, r = n, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (k > A[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << endl;
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