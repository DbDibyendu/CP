//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯

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

//! Did wrong implementation
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vl q(n + 1);
    map<ll, ll> hash;
    fo(i, 1, n + 1)
    {
        cin >> q[i];
        hash[q[i]]++;
    }
    vl B;
    set<int> New;
    fo(i, 1, n + 1)
    {
        if (hash[i] == 0)
        {
            B.pb(i);
            New.insert(i);
        }
    }
    map<ll, ll> hash2;
    k = 0;
    fo(i, 1, n + 1)
    {
        hash2[q[i]]++;
        if (hash2[q[i]] > 1)
        {
            cout << B[k] << " ";
            k++;
        }
        else
        {
            cout << q[i] << " ";
        }
    }
    cout << endl;
    int t = 0;
    k = 0;
    hash2.clear();
    int last;
    fo(i, 1, n + 1)
    {
        k = 0;
        hash2[q[i]]++;
        if (hash2[q[i]] > 1)
        {
            auto t = New.upper_bound(last);
            t--; //! Get the next lower element in set, as the set elements starts from 0, and the value of t starts from 1
            cout << *t << " ";
            last = *t;
            New.erase(last);
        }
        else
        {
            cout << q[i] << " ";
            last = q[i];
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