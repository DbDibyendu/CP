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

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    string A;
    cin >> A;
    vl pre(n, 0);
    map<pair<int, int>, int> hash;
    ll Ad = 0, Ak = 0;
    for (i = 0; i < n; i++)
    {

        if (A[i] == 'D')
        {
            Ad++;
        }
        else
        {
            Ak++;
        }
        if (Ad == 0)
        {
            hash[{Ad, 1}]++;
            pre[i] = hash[{Ad, 1}];
            continue;
        }
        if (Ak == 0)
        {
            hash[{1, Ak}]++;
            pre[i] = hash[{1, Ak}];
            continue;
        }
        ll t = gcd(Ad, Ak);
        ll Rd = Ad / t;
        ll Ar = Ak / t;

        hash[{Rd, Ar}]++;
        pre[i] = hash[{Rd, Ar}];
    }
    display(pre);
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