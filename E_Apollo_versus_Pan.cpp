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
const ll MOD = 1'000'000'007;
const ll N = 1e6, M = N;
//=======================

ll A[N];
//! Great approach....didn't try on my own
void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;

    fo(i, 0, n)
    {
        cin >> A[i];
    }
    ll Bits[61] = {0};

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 60; j++)
        {
            if (A[i] & (1ll << j))
            {
                Bits[j]++;
            }
        }
    }
    ll ans_and = 0;
    ll ans_or = 0;
    for (i = 0; i < n; i++)
    {
        ans_and = 0;
        ans_or = 0;
        for (j = 0; j < 60; j++)
        {
            ll p = (1ll << j) % MOD;
            if (A[i] & (1ll << j))
            {
                ans_and = (ans_and + p * Bits[j]) % MOD;
                ans_or = (ans_or + p * n) % MOD;
            }
            else
            {
                ans_or = (ans_or + p * Bits[j]) % MOD;
            }
        }
        temp = (temp + ans_or * ans_and) % MOD;
    }

    cout << temp << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================