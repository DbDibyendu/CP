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
typedef vector<vi> vvi;
typedef vector<ll> vl;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

void solve()
{

    int i, j, m, k;
    ll temp = 0, flag = 0;
    string A;
    cin >> A;
    ll n = A.length();
    string B;
    if (n < 3)
    {
        cout << A << endl;
        return;
    }

    B.pb(A[0]);
    B.pb(A[1]);
    for (i = 2; i < n; i++)
    {

        if (A[i] == B[B.length() - 1] && B[B.length() - 1] == B[B.length() - 2])
        {
        }
        else if (i - 3 >= 0 && B[B.length() - 3] == B[B.length() - 2] && B[B.length() - 1] == A[i])
        {
        }
        else
        {
            B.push_back(A[i]);
        }
    }
    cout << B << endl;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================