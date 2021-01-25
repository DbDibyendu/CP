
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

const int NMAX = 2014;
long long d1[2 * NMAX], d2[2 * NMAX], sol[2];
pair<int, int> v[2];
int a[NMAX][NMAX];


// I don't know why, but I'm getting TLE error
void solve()
{
    int i, j;
    int n;
    cin >> n;
    sol[0] = sol[1] = -1;

    fo(i, 1, n + 1)
    {
        fo(j, 1, n + 1)
        {
            cin >> a[i][j];
            d1[i - j + n] += a[i][j];
            d2[i + j] += a[i][j];
        }
    }

    ll temp, c;
    fo(i, 1, n + 1)
    {
        fo(j, 1, n + 1)
        {
            c = (i + j) & 1;
            temp = d1[i - j + n] + d2[i + j] - a[i][j];
            if (sol[c] < temp)
            {
                sol[c] = temp;
                v[c].first = i;
                v[c].second = j;
            }
        }
    }
    cout << sol[0] + sol[1] << '\n';

    cout << v[0].first << " " << v[0].second << " ";
    cout << v[1].first << " " << v[1].second << " ";
}

inline void Update(const int c, const int i, const int j, const long long val)
{
    if (val > sol[c])
    {
        sol[c] = val;
        v[c].first = i;
        v[c].second = j;
    }
}
int solve2()
{

    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    sol[0] = sol[1] = -1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> a[i][j];
            d1[i + j] += a[i][j];
            d2[i - j + n] += a[i][j];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            Update((i + j) & 1, i, j, d1[i + j] + d2[i - j + n] - a[i][j]);
    cout << sol[0] + sol[1] << "\n";
    if (v[0] > v[1])
        swap(v[0], v[1]);
    cout << v[0].first << " " << v[0].second << " ";
    cout << v[1].first << " " << v[1].second << "\n";
    return 0;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================