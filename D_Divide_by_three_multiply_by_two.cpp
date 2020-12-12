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
vector<vector<int>> g;

void edge(int a, int b);
void dfs(ll u);
void bfs(ll u);

void solve()
{

    int i, j, n, m, k;
    ll temp1 = 0, temp2 = 0, flag = 1;
    cin >> n;
    vector<long long int> A(n, 0);
    // Important
    visited.assign(n, false);
    vector<bool> v(n, 0);
    g.assign(n, vector<int>());

    fo(i, 0, n) cin >> A[i];

    fo(i, 0, n)
    {
        v[i] = true;
        if (A[i] % 3 == 0)
        {
            fo(j, 0, n)
            {

                if (A[i] / 3 == A[j] && !v[j])
                {
                    v[j] = true;
                    edge(i, j);
                    deb2(i, j);
                }
            }
        }
        else
        {
            fo(j, 0, n)
            {

                if (A[j] == 2 * A[i] && !v[j])
                {
                    v[j] = true;
                    edge(i, j);
                    deb2(i, j);
                }
            }
        }
    }

    
}

int main()
{
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================

void edge(int a, int b)
{
    //  undirected graph
    g[a].pb(b);
    g[b].pb(a);
}

void dfs(ll u)
{
    visited[u] = true;

    for (auto x : g[u])
    {
        if (visited[x] == false)
        {
            cout << x << " ";
            dfs(x);
        }
    }
}

void bfs(ll u)
{
    queue<int> q;

    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (auto x : g[f])
        {
            if (!visited[x])
            {
                q.push(x);
                cout << x << " ";
                visited[x] = true;
            }
        }
    }
}