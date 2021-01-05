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
typedef vector<vi> vvi;
typedef vector<ll> vl;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

ll bin_pow(ll x, ll y);

void solve()
{

    ll i, j, n, m, k, a, b;
    ll temp = 0, flag = 1;
    string A;
    cin >> A >> a >> b;
    string B = A;
    reverse(B.begin(), B.end());
    n = A.length();
    int pref[n], suff[n];

    pref[0] = (A[0] - '0') % a;
    for (i = 1; i < n; i++)
    {
        pref[i] = (pref[i - 1] * 10 + (A[i] - '0')) % a;
    }

    suff[n - 1] = (A[n - 1] - '0') % b;
    for (i = n - 2; i >= 0; i--)
    {
        flag *= 10;
        flag %= b;
        suff[i] = (suff[i + 1] + (A[i] - '0') * flag) % b;
    }

    for (i = 0; i < n; i++)
    {
        if (pref[i] == 0 && suff[i + 1] == 0 && A[i + 1] != '0')
        {
            cout << "YES" << endl;
            fo(j, 0, i + 1) cout << (A[j]);
            cout << endl;
            for (j = i + 1; j < n; j++)
                cout << A[j];
            return;
        }
    }

    cout << "NO" << endl;
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

ll bin_pow(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y % 2)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}