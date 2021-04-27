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
    string A[n];
    char B[n][n];
    fo(i, 0, n)
    {
        cin >> A[i];
        // B[i] = A[i];
    }

    int ans[4][2];
    clr(ans);
    k = 0;
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            B[i][j] = A[i][j];
            if (A[i][j] == '*')
            {
                ans[k][0] = i;
                ans[k][1] = j;
                k++;
                // deb2(i, j);
            }
        }
    }

    if (ans[0][0] - ans[1][0] == 0)
    {
        if (ans[0][0] > 0)
        {
            int x = ans[0][0] - 1;
            A[x][ans[0][1]] = '*';
            A[x][ans[1][1]] = '*';
        }
        else
        {
            int x = ans[0][0] + 1;
            A[x][ans[0][1]] = '*';
            A[x][ans[1][1]] = '*';
        }
    }
    else if (ans[0][1] - ans[1][1] == 0)
    {
        // deb(ans[0][0]);
        if (ans[0][1] > 0)
        {
            int y = ans[0][1] - 1;
            A[ans[0][0]][y] = '*';
            A[ans[1][0]][y] = '*';
        }
        else
        {
            int y = ans[0][1] + 1;
            A[ans[0][0]][y] = '*';
            A[ans[1][0]][y] = '*';
        }
    }
    else
    {
        A[ans[0][0]][ans[1][1]] = '*';
        A[ans[1][0]][ans[0][1]] = '*';
    }
    fo(i, 0, n)
    {
        cout << A[i];
        cout << endl;
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