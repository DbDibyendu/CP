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
    cin >> n >> k;
    vi A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    ll previ = MOD, prevj;
    j = 0;
    if (n < 3)
    {
        cout << 0 << endl;
        return;
    }
    flag = 0;
    for (i = 0; i < n; i++)
    {
        auto ptr = upper_bound(A.begin(), A.end(), A[i] + k); // ! I applied this concept myself
        ptr;
        ll t = ptr - A.begin() - i - 1;
        temp += t * (t - 1) / 2; // ! For different i, we are selecting all 2 possible integers
        // deb(temp);
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