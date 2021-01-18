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

int ans = 0;
void calc(int x, int y, int m, int n);

int throughDP(int m, int n)
{
	vector<vector<int>> dp(m, vector<int>(n, 1));
	int i, j;
	for (i = 1; i < m; i++)
	{
		for (j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}
void solve()
{

	int i, j, n, m, k;
	ll temp = 0, flag = 1;
	cin >> m >> n;
	ans = throughDP(m, n);
	cout << ans << endl;
}

int main()
{
	int t = 1;
	//	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
