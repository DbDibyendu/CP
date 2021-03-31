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

//! Greedy problem, tough implementation
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A;
    cin >> A;
    n = A.length();
    int C[26];
    clr(C);
    fo(i, 0, n)
    {
        C[int(A[i] - 'a')]++;
    }
    string ans;
    for (i = 0; i < n; i++)
    {
        if (C[A[i] - 'a'] == 0)
            continue;

        int pos = i;
        int mx = A[i] - 'a';
        int last = i;
        for (j = i; j < n; j++)
        {
            if (C[A[j] - 'a'] == 0)
                continue;

            if (A[j] - 'a' > mx)
            {
                pos = j;
                mx = A[j] - 'a';
            }
            if (C[A[j] - 'a'] == 1)
            {
                last = j;
                break;
            }
            C[A[j] - 'a']--;
        }
        for (j = pos + 1; j < last; j++)
        {
            if (C[A[j] - 'a'] != 0)
            {
                C[A[j] - 'a']++;
            }
        }
        // deb(pos);
        C[A[pos] - 'a'] = 0;
        ans.pb(A[pos]);
        i = pos;
    }
    cout << ans << endl;
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