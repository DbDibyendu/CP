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
const int N = 1e3, M = N;
//=======================

int G[N][N];
int n;
bool isPossible(int i, int j)
{
    int x, y;
    for (x = 0; x < i; x++)
    {
        if (G[x][j] == 1)
        {
            return false;
        }
    }
    x = i, y = j;
    while (x >= 0 && y >= 0)
    {
        if (G[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (G[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool n_queen(int i)
{
    if (i == n)
    {
        return true;
    }
    int j;
    for (j = 0; j < n; j++)
    {
        if (isPossible(i, j))
        {
            G[i][j] = 1;
            if (n_queen(i + 1) == 1)
            {
                return true;
            }
            G[i][j] = 0;
        }
    }
    return false;
}
void solve()
{

    int i, j, k;
    ll temp = 0, flag = 1;
    cin >> n;
    clr(G);
    temp = n_queen(0);
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            if (G[i][j] == 1)
            {
                cout << "Q";
            }
            else
            {
                cout << "_";
            }
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