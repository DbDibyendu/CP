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

    int i, j, n, m, k;
    ll temp = 0, flag = 0;
    cin >> n;
    int A[30005];
    clr(A);
    int p[30005], s[30005];
    clr(p);
    fo(i, 1, n + 1)
    {
        cin >> A[i];
    }
    if (n <= 2)
    {
        cout << "YES" << endl;
        return;
    }
    for (i = 1; i <= n; i++)
    {
        s[i] = A[i] - A[i - 1];
    }
    m = s[1];
    for (i = 2; i <= n; i++)
    {
        if (s[i] < 0 && m + s[i] >= 0)
        {
            m += s[i];
            s[i] = 0;
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (s[i] < 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

void solve2()
{
    int i, j, n, m, k;
    ll temp = 0, flag = 0;
    cin >> n;
    int A[30005];
    clr(A);
    int p[30005], s[30005];
    clr(p);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    flag = A[0];

    for (i = n - 1; i > 0; i--)
    {

        if (A[i] < A[i - 1])
        {
            flag += A[i] - A[i - 1];
        }
        if (flag < 0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================