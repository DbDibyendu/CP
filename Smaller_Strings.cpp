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
bool isP(string &A)
{
    int n = A.length();
    int flag = 0;
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        // deb2(A[i], A[n - i - 1]);
        if (A[i] - 'a' < A[n - i - 1] - 'a' && flag == 0)
        {
            return true;
        }
        else if (A[i] - 'a' > A[n - i - 1] - 'a')
        {
            flag = -1;
        }
    }
    return false;
}

int fast_pow(int a, int p)
{
    int res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = a * 1ll * a % MOD;
            p /= 2;
        }
        else
        {
            res = res * 1ll * a % MOD;
            p--;
        }
    }
    return res;
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> k;
    string A;
    cin >> A;
    ll mid = (n - 1) / 2;
    ll l = 0;
    for (i = mid; i >= 0; i--)
    {
        if (i == mid)
        {
            if (isP(A) == 0)
            {
                temp += (ll)(A[i] - 'a');
            }
            else
            {
                /* code */
                temp += (ll)A[i] - 'a' + 1;
            }
        }
        else
        {

            temp += (ll)(A[i] - 'a') * (ll)(fast_pow(k, l));
        }
        l++;
        // temp %= MOD;
        // deb(temp);
    }
    cout << temp % MOD << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    int k = 1;
    while (t--)
    {
        cout << "Case #" << k << ": ";
        solve();
        k++;
    }
    return 0;
}

//=======================