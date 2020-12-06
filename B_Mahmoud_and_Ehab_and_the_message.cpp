#include <bits/stdc++.h>
#include <map>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = 100005;
//===========================
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================

map<string, int> group;

//=======================

void solve()
{
    string word[N];

    int i, j, n, m, k, a, b ;
    ll temp = 0, flag = 1,sum = 0;
    ll min_cost[N];
    ll cost[N];

    cin >> n >> k >> m;

    for (i = 1; i <= n; i++)
    {
        cin >> word[i];
    }

    for (i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }

    for (i = 1; i <= k; i++)
    {
        min_cost[i] = (1<<30);
        cin >> a;
        for (j = 0; j < a; j++)
        {

            cin >> b;
            min_cost[i] = min(min_cost[i], cost[b]);
            group[word[b]] = i;
        }
    }
    for (i = 1; i <= m; i++)
    {
        string msg;
        cin >> msg;
        sum += min_cost[group[msg]];
    }
    cout << sum << endl;
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