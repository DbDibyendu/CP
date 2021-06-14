#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)         \
    for (auto &aa : A)     \
        cout << aa << ' '; \
    cout << endl;
#define displayP(A)    \
    for (auto &aa : A) \
    {                  \
        display(aa);   \
    }
#define read(A)        \
    for (auto &aa : A) \
    {                  \
        cin >> aa;     \
    }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

vl A;
ll l, r;
int f = -1;
void get(ll x)
{
    if (x > r)
    {

        A.push_back(x);

        return;
    }
    if (x >= l)
    {
        A.push_back(x);
    }

    get(x * 10 + 4);
    get(x * 10 + 7);
}
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> l >> r;
    get(0);
    sort(A.begin(), A.end());
    // display(A);
    ll t = l - 1;
    // deb(t);
    for (i = 0; i < A.size(); i++)
    {
        if (A[i] > r)
        {
            temp += (min(A[i] - t, r - t)) * A[i];
            break;
        }
        temp += (min(A[i] - t, r - t)) * A[i];
        t = A[i];
    }
    cout << temp << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================