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

    int i, j, n, m, k, empty_glass = 0;
    ll temp = 0, flag = 1;
    cin >> n;
    vi A(n), B(n);
    vector<double> C(n), dp(n,0);
    
    fo(i, 0, n)
    {
        cin >> A[i] >> B[i];
    }
    for (i = n; i > 0; i--)
    {
        empty_glass = n - i;
        while(empty_glass)
    }
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