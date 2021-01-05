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

// Basic property
ll gcd(ll n, ll m)
{

    if (n == 0)
        return m;
    if (m == 0)
        return n;
    if (n == m)
        return n;

    if (n > m)
        return gcd(n - m, m);
    return gcd(n, m - n);
}


void solve()
{

    ll i, j, n, m, k, G;
    ll temp = 0, flag =LLONG_MAX;
    cin >> n >> m;
    vector<ll> A(n), B(m);
    fo(i, 0, n)
    {
        cin >> A[i];
        flag = min(flag, A[i]);
    }
    fo(i, 0, m) cin >> B[i];

    if (n == 1)
    {
        fo(i, 0, m)
        {
            k = A[0] + B[i];

            cout << k << " ";
        }
        cout << endl;
        return;
    }

    else
    {
        G = __gcd(A[n - 1] - flag, A[n - 1] - flag);

        fo(i, 0, n)
        {
            if (A[i] == flag)
            {
            }

            else
                G = __gcd(A[i] - flag, G);
        }

        fo(i, 0, m)
        {
            k = __gcd(G, B[i] + flag);

            cout << k << " ";
        }
        cout << endl;
    }
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