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

// Binary search approach 
void solve()
{
    ll i, j, n, m, r, b = 0, s = 0, c = 0;
    ll temp = 0, buns = 0;
    ll N[3], P[3];
    string A;
    cin >> A;
    fo(i, 0, 3)
    {
        cin >> N[i];
    }
    fo(i, 0, 3)
    {
        cin >> P[i];
    }
    cin >> r;
    n = A.length();
    fo(i, 0, n)
    {
        if (A[i] == 'B')
        {
            b++;
        }
        else if (A[i] == 'S')
        {
            s++;
        }
        else if (A[i] == 'C')
        {
            c++;
        }
    }

    ll left = 0, right = 100000000000000, mid;
    ll price;
    while (left <= right)
    {
        mid = (left + right) / 2;

        price = max(0ll, (mid * b - N[0]) * P[0]) + max(0ll, (mid * s - N[1]) * P[1]) + max(0ll, (mid * c - N[2]) * P[2]);
        if (price <= r)
        {
            // deb(price);
            // deb2(mid, price);
            temp = max(temp, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        // deb2(left, mid);
        //    deb(right);
    }
    cout << temp << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================