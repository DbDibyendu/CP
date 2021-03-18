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
    string A;
    cin >> A;
    ll even = 0, odd = 0;
    n = A.length();
    ll E[2] = {0}, O[2] = {0};

    // ! I was able to find the initial concept, then had a look at tutorial
    for (i = 0; i < n; i++)
    {
        k = A[i] - 'a';
        odd++;
        if (i % 2 == 0)
        {
            odd += E[k];
            even += O[k];
            E[k]++;
        }
        else //! Current iterator is odd
        {
            odd += O[k];
            even += E[k];
            O[k]++;
        }
        }
    cout << even << " " << odd << endl;
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