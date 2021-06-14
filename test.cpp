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

bool isScramble(string A, string B)
{
    if (A == B)
    {
        return true;
    }
    if (A.length() != B.length())
    {
        return false;
    }
    string a = A, b = B;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // deb2(A, B);
    if (a != b)
    {
        return false;
    }
    int n = A.length();
    for (int i = 1; i < n; i++)
    {

        if (isScramble(A.substr(0, i), B.substr(0, i)) && isScramble(A.substr(i), B.substr(i)))
        {
            return true;
        }
        if (isScramble(A.substr(0, i), B.substr(n - i)) && isScramble(A.substr(i), B.substr(0, n - i)))
        {
            return true;
        }
    }
    return false;
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    // cin >> n;
    string A, B;
    cin >> A >> B;
    int ans = isScramble(A, B);
    n = A.length();
    deb(A.substr(n - 1));
    deb(ans);
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