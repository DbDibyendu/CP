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
    ll temp = 0, flag = 1;
    cin >> n >> m;
    string S, T;
    cin >> S >> T;
    ll mint[m], maxt[m];
    j = 0;
    // ! finding min edge of each t[i]
    for (i = 0; i < m; i++)
    {
        while (S[j] != T[i])
        {
            j++;
        }
        mint[i] = j;
        j++;
    }
    j = n - 1;
    for (i = m - 1; i >= 0; i--)
    {
        while (S[j] != T[i])
        {
            j--;
        }
        maxt[i] = j;
        // deb(j);
        j--;
    }
    for (i = 1; i < m; i++)
    {
        temp = max(maxt[i] - mint[i - 1], temp);
    }

    cout << temp << endl;
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