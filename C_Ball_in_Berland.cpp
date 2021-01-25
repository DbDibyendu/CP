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

    ll a, b, i, j, n, m, k;
    ll temp = 0, flag = 1;

    unordered_map<int, int> boy;
    unordered_map<int, int> girl;
    unordered_map<int, int> boygirl;

    cin >> a >> b >> k;
    pll couples[k];
    fo(i, 0, k)
    {
        cin >> couples[i].first;
    }
    fo(i, 0, k)
    {
        cin >> couples[i].second;
    }

    if (k == 1)
    {
        cout << 0 << endl;
        return;
    }

    fo(i, 0, k)
    {

        temp += i - boy[couples[i].first] - girl[couples[i].second] - boygirl[couples[i].first] - boygirl[couples[i].second];
        if (couples[i].first != couples[i].second)
        {
            boy[couples[i].first]++;
            girl[couples[i].second]++;
        }
        else
        {
            boygirl[couples[i].first]++;
        }
        // deb(temp);
    }

    cout << temp << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================