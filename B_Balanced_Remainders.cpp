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

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1, c0 = 0, c1 = 0, c2 = 0;
    cin >> n;
    vl A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
        if (A[i] % 3 == 0)
        {
            c0++;
        }
        else if (A[i] % 3 == 1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    m = n / 3;

    if (c2 >= c0 && c2 >= m)
    {
        temp += (c2 - m);
        c0 += c2 - m;
        if (c0 >= c1 && c0 >= m)
        {
            temp += c0 - m;
            c1 += c0 - m;
        }
        else
        {
            temp += 2 * (c1 - m);
            c0 += c1 - m;
        }
    }
    else if (c1 >= c2 && c1 >= m)
    {
        temp += (c1 - m);
        c2 += c1 - m;
        if (c2 >= c0 && c2 >= m)
        {
            temp += c2 - m;
            c0 += c2 - m;
        }
        else
        {
            temp += 2 * (c0 - m);
            c2 += c0 - m;
        }
    }
    else if (c0 >= c1 && c0 >= m)
    {
        temp += (c0 - m);
        c1 += c0 - m;
        if (c1 >= c2 && c1 >= m)
        {
            temp += c1 - m;
            c2 += c1 - m;
        }
        else
        {
            temp += 2 * (c2 - m);
            c1 += c2 - m;
        }
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

//=======================