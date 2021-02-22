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

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
// Function to return LCM of two numbers
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n == 2)
    {
        cout << 2 << endl;
    }
    else
    {
        if (n & 1)
        {
            cout << lcm(lcm(n, n - 1), n - 2);
        }
        else
        {
            ll t;
            flag = lcm(lcm(n - 1, n - 2), n - 3); // ! This line is important too
            t = lcm(n, n - 1);
            n--;
            m=n;
            while (n > m-5)
            {
                n -= 2;
                temp = max(temp, lcm(t, n));
                // deb(temp);
            }
            cout << max(flag, temp) << endl;
        }
    }
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