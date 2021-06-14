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

//! Very tough implementation, but did on my own
void solve()
{

    int i, j, n, m, k, x;
    int temp = 0, flag = 1;
    cin >> n >> m >> x;
    vi A(n);
    int p[n + 1];
    clr(p);
    priority_queue<pair<int, int>> P;
    fo(i, 0, n)
    {
        cin >> A[i];
        P.push({A[i], i});
    }
    int T[m + 1];
    vi ans(n);
    int a = MOD;
    flag = 0;
    int flag2 = 0;
    while (!P.empty())
    {
        if (flag == 0)
        {
            for (i = 1; i <= m; i++)
            {
                T[i] += P.top().first;
                ans[P.top().second] = i;
                P.pop();
                a = min(a, A[i]);
                temp = max(temp, A[i]);
                if (P.empty())
                {
                    break;
                }
                if (temp - a > x)
                {
                    i--;
                    flag2 = -1;
                    continue;
                }
                else
                {
                    flag2 = 0;
                }
            }
            flag = 1;
        }
        else
        {
            for (i = m; i >= 1; i--)
            {
                T[i] += P.top().first;
                ans[P.top().second] = i;
                P.pop();
                a = min(a, A[i]);
                temp = max(temp, A[i]);
                if (P.empty())
                {
                    break;
                }
                if (temp - a > x)
                {
                    i--;
                    flag2 = -1;
                    continue;
                }
                else
                {
                    flag2 = 0;
                }
            }
            flag = 1;
        }
    }
    if (flag2 == -1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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