#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)         \
    for (auto &aa : A)     \
        cout << aa << ' '; \
    cout << endl;
#define displayP(A)    \
    for (auto &aa : A) \
    {                  \
        display(aa);   \
    }
#define read(A)        \
    for (auto &aa : A) \
    {                  \
        cin >> aa;     \
    }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
const int N = 2010, M = N;
//=======================
vector<bool> visited;
vector<vector<int>> g;
// ll A[N];

//? 2 coloring tree
//! was easy, I was doing quite similar
void dfs(int u)
{
    visited[u] = true;
    for (auto x : g[u])
    {
        if (visited[x] == false)
        {
            cout << u << " " << x << endl;
            dfs(x);
        }
    }
}

void call(int u, int n)
{

    cout << "? " << u << endl;
    cout.flush();
    int i;
    vl A(n + 1);
    fo(i, 1, n + 1)
    {
        cin >> A[i];
    }
    int j;

    fo(i, 1, n + 1)
    {
        if (A[i] == 1)
        {
            g[i].push_back(u);
            g[u].push_back(i);
        }
    }
}
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    m = (n + 1) / 2;
    visited.assign(N, false);
    g.assign(n + 1, vector<int>());
    vl A(n + 1);
    cout << "? " << 1 << endl;
    fo(i, 1, n + 1)
    {
        cin >> A[i];
    }
    ll even = 0, odd = 0;
    fo(i, 2, n + 1)
    {
        if (A[i] == 1)
        {
            g[i].push_back(1);
            g[1].push_back(i);
        }
        if (A[i] & 1)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    // deb2(odd, even);
    if (odd < even)
    {
        fo(i, 2, n + 1)
        {
            if (A[i] & 1)
            {
                call(i, n);
            }
        }
    }
    else
    {
        fo(i, 2, n + 1)
        {
            if (A[i] % 2 == 0)
            {
                call(i, n);
            }
        }
    }
    cout << '!' << endl;
    dfs(1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================