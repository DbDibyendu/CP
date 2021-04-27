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
//! My final solution 
void solve()
{

    ll l, r, s, i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> l >> r >> s;
    k = r - l + 1;
    vl ans, t;
    ll Up = k * (2 * n - k + 1) / 2;
    ll Low = k * (k + 1) / 2;
    if (s <= Up && s >= Low)
    {
        for (i = n; i >= 1; i--)
        {
            Up = (k - 1) * (2 * i - k + 2) / 2;
            Low = k * (k - 1) / 2;
            if (s - i <= Up && s - i >= Low) //! whether after subtracting they are satisfying the conditions or not
            {
                s -= i;
                ans.pb(i);
                k--;
            }
            else
            {
                t.pb(i);
            }
        }
        for (i = 1; i <= n; i++)
        {
            if (i >= l && i <= r)
            {
                cout << ans.back() << " ";
                ans.pop_back();
            }
            else
            {
                cout << t.back() << " ";
                t.pop_back();
            }
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
        return;
    }
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