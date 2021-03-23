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

//! Simple logic, was able to catch the concept in my sleep
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n);
    vl U, R;
    ll dpU[n], dpR[n];
    clr(dpU), clr(dpR);
    ll tU = 1e18, tR = 1e18;
    fo(i, 0, n)
    {
        cin >> A[i];
    }

    dpU[0] = A[1];
    temp = A[1] * n;
    dpR[0] = A[0];
    temp += A[0] * n;
    k = 1, j = 1;

    ll minU = A[1], minR = A[0];
    fo(i, 2, n)
    {
        if (i & 1)
        {       

            dpU[k] = A[i] + dpU[k - 1];
            minU = min(minU, A[i]);
            temp = min(temp, dpU[k] + dpR[j - 1] - minU - minR + (n - k) * minU + (n - j + 1) * minR);
            k++;
        }
        else
        {

            dpR[j] = A[i] + dpR[j - 1];
            minR = min(minR, A[i]);
            temp = min(temp, dpU[k - 1] + dpR[j] - minU - minR + (n - k + 1) * minU + (n - j) * minR);
            j++;
        }
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