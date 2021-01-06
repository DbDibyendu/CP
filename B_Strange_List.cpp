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
typedef vector<vi> vvi;
typedef vector<ll> vl;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

void solve()
{

    ll i, j, n, m, k, x;
    ll temp = 0, flag = 1;
    cin >> n >> x;
    vector<pair<ll, ll>> B;
    ll min = 0, max = 0;
    fo(i, 0, n)
    {
        cin >> k;
        B.pb(make_pair(k, k));
    }
    i=0;
    while (1)
    {

        if (B[i].first % x == 0)
        {
            B.push_back(make_pair(B[i].first / x, B[i].second));         
        }
        else
        {
            break;
        }
        i++;
    }
    for (auto a : B)
    {

        temp += a.second;
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