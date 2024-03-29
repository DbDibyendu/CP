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
const int N = 1e5, M = N;
//=======================

int A[N];

//! 2 pointer logic
int partition(int l, int r)
{
    int el = A[r];
    int i = l - 1, j;
    for (j = l; j < r; j++)
    {
        if (A[j] < el)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}
void quicksort(int l, int r)
{
    if (l < r)
    {
        int p = partition(l, r);
        quicksort(l, p - 1);
        quicksort(p + 1, r);
    }
}
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    quicksort(0, n - 1);
    for (i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================