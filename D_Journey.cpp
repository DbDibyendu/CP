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

ll visited[300010] = {};
string A1;
char A2[300010];
ll temp, n;

void dfs(int u, int t)
{
    visited[u] = 1;
    temp++;
    if (t == 0)
    {
        if (u == 0)
        {
            if (A1[u] == 'R' && visited[u + 1] == 0)
            {
                dfs(u + 1, 1);
            }
        }
        else if (u == n)
        {
            if (A1[u - 1] == 'L' && visited[u - 1] == 0)
            {
                dfs(u - 1, 1);
            }
        }
        else
        {
            if (A1[u - 1] == 'L' && visited[u - 1] == 0)
            {
                dfs(u - 1, 1);
            }
            if (A1[u] == 'R' && visited[u + 1] == 0)
            {
                dfs(u + 1, 1);
            }
        }
    }
    else
    {
        if (u == 0)
        {
            if (A2[u] == 'R' && visited[u + 1] == 0)
            {
                dfs(u + 1, 0);
            }
        }
        else if (u == n)
        {
            if (A2[u - 1] == 'L' && visited[u - 1] == 0)
            {
                dfs(u - 1, 0);
            }
        }
        else
        {
            if (A2[u - 1] == 'L' && visited[u - 1] == 0)
            {
                dfs(u - 1, 0);
            }
            if (A2[u] == 'R' && visited[u + 1] == 0)
            {
                dfs(u + 1, 0);
            }
        }
    }
}
// Approach one
void solve()
{

    int i, j, m, k;
    ll flag = 1;
    cin >> n;
    cin >> A1;
    fo(i, 0, n)
    {
        if (A1[i] == 'L')
        {
            A2[i] = 'R';
        }
        else
        {
            A2[i] = 'L';
        }
    }
    fo(i, 0, n + 1)
    {
        dfs(i, 0);
        cout << temp << " ";
        temp = 0;
        clr(visited);
    }
    cout << endl;
}

// DP approach
void solve2()
{
    int i, j, m, k;
    ll flag = 1;
    string A;
    cin >> n;
    cin >> A;
    ll dp[n + 1][4] = {0};

    for (i = n - 1; i >= 0; i--)
    {
        if (A[i] == 'R')
        {
            dp[i][0] = dp[i + 1][1] + 1;
        }
        else
        {
            dp[i][1] = dp[i + 1][0] + 1;
        }
    }

    for (i = 1; i <= n; i++)
    {
        if (A[i - 1] == 'L')
        {
            dp[i][2] = dp[i - 1][3] + 1;
        }
        else
        {
            dp[i][3] = dp[i - 1][2] + 1;
        }
    }
    
    for (i = 0; i <= n; i++)
    {
        cout << dp[i][0] + dp[i][2] + 1 << " ";
    }
    cout << endl;
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