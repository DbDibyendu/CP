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

    int i, j, n, m, k, Max, Min;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    fo(i, 1, n)
    {
        if (max(A[i], A[i - 1]) <= 2 * min(A[i], A[i - 1]))
        {
            continue;
        }

        else
        {
            if (A[i] > A[i - 1])
            {
                Max = A[i];
                Min = A[i - 1];
            }
            else
            {
                Max = A[i - 1];
                Min = A[i];
            }
            for (j = 1; j < MOD; j++)
            {
                if (pow(2, j) - 1 >= (Max + Min - 1) / Min - 1)
                {
                    temp += j - 1;
                    break;
                }
            }
        }
    }
    cout << temp << endl;
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