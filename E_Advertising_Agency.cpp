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
const int N = 1000010, M = N;
//=======================

int fast_pow(int a, int p)
{
    int res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = a * 1ll * a % MOD;
            p /= 2;
        }
        else
        {
            res = res * 1ll * a % MOD;
            p--;
        }
    }
    return res;
}

int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * 1ll * i % MOD;
    }
    return res;
}

int C(int n, int k)
{
    if (k > n)
    {
        return 0;
    }
    else
        return fact(n) * 1ll * fast_pow(fact(k), MOD - 2) % MOD * 1ll * fast_pow(fact(n - k), MOD - 2) % MOD;
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1, t = 0, den = 1;
    cin >> n >> k;
    unordered_map<ll, ll> hash;
    vl A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
        hash[A[i]]++;
    }
    sort(A.begin(), A.end(), greater<ll>());
    i = 0;
    j = k;
    while (i < n)
    {
        flag *= max(1, C(hash[A[i]], j));
        // deb2(j, hash[A[i]]);
        j -= hash[A[i]];
        i += hash[A[i]];
        if (i >= k)
        {
            break;
        }
    }

    cout << flag % MOD << endl;
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