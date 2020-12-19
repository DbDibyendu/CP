#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef vector<int> vi;
typedef vector<vi> vvi;
//=======================

void solve()
{

    int i, j, n, m, k, a, b;
    ll temp = 0, flag = 1;
    cin >> n;
    vi A(n), B(n, 0);

    fo(i, 0, n)
    {
        cin >> A[i];
    }

    B[0] = A[0];
    fo(i, 1, n)
    {

        if (A[i] >= B[i - 1])
        {

            k = A[i] / B[i - 1];
            a = k * B[i - 1];
            B[i] = a;
        }

        // This was the catch
        else
        {
            B[i] = 1;
        }
    }

    fo(i, 0, n)
    {
        cout << B[i] << " ";
    }
    cout << endl;
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