#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
//=======================

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 0;
    cin >> n;
    vl A(n);
    unordered_map<ll, ll> count;

    fo(i, 0, n)
    {
        cin >> A[i];
        count[A[i]]++;
        temp=max(A[i],temp);
    }
    vl dp(temp+1);
    dp[0] = 0;
    dp[1] = count[1] * 1;

    for (i = 2; i <= temp; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * i);
     //   flag = max(dp[i], flag);
    }
    cout << dp[temp] << endl;
}

int main()
{
    int t = 1;

    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================