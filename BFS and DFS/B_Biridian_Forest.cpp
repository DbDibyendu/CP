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
const int N = 1e3 + 10, M = N;
//=======================

int G[N][N];
int dis[N][N];
//! Best way to travel to adjacent squares in 2d array
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int xE, yE, xS, yS;
int r, c;
queue<pair<int, int>> dp;

//! Good question for understanding BFS
void bfs(int X, int Y)
{

    dp.push({X, Y});
    dis[X][Y] = 1;
    int i;
    while (!dp.empty())
    {
        int x = dp.front().first, y = dp.front().second;
        dp.pop();
        for (i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 1 && tx <= r && ty >= 1 && ty <= c)
            {
                if (G[tx][ty] == 0 && dis[tx][ty] == 0)
                {
                    dis[tx][ty] = dis[x][y] + 1;
                    dp.push({tx, ty});
                }
            }
        }
    }
}

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> r >> c;
    // ! Important
    string A[r + 1];
    clr(dis);
    clr(G);
    for (i = 1; i <= r; i++)
    {
        cin >> A[i];
        for (j = 0; j < c; j++)
        {
            if (A[i][j] == 'E')
            {
                xE = i;
                yE = j + 1;
            }
            else if (A[i][j] == 'S')
            {
                xS = i;
                yS = j + 1;
            }
            else if (A[i][j] == 'T')
            {
                G[i][j + 1] = 1;
            }
        }
    }
    bfs(xE, yE);
    temp = dis[xS][yS];
    int ans = 0;

    for (i = 1; i <= r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (A[i][j] - '0' >= 1 && A[i][j] - '0' <= 9)
            {
                if (dis[i][j + 1] > 0 && dis[i][j + 1] <= temp)
                {
                    ans += A[i][j] - '0';
                }
            }
            // deb2(ans, dis[i][j + 1]);
        }
    }
    cout << ans << endl;
}

int main()
{
    int t = 1;

    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================