#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef vector<int> vi;
typedef vector<vi> vvi;
//=======================

bool calc(ll n)
{
    ll temp = n;

    while (temp)
    {
        if (temp % 10 != 0 && n % (temp % 10) != 0)
        {
            return false;
        }
        temp /= 10;
    }
    return true;    
}

void solve()
{

    ll i, j, m, k, n;
    ll temp = 0, flag = 1;
    cin >> n;
    for (i = n;; i++)
    {

        if (calc(i) == true)
        {
            cout << i << endl;
            return;
        }
    }
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