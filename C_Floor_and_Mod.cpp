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

// ! For every remainder we are finding the pairs.....As the remainder will be less than ROOT(x).
void solve()
{

    ll i, j, n, m, k, x, y;
    ll temp = 0, flag = 1;
    cin >> x >> y;
    for (i = 1; i <= x; i++)
    {
        if (i * (i + 1) > x)
        {
            j = i;
            break;
        }
    }
    // ! Now we will iterate till j and find the pairs
    for (i = 1; i <= j; i++)
    {
        flag = min((x - i) / i, y);
        temp += max(flag - (i + 1) + 1, 0ll);
    }
    cout << temp << endl;
}

// ? Brute force Approach
void bruteForce()
{

    ll i, j, n, m, k, x, y;
    ll temp = 0, flag = 1;
    cin >> x >> y;
    for (i = 1; i <= x; i++)
    {
        temp += min(x / (i + 1), i - 1);
    }
    cout << temp << endl;
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
