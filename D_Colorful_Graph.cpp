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
const int N = 1000000, M = N;
//=======================
int visited[N] = {0};
vi g[N];
int A[N];
map<int, int> T;

void solve()
{
    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n >> m;

    fo(i, 1, n + 1)
    {
        cin >> A[i];
    }

    int x, y;
    fo(i, 0, m)
    {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    map<int, set<int>> card; // ! Important trick to solve this question

    for (j = 1; j <= n; j++)
    {
        for (auto x : g[j])
        {
            if (A[j] != A[x])
            {
                T[A[j]]++;
                card[A[j]].insert(A[x]);
            }
        }
    }
    temp = 0;
    int ans = 0;
    if (card.size())
    {
        for (auto x : card)
        {
            if (x.second.size() > temp)
            {
                temp = x.second.size();
                ans = x.first;
            }
            // deb2(x.first, x.second.size());
        }

        cout << ans;
        return;
    }

    ans = INT_MAX;
    fo(i, 1, n + 1)
    {
        if (A[i] < ans)
        {
            ans = A[i];
        }
    }

    cout << ans << endl;
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