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

bool isPrime(int n)
{
    int i;
    if (n % 2 == 0 && n != 2)
    {
        return false;
    }
    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n);
    read(A);
    vl B;
    for (i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            B.push_back(A[i]);
        }
    }
    vl C;
    for (i = 0; i < n; i++)
    {
        if (A[i] % 2 && !isPrime(A[i]))
        {
            C.push_back(A[i]);
        }
    }
    sort(C.rbegin(), C.rend());
    for (j = 0; j < C.size(); j++)
    {
        B.push_back(C[j]);
    }
    for (i = 0; i < n; i++)
    {
        if (A[i] % 2 && isPrime(A[i]))
        {
            B.push_back(A[i]);
        }
    }
    // display(B);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (gcd(B[i], 2 * B[j]) > 1)
            {
                temp++;
            }
        }
    }
    cout << temp << endl;
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