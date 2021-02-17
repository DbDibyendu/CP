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
int n;
vl A(105), B(105);


// ! Many Silly mistakes occured, Be carefull from next time
void subtree(int l, int r, int t)
{
    int i, Max1 = 0, j;
    for (i = l; i <= r; i++)
    {
        if (Max1 < A[i])
        {
            Max1 = A[i];
            j = i;
            // deb2(t, j);
        }
    }
    B[j] = t;

    if (l < j)
        subtree(l, j - 1, t+1);
    if (j < r)
        subtree(j + 1, r, t+1);
}

void solve()
{

    int i, j, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    ll Max = 0;
    fo(i, 0, n)
    {
        cin >> A[i];
    }

    subtree(0, n - 1, 0);
    fo(i, 0, n)
    {
        cout << B[i] << " ";
    }
    cout << endl;
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