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

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vector<pll> year;
    int x, y;
    fo(i, 0, n)
    {
        cin >> x >> y;
        year.pb(make_pair(x, y));
    }
    sort(year.begin(), year.end());
    k = 0;
    fo(i, 1, n)
    {
        // cout << year[i].first << " " << year[i].second;
        // cout << endl;

        for (j = k; j < i; j++)
        {
            if (year[i].first > year[j].first && year[i].second < year[j].second)
            {
                temp++;
                break;
            }
            else
            {
                k++;
            }
        }
        // deb(temp);
    }
    cout << temp;
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