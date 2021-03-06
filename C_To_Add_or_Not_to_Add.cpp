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
    cin >> n >> k;
    vl A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vl prefix(n + 1);
    ll l = 1, r = n, mid;
    fo(i, 0, n + 1)
    {
        if (i > 1)
            prefix[i] = A[i - 1] + prefix[i - 1];
        else if (i == 1)
        {
            prefix[i] = A[i - 1];
        }
        else
        {
            prefix[i] = 0;
        }
    }
    ll ans = 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        flag = 0;
        // deb(mid);
        for (i = mid; i <= n; i++)
        {
            if (mid * A[i - 1] - (prefix[i] - prefix[i - mid]) <= k)
            {
                flag = 1;
                temp = A[i - 1];
                // deb(temp);
                ans = mid;
                break;
            }
        }
        if (flag == 1)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << " " << temp << endl;
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