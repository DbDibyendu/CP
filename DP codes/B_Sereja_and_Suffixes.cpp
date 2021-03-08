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

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    vl A(n + 1), B(m + 1), pre(n + 1, 0);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    map<ll, ll> hash;
    hash[A[n - 1]]++;
    pre[n - 1] = 1;
    for (i = n - 2; i >= 0; i--)
    {
        if (hash[A[i]] == 0)
        {
            hash[A[i]]++;
            pre[i] = pre[i + 1] + 1;
        }
        else
        {
            pre[i] = pre[i + 1];
            continue;
        }
    }
    for (i = 0; i < m; i++)
    {
        cin >> k;
        cout << pre[k - 1] << endl;
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