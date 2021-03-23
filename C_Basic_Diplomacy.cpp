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

//! Solved my own, good implementation
void solve()
{

    int i, j, n, m, k, t;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    vector<pair<int, vi>> elements;
    fo(i, 0, m)
    {
        cin >> k;
        vi A;
        A.pb(i);
        fo(j, 0, k)
        {
            cin >> t;
            A.pb(t);
        }
        elements.pb({k, A});
        A.clear();
    }
    sort(elements.begin(), elements.end());
    int limit = (m + 1) / 2;

    map<int, int> hash;
    int val;
    vector<pair<int, int>> ans;
    fo(i, 0, m)
    {
        int count = 0;
        int index;
        for (auto x : elements[i].second)
        {
            if (count == 0)
            {
                index = x;
                count++;
                continue;
            }
            if (count == 1)
            {
                temp = hash[x];
                val = x;
                count++;
                continue;
            }
            if (hash[x] < temp)
            {
                temp = hash[x];
                val = x;
            }
            // cout << x << " ";
        }
        hash[val]++;
        ans.pb({index, val});
        if (hash[val] > limit)
        {
            cout << "NO" << endl;
            return;
        }
    }
    sort(ans.begin(), ans.end());
    cout << "YES" << endl;
    for (auto x : ans)
    {
        cout << x.second << " ";
    }
    cout << endl;
}

//! Approach 2, better implementation 
void solve2()
{

    int i, j, n, m, k, t;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    vector<pair<int, vi>> elements;
    fo(i, 0, m)
    {
        cin >> k;
        vi A;
        fo(j, 0, k)
        {
            cin >> t;
            A.pb(t);
        }
        elements.pb({k, A});
        A.clear();
    }
    int limit = (m + 1) / 2;

    map<int, int> hash;

    fo(i, 0, m)
    {
        int count = 0;
        int size = elements[i].second.size();
        if (size == 1)
            for (auto x : elements[i].second)
            {
                hash[x]++;
                // cout << x << " ";
            }
    }
    int val;
    vl ans;

    fo(i, 0, m)
    {
        int count = 0;
        int index;
        int size = elements[i].second.size();
        for (auto x : elements[i].second)
        {
            if (count == 0)
            {
                temp = hash[x];
                val = x;
                count++;
                continue;
            }
            if (hash[x] < temp)
            {
                temp = hash[x];
                val = x;
            }
            // cout << x << " ";
        }
        if (size > 1)
            hash[val]++;
        ans.pb(val);
        if (hash[val] > limit)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
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