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
    cin >> n;
    vl A(n), B;
    map<ll, ll> hash;
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    m = n;
    for (i = n - 1; i >= 0; i--)
    {
        if (A[i] == m && hash[A[i]] == 0)
        {
            hash[m]++;
            m--;
            B.pb(A[i]);
            while (hash[m] == 1)
            {
                m--;
            }
            reverse(B.begin(), B.end());
            for (auto x : B)
            {
                cout << x << " ";
            }
            B.clear();
        }
        else
        {
            B.pb(A[i]);
            hash[A[i]]++;
        }
    }
    if (!B.empty())
    {
        for (auto x : B)
        {
            cout << x << " ";
        }
        B.clear();
    }

    cout << endl;
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