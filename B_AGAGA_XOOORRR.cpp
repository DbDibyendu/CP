//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯

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

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n + 1);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    ll prefix[n + 1] = {0};
    ll suffix[n + 1] = {0};
    prefix[0] = A[0];
    suffix[n - 1] = A[n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        suffix[i] = A[i] ^ suffix[i + 1];
    }
    fo(i, 1, n)
    {
        prefix[i] = A[i] ^ prefix[i - 1];
        // deb(prefix[i]);
    }
    if (suffix[0] == 0)
    {
        cout << "YES" << endl;
        return;
    }
    if (n > 2)
        for (i = 0; i < n - 2; i++)
        {
            ll x = prefix[i];
            k = 0;
            ll c = 0;
            ll t = 0;
            for (j = i + 1; j < n - 1; j++)
            {
                c ^= A[j];
                if (prefix[i] == c)
                {
                    // k++;
                    if (prefix[i] == suffix[j + 1])
                    {
                        // deb(prefix[i]);
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }

    cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================