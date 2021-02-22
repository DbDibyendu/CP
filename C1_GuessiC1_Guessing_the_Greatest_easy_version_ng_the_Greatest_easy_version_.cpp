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
ll secmax, A, prev_secmax;
ll n;

void ans(int l, int r, int dir)
{
    if (l == r)
    {
        return;
    }
    else if (l + 1 == r && dir == -1)
    {
        A = l;
        return;
    }
    else if (l + 1 == r && dir == 1)
    {
        A = r;
        return;
    }
    if (dir == -1)
    {
        cout << "? " << l << " " << r << "\n";
        cin >> secmax;
        if (r == secmax)
        {
            ans(l, r - 1, -1);
            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        cout << "? " << l << " " << r << "\n";
        cin >> secmax;
        if (l == secmax)
        {
            ans(l + 1, r, 1);
            return;
        }
        else
        {
            return;
        }
    }
}
void solve()
{

    ll i, j, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    ll l = 1, r = n;
    cout << "? " << l << " " << r << "\n";
    cin >> prev_secmax;
    ans(l, prev_secmax, -1);
    ans(prev_secmax, r, 1);
    cout << "! " << A << "\n";
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