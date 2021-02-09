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

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vi A(n + 2);
    A[0] = A[n + 1] = N;
    if (n < 3)
    {
        if (n == 1)
        {
            cout << "! " << 1 << endl;
            return;
        }
        if (n == 2)
        {
            cout << "? " << 1;
            cout << endl
                 << flush;
            cin >> A[1];

            cout << "? " << 2;
            cout << endl
                 << flush;
            cin >> A[2];

            if (A[1] > A[2])
            {
                cout << "! " << 2 << endl;
                return;
            }
            else
            {
                cout << "! " << 1 << endl;
                return;
            }
        }
    }
    if (n >= 3)
    {
        int l = 2, r = n;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (m > 0 && m <= n)
            {
                cout << "? " << m;
                cout << endl
                     << flush;
                cin >> A[m];
            }
            if (m - 1 > 0 && m - 1 <= n)
            {
                cout << "? " << m - 1;
                cout << endl
                     << flush;
                cin >> A[m - 1];
            }
            if (m - 2 > 0 && m - 2 <= n)
            {
                cout << "? " << m - 2;
                cout << endl
                     << flush;
                cin >> A[m - 2];
            }
            // Check if x is present at mid
            if (A[m] > A[m - 1] && A[m - 1] < A[m - 2])
            {
                cout << "! " << m - 1 << endl;
                return;
            }

            // If x greater, ignore left half
            if (A[m] < A[m - 1])
                l = m + 1;

            // If x is smaller, ignore right half
            else
                r = m - 1;
        }
    }
}

int ask(int i)
{
    int x;

    cout << "? " << i << "\n";

    cin >> x;

    return x;
}

void solve2()
{
    int n;
    cin >> n;

    int l = 0, r = n;

    while (r - l > 1)
    {
        int m = l + (r - l) / 2;

        if (ask(m + 1) < ask(m))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }

    cout << "! " << r << "\n";
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================