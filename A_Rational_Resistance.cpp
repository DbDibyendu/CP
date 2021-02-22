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

void swap(ll *a, ll *b)
{
    ll t;
    t = *a;
    *a = *b;
    *b = t;
}
// ! Solved on my own
// ! Nice number theory logic behind it
void solve()
{

    ll a, b, i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> a >> b;

    if (a % b == 0)
    {
        cout << a / b << endl;
        return;
    }
    temp += a / b;
    // deb(temp);
    a -= temp * b;
    while (b != 1)
    {
        swap(&a, &b);
        // deb2(a, b);
        temp += a / b;
        k = a / b;
        a = a - k * b;
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