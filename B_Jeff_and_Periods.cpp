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
const int N = 1e5 + 10, M = N;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vi A(n);
    int diff[N], pos[N];
    clr(diff), clr(pos);
    map<int, int> s;
    fo(i, 0, n)
    {
        cin >> A[i];
        s[A[i]]++;
        if (i == 0)
            pos[A[i]] = i;
        else
        {
            if (s[A[i]] == 1)
            {
                diff[A[i]] = 0;
                pos[A[i]] = i;
            }
            else
            {
                if (diff[A[i]] != -1)
                    if (s[A[i]] > 2)
                    {
                        // deb2(i, pos[A[i]]);
                        if (diff[A[i]] == (i - pos[A[i]]))
                        {
                            diff[A[i]] = i - pos[A[i]];
                            pos[A[i]] = i;
                        }
                        else
                        {
                            diff[A[i]] = -1;
                        }
                    }
                    else
                    {
                        diff[A[i]] = i - pos[A[i]];
                        pos[A[i]] = i;
                    }
            }
        }
        // deb(diff[A[i]]);
    }

    for (auto x : s)
    {
        if (diff[x.first] != -1)
        {
            temp++;
            // cout << x.first << " " << diff[x.first] << endl;
        }
    }
    cout << temp << endl;

    for (auto x : s)
    {
        if (diff[x.first] != -1)
        {
            temp++;
            cout << x.first << " " << diff[x.first] << endl;
        }
    }
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