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
    int i;
    int n = A.size();
    for (i = 0; i < n / 2; i++)
    {
        if (A[i] != A[n - i - 1])
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
    string A;
    cin >> A;
    for (i = 0; i < n; i++)
    {
        if (A[i] == '0')
        {
            temp++;
        }
    }
    int bob = 0, alic = 0;
    if (isP(A))
    {
        if (temp & 1)
        {
            alic++;
            temp--;
            //! Bob's chance
            if (temp)
            {

                alic += 0;
                bob += 4;
            }
        }
        else
        {
            if (temp)
            {
                alic += 4;
                bob += 0;
            }
        }
    }

    // deb2(alic, bob);
    if (alic < bob)
    {
        cout << "ALICE" << endl;
    }
    else if (bob < alic)
    {
        cout << "BOB" << endl;
    }
    else
    {
        cout << "DRAW" << endl;
    }
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