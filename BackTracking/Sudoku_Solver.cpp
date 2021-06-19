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
//=======================;
int G[N][N];
int n;

bool isPossible(int i_start, int j_start, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (G[i][j_start] == num)
        {
            return false;
        }
    }
    int j;
    for (j = 0; j < n; j++)
    {
        if (G[i_start][j] == num)
        {
            return false;
        }
    }
    int r_start = (j_start / 3) * 3;
    int c_start = (i_start / 3) * 3;
    for (i = c_start; i < c_start + 3; i++)
    {
        for (j = r_start; j < r_start + 3; j++)
        {
            if (G[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudoku()
{
    int i, j, temp = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                temp++;
                break;
            }
        }
        if (temp)
        {
            break;
        }
    }
    if (temp == 0)
    {
        return true;
    }
    int k;
    for (k = 1; k <= 9; k++)
    {
        if (isPossible(i, j, k))
        {
            G[i][j] = k;
            if (sudoku() == 1)
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

    int i, j, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    clr(G);
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            cin >> G[i][j];
        }
    }
    temp = sudoku();
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
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