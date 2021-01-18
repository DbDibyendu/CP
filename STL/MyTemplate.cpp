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
long long lcm(int a, int b)
{
  return (a / gcd(a, b)) * b;
}

// calculate a^b in log(b) time
ll bin_pow(ll x, ll y)
{
  ll res = 1;
  while (y)
  {
    if (y % 2)
      res = (res * x) % MOD;
    x = (x * x) % MOD;
    y /= 2;
  }
  return res;
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
  }
  return 0;
}

//=======================
