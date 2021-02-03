#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
//=======================

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
// Function to return LCM of two numbers
ll lcm(int a, int b)
{
  return (a / gcd(a, b)) * b;
}
// calculate a^b in log(b) time
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

int factorial(int n)
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

bool isPrime(int n)
{
    int i;
    if (n % 2 == 0 && n != 2)
    {
        return false;
    }
    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void primeFactors(int n)
{
  int flag = 0;
  while (n % 2 == 0)
  {
    n = n / 2;
    flag = 1;
    cout << 2 << " ";
  }

  for (int i = 3; i * i <= n; i = i + 2)
  {
    // While i divides n, print i and divide n
    while (n % i == 0)
    {
      cout << i << " ";
      n = n / i;
    }
  }

  if (n > 2)
  {
    cout << n << " ";
  }
}

void solve()
{

  int i, j, n, m, k;
  ll temp = 0, flag = 1;
  cin >> n;
}

int main()
{
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
    cout << gcd(45, 6);
  }
  return 0;
}

//=======================
