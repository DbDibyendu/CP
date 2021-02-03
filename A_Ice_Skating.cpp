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
const int N = 1010;

int n;
bool visited[1000] = {false};
int arr[1000][2];

void dfs(int u)
{
    visited[u] = true;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
            if (arr[i][0] == arr[u][0] || arr[i][1] == arr[u][1])
            {
                dfs(i);
            }
    }
}

void solve()
{
    int i, j, k;
    ll temp = 0, flag = 1;
    cin >> n;
    fo(i, 0, n)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    fo(i, 0, n)
    {
        if (visited[i] == false)
        {
            dfs(i);
            temp++;
        }
    }
    cout << temp - 1 << endl;
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