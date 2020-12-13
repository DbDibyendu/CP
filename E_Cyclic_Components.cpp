#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================
vector<bool> visited;
vvi adj;
vi v;

// correct dfs code
int dfscycle(ll u)
{

    visited[u] = true;
    v.pb(u);
    for (auto i : adj[u])
    {
        if (!visited[i])
        {
            dfscycle(i);
        }
    }
    return false;
}

void solve()
{

    int i, j, n, m, k, x, y;
    ll temp = 0, flag = 0;
    cin >> n >> m;

    int vertex[n+1] = {0};
    visited.assign(n + 1, false);
    adj.assign(n + 1, vector<int>());

    for (i = 0; i < m; i++)
    {
        x = 0, y = 0;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        vertex[x]++;
        vertex[y]++;
    }

    fo(i, 1, n + 1)
    {
        //   deb(visited[i]);
        if (visited[i] == false)
        {
            visited[i] == true;
            dfscycle(i);
            flag=1;
            for (auto x : v)
            {
                // deb2(x,vertex[x]);
                if (vertex[x] == 2)
                {
                    continue;
                }
                else
                {
                    flag = 0;
                }
            }

            if (flag == 1)
                temp++;

            v.clear();
        }
    }

    cout << temp << endl;
}

int main()
{
    int t = 1;
    //    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
