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
const int N = 305, M = N;
//=======================

void solve()
{

    int n, i, j, m, k;
    ll flag = 0, temp = 0, x, y;
    cin >> x >> y;
    string A;
    cin >> A;
    char c1, c2;
    n = A.length();
    string ans;
    int r = 0, last = 0;
    fo(i, 0, n)
    {
        if (A[i] == 'C' || A[i] == 'J')
        {
            flag++;
        }
    }
    if (flag == 0)
    {
        cout << 0<< endl;
        return;
    }
    fo(i, 0, n)
    {
        if (A[i] == 'C')
        {
            c1 = 'C';
            if (r == 0)
                fo(j, 0, i)
                {
                    ans.pb(c1);
                }
            r++;
            ans.pb(c1);
        }
        else if (A[i] == 'J')
        {
            c1 = 'J';
            if (r == 0)
            {
                fo(j, 0, i)
                {
                    ans.pb(c1);
                }
            }
            r++;
            ans.pb(c1);
        }
        else if (A[i] == '?')
        {
            if (r)
            {
                ans.pb(c1);
            }
        }
    }
    fo(i, 0, n - 1)
    {
        if (ans.substr(i, 2) == "CJ")
        {
            temp += x;
        }
        else if (ans.substr(i, 2) == "JC")
        {
            temp += y;
        }
    }
    cout << temp << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    int k = 1;
    while (t--)
    {
        cout << "Case #" << k << ": ";
        solve();
        k++;
    }
    return 0;
}

//=======================