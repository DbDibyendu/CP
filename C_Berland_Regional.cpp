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
    ll temp = 0, flag = 1;
    cin >> n;
    vl A(n + 1), S(n + 1);
    vector<vector<ll>> teams(n + 1);
    int M = 0;
    for (i = 0; i < n; i++)
    {
        cin >> k;
        A[i] = k;
        M = max(k, M);
    }
    for (i = 0; i < n; i++)
    {
        cin >> k;
        teams[A[i]].push_back(k);
        temp += k;
    }
    for (int i = 1; i <= M; i++)
    {
        sort(teams[i].rbegin(), teams[i].rend());
        for (j = 1; j < teams[i].size(); j++)
        {
            teams[i][j] += teams[i][j - 1];
        }
    }
    vector<ll> ans(n + 1, 0);

    for (int i = 1; i <= M; i++)
    {
        int len = teams[i].size();

        for (int k = 1; k <= len; k++)
        {
            int rem = len % k;
            ans[k] += teams[i][len - rem - 1];
        }
    }
    for (int i = 1; i <= n; i++)
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