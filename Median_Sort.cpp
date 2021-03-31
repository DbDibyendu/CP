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

int n, q;
void solve()
{

    int i, j, m, k, k2, k3;
    ll temp = 0, flag = 1;
    vi A(n);
    bool found = false;
    k = 1;
    k2 = 2;
    k3 = 3;
    vi ans;
    while (q--)
    {
        int a;

        cout << k << " " << k2 << " " << k3 << "\n";
        cin >> a;
        if (a == k)
        {
            if (ans.size() == 0)
            {
                ans.pb(k2);
                ans.pb(k);
                ans.pb(k3);
                k++, k2++, k3++;
            }
            else
            {
            }
        }
        else if (a == k2)
        {
            if (ans.size() == 0)
            {

                ans.pb(k);
                ans.pb(k2);
                ans.pb(k3);
                k++, k2++, k3++;
            }
            else
            {
            }
        }
        else if (a == k3)
        {
            if (ans.size() == 0)
            {

                ans.pb(k);
                ans.pb(k3);
                ans.pb(k2);
                k++, k2++, k3++;
            }
            else
            {
            }
        }
        if (ans.size() == n)
        {
            break;
        }
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    int t;
    cin >> t;
    A.clear();
    if (t == 1)
    {
        return;
    }
}

int main()
{
    int t = 1;
    cin >> t >> n >> q;
    int k = 1;
    while (t--)
    {
        solve();
        k++;
    }
    return 0;
}

//=======================