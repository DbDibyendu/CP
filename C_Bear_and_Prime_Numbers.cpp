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

map<ll, ll> f;

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
    }
    if (flag)
        f[2]++;

    flag = 0;
    for (int i = 3; i * i <= n; i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            n = n / i;
            flag = 1;
        }
        if (flag)
        {
            f[i]++;
        }
    }

    if (n > 2)
    {
        f[n]++;
    }
}

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n);
    vpll B;
    fo(i, 0, n)
    {
        cin >> A[i];
        primeFactors(A[i]);
    }
    cin >> m;
    int x, y;

    fo(i, 0, n)
    {
        cin >> x >> y;
        B.pb(make_pair(x, y));
    }
    fo(i, 0, m)
    {
        for (j = B[i].first; j <= B[i].second; j++)
        {
            if (isPrime(j))
            {
                temp += f[j];
            }
        }
        cout << temp << endl;
        temp = 0;
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