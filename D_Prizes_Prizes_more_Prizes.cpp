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
    ll A[n], P[5];
    ll ans[5] = {0};
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    fo(i, 0, 5)
    {
        cin >> P[i];
    }
    fo(i, 0, n)
    {
        if (i)
        {
            A[i] += A[i - 1];
        }
        while (A[i] >= P[0])
        {
            for (j = 4; j >= 0; j--)
            {
                if (A[i] >= P[j])
                {
                    k = A[i] / P[j];
                    A[i] = A[i] - k * P[j];
                    ans[j]+=k;
                }
            }
        }
        // deb(A[i]);
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl
         << A[n - 1] << endl;
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