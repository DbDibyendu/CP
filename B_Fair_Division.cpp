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

    ll i, j, n, m, k;
    ll temp = 0, flag = 1, prev = 0;
    cin >> n;
    vi A(n);
    ll B[2]={0};
    fo(i, 0, n)
    {
        cin >> A[i];
        temp += A[i];
        {
            B[A[i]]++;
        }
    }
    if (temp % 2 == 0)
    {
        if (n % 2 == 0)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {
            if (B[1] % 2 == 0 && B[1] != 0)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
    return;
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