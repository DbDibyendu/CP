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

ll isPrimeNumber(ll n)
{
    bool isPrime = true;

    for (ll i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

void solve()
{

    ll i, j, n, m, k, d;
    ll temp = 0, flag = 1;
    cin >> d;
    ll n1 = 1, n2 = 1;
    for (i = d + 1;; i++)
    {
        if (isPrimeNumber(i))
        {

            temp++;
            n1 *= i;
            i += d - 1;
        }
        if (temp == 2)
        {
            break;
        }
    }
    cout << n1 << endl;
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