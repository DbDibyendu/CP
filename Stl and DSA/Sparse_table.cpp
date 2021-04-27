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
const int N = 1e5, M = N;
//=======================

//? Sparse table code, it can't be used for updating of elements, (for updating use segment treesa)
ll st[N][25];
ll arr[N];
int Log[N];

void RangeSumQuery()
{

    for (int j = 1; j <= 25; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];

    //! For printing the sum in qeury range
    int L, R;
    cin >> L >> R;
    long long sum = 0;
    for (int j = 25; j >= 0; j--)
    {
        if ((1 << j) <= R - L + 1)
        {
            sum += st[L][j];
            L += 1 << j;
        }
    }
}

//! Idempotent Functions
void RangeMinQuery(int n)
{

    for (int j = 1; j <= 25; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    //! For printing the Min in query range
    Log[1] = 0;
    for (int i = 2; i <= n; i++)
        Log[i] = Log[i / 2] + 1;
    int L, R;
    cin >> L >> R;
    L--, R--;
    int j = Log[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
    cout << minimum << endl;
}

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    k = 25;

    clr(arr), clr(st);
    fo(i, 0, n)
    {
        cin >> arr[i];
        st[i][0] = arr[i];
    }
    RangeMinQuery(n);
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