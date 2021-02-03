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

// Bit Masking
int n, l, r, x;
int A[20];

bool check(int k)
{
    int Min = INT_MAX;
    int Max = 0;
    int count = 0;
    int sum = 0;
    int i = 0;
    while (k > 0)
    {

        if (k & 1 == 1)
        {
            sum += A[count];
            Max = max(Max, A[count]);
            Min = min(Min, A[count]);
            i++;
        }
    
        count++;
        k >>= 1;
    }
    return i > 1 && sum >= l && sum <= r && Max - Min >= x;
}
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> l >> r >> x;
    fo(i, 0, n)
    {
        cin >> A[i];
    }

    for (i = 3; i < (1 << n); i++)
    {
        if (check(i))
        {
            temp++;
        }
    }
    cout << temp << endl;
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