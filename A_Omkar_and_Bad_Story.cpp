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

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 0;
    cin >> n;
    vl A(n), B;
    read(A);
    map<int, int> hash;
    for (auto x : A)
    {
        if (x >= 0)
        {
            temp++;
        }
        else
        {
            flag++;
        }
    }
    if (temp != n && flag != n)
    {
        cout << "NO" << endl;
        return;
    }
    sort(A.begin(), A.end());
    for (auto x : A)
    {
        hash[x]++;
        B.push_back(x);
        if (x >= 0)
        {
        }
    }
    int t = -1;
    while (A.size() <= 320 && t == -1)
    {
        t = 0;
        for (i = 0; i < A.size(); i++)
        {
            for (j = i + 1; j < A.size(); j++)
            {
                if (hash[abs(A[i] - A[j])])
                {
                }
                else
                {
                    t = -1;
                    B.push_back(abs(A[i] - A[j]));
                    hash[abs(A[i] - A[j])]++;
                }
            }
        }
        A = B;
        if (t == 0)
        {
            break;
        }
    }
    if (B.size() > 300)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << B.size() << endl;
        display(B);
    }
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