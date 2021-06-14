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

//! Easy imlementation, just need to observe the trick, of distribution of 0,1,2
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    ll cnt[n + 1];
    clr(cnt);
    vector<pair<ll, ll>> vec;
    fo(i, 0, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        vec.push_back({x, y});
        cnt[x]++;
        cnt[y]++;
    }
    for (i = 1; i <= n; i++)
    {
        if (cnt[i] >= 3)
        {
            k = i;
            temp = 1;
            break;
        }
    }
    if (temp)
    {
        //! Distribute tree into 3 junction
        ll t = 2;
        ll x = 3;
        for (i = 0; i < n - 1; i++)
        {
            if (t >= 0)
            {
                if (vec[i].first == k || vec[i].second == k)
                {
                    cout << t << endl;
                    t--;
                }
                else
                {
                    cout << x << endl;
                    x++;
                }
            }
            else
            {
                cout << x << endl;
                x++;
            }
        }
    }
    else
    {
        //! Bamboo tree
        for (i = 0; i < n - 1; i++)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================