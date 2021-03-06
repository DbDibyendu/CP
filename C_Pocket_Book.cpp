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
    ll temp = 0, flag = 1;
    cin >> n >> m;
    vector<string> A;
    string x;
    fo(i, 0, n)
    {
        cin >> x;
        A.pb(x);
    }
    map<char, ll> s;
    for (i = 0; i < m; i++)
    {
        s.clear();
        for (j = 0; j < n; j++)
        {

            s[A[j][i]]++;
        }

        flag *= s.size();
        flag = flag % MOD;
    }

    cout << flag << endl;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================