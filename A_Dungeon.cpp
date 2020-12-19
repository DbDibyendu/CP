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

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 9 == 0 && a + b + c >= 9)
    {
        temp = (a + b + c) / 9;
        if (a >= temp && b >= temp && c >= temp)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;
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