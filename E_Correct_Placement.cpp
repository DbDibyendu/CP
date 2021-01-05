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

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vector<pair<int, int>> frnd(n);

    fo(i, 0, n)
    {
        cin >> frnd[i].first >> frnd[i].second;
    }

    for (i = 0; i < n; i++)
    {
        flag = 1;
        for (j = 0; j < n; j++)
        {
            if (frnd[j].first < frnd[i].first && frnd[j].second < frnd[i].second)
            {
                //   cout << j + 1 << " ";
                flag = 0;
                temp = j + 1;
            }
            else if (frnd[j].second < frnd[i].first && frnd[j].first < frnd[i].second)
            {
                // cout << j + 1 << " ";
                flag = 0;
                temp = j + 1;
            }
        }
        if (flag != 0)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << temp << " ";
        }
    }
    cout << endl;
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