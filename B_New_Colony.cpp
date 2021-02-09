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
    ll temp = 0, flag = 0;
    ll maxCliff = 0, count = 0;
    cin >> n >> k;
    vl A(n), f(n, 0);

    fo(i, 0, n)
    {
        cin >> A[i];
    }

    int p = 0;
    int s = 0;
    while (p < n && k > 0)
    {
        s = 0;
        for (i = 1; i < n; i++)
        {

            if (A[i] > A[i - 1])
            {
                A[i - 1]++;
                p = i;
                k--;
                s = 1;
                break;
            }
        }
        if (s)
            continue;
        else
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << p << endl;
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