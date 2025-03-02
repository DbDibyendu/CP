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
const int N = 1e6 + 100, M = N;
//=======================

long long fact[N];

long long binpow(long long val, long long deg, long long mod)
{
    if (!deg)
        return 1 % mod;
    if (deg & 1)
        return binpow(val, deg - 1, mod) * val % mod;
    long long res = binpow(val, deg >> 1, mod);
    return (res * res) % mod;
}

void initfact()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i);
        fact[i] %= MOD;
    }
}

long long C(ll n, ll i)
{
    long long res = fact[n];
    long long div = fact[n - i] * fact[i];
    div %= MOD;
    div = binpow(div, MOD - 2, MOD);
    return (res * div) % MOD;
}

bool isGood(ll n, int a, int b)
{
    ll k = n % MOD;
    while (k)
    {
        if (k % 10 == a || k % 10 == b)
        {
            k /= 10;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void solve()
{

    ll a, b, n, i;
    ll temp = 0, flag = 0;
    cin >> a >> b >> n;
    initfact();
    fo(i, 0, n + 1)
    {
        temp = a * i + b * (n - i);
        if (isGood(temp, a, b))
        {
            flag += C(n, i) % MOD;
        }
    }
    cout << flag % MOD;
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
