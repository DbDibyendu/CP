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
typedef pair<int, int> pi;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================
char A[505][505];
int visited[505][505] = {};
int store[300000][2];
int temp = 0, n, m, k;
int t = 0;
void dfs(int i, int j)
{
    if (t >= temp)
        return;

    // visited[i][j] = 1;
    store[t][0] = i;
    store[t][1] = j;
    t++;
    if (j + 1 <= m && visited[i][j + 1] == 0)
    {
        visited[i][j + 1] = 1;
        if (A[i][j + 1] == '.')
            dfs(i, j + 1);
    }

    if (j - 1 >= 1 && visited[i][j - 1] == 0)
    {
        visited[i][j - 1] = 1;
        if (A[i][j - 1] == '.')
            dfs(i, j - 1);
    }

    if (i + 1 <= n && visited[i + 1][j] == 0)
    {
        visited[i + 1][j] = 1;
        if (A[i][j + 1] == '.')
            dfs(i + 1, j);
    }
    if (i - 1 >= 1 && visited[i - 1][j] == 0)
    {
        visited[i - 1][j] = 1;
        if (A[i - 1][j] == '.')
            dfs(i - 1, j);
    }
}

void solve()
{
    int i, j, x = 0, y = 0;
    int flag = 1;
    cin >> n >> m >> k;

    fo(i, 1, n + 1)
    {
        fo(j, 1, m + 1)
        {
            cin >> A[i][j];
            if (A[i][j] == '.')
            {
                temp++;
                x = i;
                y = j;
            }
        }
    }
    visited[x][y] = 1;
    dfs(x, y);

    for (i = t-1 ; i > t - k -1; i--)
    {
        A[store[i][0]][store[i][1]] = 'X';
        // deb2(store[i][0], store[i][1]);
    }

    fo(i, 1, n + 1)
    {
        fo(j, 1, m + 1)
        {
            cout << A[i][j];
        }
        cout << endl;
    }
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================