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

// ! Time Limit exceeded on test 12
// * Accepted
// ! Do not use UNORDERED MAP.... will result in TLE
void solve()
{

    int i, j, n, m, k;
    ll temp = MOD, flag = 1;
    cin >> n;
    vl A(n);
    map<ll, int> Order;  // ! ALways use map, in normal case
    set<int> unique;
    fo(i, 0, n)
    {
        cin >> A[i];
        Order[A[i]]++;
        unique.insert(A[i]);
    }
    vl B;
    for (auto x : unique)
    {
        B.pb(Order[x]);
    }
    sort(B.begin(), B.end());

    map<int, int> O2;
    set<int> Final;

    for (auto x : B)
    {
        O2[x]++;
        Final.insert(x);
    }

    m = Final.size();
    vl Prefix(m), Prefix_count(m);
    i = 0;
    for (auto x : Final)
    {

        if (i > 0)
        {
            Prefix[i] = x * O2[x] + Prefix[i - 1];
            Prefix_count[i] = O2[x] + Prefix_count[i - 1];
        }
        else
        {
            Prefix[i] = x * O2[x];
            Prefix_count[i] = O2[x];
        }
        i++;
    }
    i = 0;
    for (auto x : Final)
    {
        if (i > 0)
        {
            temp = min(temp, Prefix[i - 1] + (Prefix[m - 1] - Prefix[i]) - x * (Prefix_count[m - 1] - Prefix_count[i]));
        }
        else
        {
            temp = min(temp, (Prefix[m - 1] - Prefix[i]) - x * (Prefix_count[m - 1] - Prefix_count[i]));
        }
        i++;
    }

    cout << temp << endl;
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