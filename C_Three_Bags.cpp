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

int Min3(int a, int b, int c)
{
    if (a < b && a < c)
    {
        return a;
    }
    else if (b < a && b < c)
    {
        return b;
    }
    else
        return c;
}
void solve()
{

    ll i, j, n1, n2, n3, m, k, t1=0, t2=0, t3=0;
    ll temp = 0, flag = 0, ans = 0, Min = 0;
    cin >> n1 >> n2 >> n3;

    vl A, B, C;
    fo(i, 0, n1)
    {
        cin >> k;
        A.pb(k);
        temp += k;
        t1 += k;
    }
    fo(i, 0, n2)
    {
        cin >> k;
        B.pb(k);
        temp += k;
        t2 += k;
    }
    fo(i, 0, n3)
    {
        cin >> k;
        C.pb(k);
        temp += k;
        t3 += k;
    }
    
    m = min(min(t1, t2), min(t2, t3));
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    flag = min(min(A[0] + B[0], B[0] + C[0]), min(A[0] + B[0], C[0] + A[0]));

    Min = min(flag, m);

    ans = temp - 2 * Min;

    cout << ans << endl;
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