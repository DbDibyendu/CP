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

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1, x, y;
    cin >> n;
    vpll A;
    vl B;
    vl Prefix(n, 0);
    fo(i, 0, n)
    {
        cin >> x;
        A.pb(make_pair(x, i + 1));
    }
    sort(A.begin(), A.end());
    fo(i, 0, n)
    {
        if (i > 0)
        {
            Prefix[i] = A[i].first + Prefix[i - 1];
        }
        else
        {
            Prefix[i] = A[i].first;
        }
    }
    B.pb(A[n - 1].second);
    for (i = n - 2; i >= 0; i--)
    {
        if (Prefix[i] < A[i + 1].first)
        {
            break;
        }
        else
        {
            B.pb(A[i].second);
        }
    }

    sort(B.begin(), B.end());

    cout << B.size() << endl;
    for (auto x : B)
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
        solve();
    }
    return 0;
}

//=======================