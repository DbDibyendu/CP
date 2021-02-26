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

// ! KMP algo

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A;
    cin >> A;
    n = A.length();
    vl prefix(n, 0);
    i = 1, j = 0;
    while (i < n)
    {

        if (A[i] == A[j])
        {
            j++;
            prefix[i] = j;
            i++;
        }
        else
        {

            if (j)
            {
                j = prefix[j - 1];
            }
            else
            {
                prefix[i] = j;
                i++;
            }
        }
    }

    vl ans;
    m = n;
    while (m)
    {
        ans.pb(m);
        m = prefix[m - 1];
    }
    reverse(ans.begin(), ans.end());
    vl cnt(n+1, 1);

    for (i = n; i > 0; i--)
    {
        cnt[prefix[i - 1]] += cnt[i];
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " " << cnt[x] << endl;
    }
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