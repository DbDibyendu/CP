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
const int N = 1000005;
//===========================
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================

vi visited;
vvi adj(N);
vi v;
ll siz[N] = {0};

// correct dfs code
void dfs(ll u)
{
    visited[u] = true;
    v.pb(u);
    for (auto x : adj[u])
    {
        if (visited[x] == false)
        {
            dfs(x);
        }
    }
}

void bfs(ll u)
{
    queue<int> q;

    q.push(u);
    visited[u] = true;
    v.pb(u);
    while (!q.empty())
    {
        int f=q.front();
        q.pop();

        for(auto x: adj[f]){
            if(!visited[x]){
            q.push(x);
            v.pb(x);
            visited[x]=true;
            }

        }
    }
}
void solve1()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    int a = 0, b = 0;
    string s;
    cin >> n >> s;
    temp = 0;
    visited.assign(n, 0);
    adj.assign(n, vector<int>());

    fo(i, 0, n)
    {

        if (s[i] == '>')
            a++;
        if (s[i] == '<')
            b++;
    }
    if (a && b)
    {
        fo(i, 0, n)
        {
            if (s[i] == '-' && i != n - 1)
            {
                adj[i].pb(i + 1);
                adj[i + 1].pb(i);
            }
            if (s[i] == '-' && i == n - 1)
            {
                adj[i].pb(0);
                adj[0].pb(i);
            }
        }
        fo(k, 0, n)
        {
            if (!visited[k] && s[k] == '-')
            {
                visited[k] = true;
                dfs(k);
                temp += v.size();
            }
            v.clear();
        }
        cout << temp << endl;
    }

    else
        cout << n << endl;
}

void solve2()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    int a = 0, b = 0;
    string s;
    cin >> n >> s;
    temp = 0;
    visited.assign(n, 0);
    adj.assign(n, vector<int>());

    fo(i, 0, n)
    {

        if (s[i] == '>')
            a++;
        if (s[i] == '<')
            b++;
    }
    if (a && b)
    {
        fo(i, 0, n)
        {
            if (s[i] == '-' && i != n - 1)
            {
                adj[i].pb(i + 1);
                adj[i + 1].pb(i);
            }
            if (s[i] == '-' && i == n - 1)
            {
                adj[i].pb(0);
                adj[0].pb(i);
            }
        }
        fo(k, 0, n)
        {
            if (!visited[k] && s[k] == '-')
            {
                visited[k]=true;
                bfs(k);
              //  v.pb(k);
                temp += v.size();
            }
            v.clear();
        }
        cout << temp << endl;
    }

    else
        cout << n << endl;
}

void solve3()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    int a = 0, b = 0;
    string s;
    cin >> n;

    cin >> s;

    fo(i, 0, n)
    {

        if (s[i] == '>')
            a++;

        if (s[i] == '<')
            b++;
    }
    //  deb2(a,b);

    if (a && b)
    {

        fo(i, 0, n)
        {

            if (s[i] == '-')
            {
                temp += 2;

                if (s[i] == s[i + 1])
                    temp--;
            }

            //        deb(temp);
        }
        if (s[0] == s[n - 1] && s[0] == '-')
            temp--;
        cout << temp << endl;
    }
    else
        cout << n << endl;
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