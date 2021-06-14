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
#define disp(x)           \
    cout << #x << " = ";  \
    for (auto &i : x)     \
    {                     \
        cout << i << ' '; \
    }                     \
    cout << endl;
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
const int N = 2e5 + 5, M = N;
//=======================

//! Pure implementation
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    int l, r;
    cin >> n >> l >> r;
    vi L(n + 1, 0);
    vi R(n + 1, 0);
    fo(i, 0, l)
    {
        cin >> k;
        L[k]++;
    }
    fo(i, 0, r)
    {
        cin >> k;
        R[k]++;
    }
    int countl = 0, countr = 0;
    for (i = 1; i <= n; i++)
    {
        int mn = min(L[i], R[i]);
        L[i] -= mn;
        R[i] -= mn;

        countl += L[i];
        countr += R[i];
    }
    if (countl < countr)
    {
        swap(L, R);
        swap(countl, countr);
    }

    int change = (countl - countr) / 2;
    int sum = 0;
    for (i = 1; i <= n; i++)
    {
        int t = min(change, L[i] / 2);
        if (t < 0)
        {
            t = 0;
        }
        L[i] -= t;
        R[i] += t;
        change -= t;
        sum += t;

        int mn = min(L[i], R[i]);
        L[i] -= mn;
        R[i] -= mn;
    }
    disp(L);
    for (i = 1; i <= n; i++)
    {
        sum += L[i];
    }
    cout << sum << endl;
    
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