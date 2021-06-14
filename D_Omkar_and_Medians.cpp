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

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n);
    read(A);
    set<ll> check;
    set<ll> check_lower;
    check.insert(A[0]);
    check_lower.insert(-A[0]);

    for (i = 1; i < n; i++)
    {

        if (A[i] >= A[i - 1])
        {
            auto it = check.upper_bound(A[i - 1]);
            if (it == check.end() || *it >= A[i])
            {
                check.insert(A[i]);
                check_lower.insert(-A[i]);
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            auto it = check_lower.upper_bound(-A[i - 1]);
            if (it == check_lower.end() || *it >= -A[i])
            {
                check.insert(A[i]);
                check_lower.insert(-A[i]);
            }
            else
            {
                cout << "NO" << endl;
                return;
            }   
        }
    }
    cout << "YES" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================