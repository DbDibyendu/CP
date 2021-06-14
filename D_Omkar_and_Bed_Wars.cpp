#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)         \
    for (auto &aa : A)     \
        cout << aa << ' '; \
    cout << endl;
#define displayP(A)    \
    for (auto &aa : A) \
    {                  \
        display(aa);   \
    }
#define read(A)        \
    for (auto &aa : A) \
    {                  \
        cin >> aa;     \
    }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

//! Observation based question
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    string A;
    cin >> A;
    int st = 0, end = n - 1;
    if (A[0] == A[n - 1])
    {
        flag = 0;
        int t = 0;
        for (i = 1; i < n; i++)
        {
            if (A[i] == A[i - 1])
            {
                t++;
            }
            else
            {
                st = i;
                break;
            }
        }
        if (st == 0 && flag == 0)
        {
            cout << ((t + 1) + 3 - 1) / 3 << endl;  //! A bit tricky here
            return;
        }
        for (i = n - 2; i >= 0; i--)
        {
            if (A[i] == A[i + 1])
            {
                t++;
            }
            else
            {
                end = i;
                break;
            }
        }
        if (t >= 1)
        {
            temp += (t + 2) / 3;
        }
    }

    // deb2(st, end);
    int t = 0;
    // deb(temp);
    for (i = st + 1; i <= end; i++)
    {
        // deb2(A[i], A[i - 1]);
        if (A[i] == A[i - 1])
        {
            t++;
        }
        else
        {
            if (t >= 2)
            {
                temp += (t + 1) / 3;
            }
            t = 0;
        }
    }
    if (t >= 2)
    {
        temp += (t + 1) / 3;
    }
    // deb(temp);
    cout << temp << endl;
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