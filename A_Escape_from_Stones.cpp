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

void solve2()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A;
    cin >> A;
    n = A.length();
    vl first, second;

    for (int i = 0; i < n; i++)
    {
        if (A[i] == 'r')
        {
            cout << i + 1 << '\n';
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] == 'l')
        {
            cout << i + 1 << '\n';
        }
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================