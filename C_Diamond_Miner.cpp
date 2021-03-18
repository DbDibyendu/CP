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
    cin >> n;
    vl A, B;
    ll x, y;
    fo(i, 0, 2 * n)
    {
        cin >> x >> y;

        if (x == 0)
        {
            B.pb(abs(y));
        }
        else
        {
            A.pb(abs(x));
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    double ans = 0;
    n = A.size();
    m = B.size();
    i = 0, j = 0;
    while (j < A.size())
    {
        ans += sqrt(pow(A[j], 2) + pow(B[i], 2));
        i++;
        j++;
    }
    printf("%0.15f\n", ans);
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