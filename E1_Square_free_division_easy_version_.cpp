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
const int N = 1e7, M = N;
//=======================
//! Implementation, concept is easy
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> k;

    map<ll, ll> hash;
    // int A[N + 1];
    map<ll, ll> A;
    ll t, ans = 0, t2;
    fo(i, 0, n)
    {
        cin >> t;
        t2 = t;
        flag = 1;
        if (A[t2] == 0)
        {
            if (t % 2 == 0)
            {
                temp = 0;
                while (t % 2 == 0)
                {
                    t /= 2;
                    temp++;
                }
                if (temp % 2)
                    flag *= 2;
            }
            for (j = 3; j * j <= t; j += 2)
            {
                temp = 0;
                while (t % j == 0)
                {
                    t /= j;
                    temp++;
                }
                // deb2(j, temp);
                if (temp % 2)
                    flag *= j;
            }
            flag *= t;
            A[t2] = flag;
        }
        else
        {
            flag = A[t2];
        }
        // deb2(flag, t);

        if (hash[flag] == 0)
        {
            hash[flag]++;
            if (k == 0)
            {
                ans++;
                k++;
            }
        }
        else
        {
            // k = 0;
            hash.clear();
            k = 0;
            if (hash[flag] == 0)
            {
                hash[flag]++;
                if (k == 0)
                {
                    ans++;
                    k++;
                }
            }
        }
        // deb(ans);
    }
    cout << ans << endl;
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