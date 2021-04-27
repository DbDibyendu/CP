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
const int N = 305, M = N;
//=======================

int a, b;
//! Good implementation

bool ok(vector<int> num, int n)
{
    num[n]--;
    int i;
    for (i = 500; i >= 1; i--)
    {
        if (num[i] <= 0)
        {
            if (i >= a)
            {
                num[i - a] += num[i];
            }
            if (i >= b)
            {
                num[i - b] += num[i];
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 0;
    cin >> n >> a >> b;
    vi num(1007, 0);

    for (i = 1; i <= n; i++)
    {
        cin >> k;
        num[i] = k;
    }

    int f2;
    for (i = 1; i <= 500; i++)
    {
        if (ok(num, i))
        {
            cout << i  << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    int k = 1;
    while (t--)
    {
        cout << "Case #" << k << ": ";
        solve();
        k++;
    }
    return 0;
}

//=======================