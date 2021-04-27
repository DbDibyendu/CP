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

    int i, j, n, k;
    ll temp = 0, flag = 1;
    cin >> n;
    string A;
    cin >> A;
    ll t = 0, m = 0;
    for (i = 0; i < n; i++)
    {
        // deb(A[i]);
        if (A[i] == 'T')
        {
            t++;
        }
        else
        {
            m++;
            j = i;
        }
    }
    // deb2(t, m);
    if (2 * m != t)
    {
        cout << "NO" << endl;
        return;
    }
    k = 0;
    for (i = 0; i <= j; i++)
    {
        if (A[i] == 'T')
        {
            k++;
        }
        else
        {
            if (k == 0)
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                k--;
            }
        }
    }
    reverse(A.begin(), A.end());
    t = 0, m = 0;
    for (i = 0; i < n; i++)
    {
        // deb(A[i]);
        if (A[i] == 'T')
        {
            t++;
        }
        else
        {
            m++;
            j = i;
        }
    }
    k = 0;
    for (i = 0; i <= j; i++)
    {
        if (A[i] == 'T')
        {
            k++;
        }
        else
        {
            if (k == 0)
            {
                cout << "NO" << endl;
                return;
            }
            else
            {
                k--;
            }
        }
    }
    cout << "YES" << endl;
    return;
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