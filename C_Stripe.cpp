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
vl A(1000000);
ll sum;

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    ll sumA = 0;
    cin >> n;
    fo(i, 0, n)
    {
        cin >> A[i];
        sum += A[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        sumA += A[i];
        if (sumA == sum - sumA)
        {
            temp++;
        }
    }
    cout << temp << endl;
}

int main()
{
    int t = 1;
    // //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================