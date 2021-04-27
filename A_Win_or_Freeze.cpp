//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯

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

bool isPrime(ll n)
{
    ll i;
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

bool isPossible(ll n)
{
    ll i;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrime(i) == 0)
            {
                return false;
            }
            if ((isPrime(n / i) == 0))
            {
                return false;
            }
        }
    }
    return true;
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    if (isPrime(n))
    {
        cout << 1 << endl
             << 0 << endl;
        return;
    }
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrime(i) == 0)
            {
                if (isPossible(i))
                {
                    cout << 1 << endl
                         << i << endl;
                    return;
                }
            }
            if (isPrime(n / i) == 0)
            {
                if (isPossible(n / i))
                {
                    cout << 1 << endl
                         << n / i << endl;
                    return;
                }
            }
        }
    }
    cout << 2 << endl;
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