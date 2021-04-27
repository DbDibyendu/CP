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

//! Solved on my own, good implementaion
void solve()
{

    ll i, j, n, m, k, a, b;
    ll temp = 0, flag = 1;
    cin >> n >> m >> a >> b;
    vl A(m);
    fo(i, 0, m)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    if (a < b)
    {
        ll max_time = b - 2;
        ll min_time = a;
        j = 0;
        for (i = min_time; i <= max_time && j < m; i++)
        {

            if (A[j] <= i)
            {
                temp++;
                j++;
            }
            else
                i = A[j] - 1; //! made the trick to avoid TLE error
        }
    }
    else
    {
        b = n - b;
        a = n - a;
        a++, b++;
        ll max_time = b - 2;
        ll min_time = a;
        j = 0;
        for (i = min_time; i <= max_time && j < m; i++)
        {

            if (A[j] <= i)
            {
                temp++;
                j++;
            }
            else
                i = A[j] - 1; //! made the trick to avoid TLE error
        }
    }
    cout << temp << endl;
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