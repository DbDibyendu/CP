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
const int N = 1e3, M = N;
//=======================

int dp[N][N];
string A, B;
int result = 0;

int recur(int n, int m)
{
	if (n == 0 || m == 0)
	{
		dp[n][m] = 0;
		return dp[n][m];
	}
	if (dp[n][m] != 0)
	{
		return dp[n][m];
	}
	if (A[n - 1] == B[m - 1])
	{
		dp[n][m] = recur(n - 1, m - 1) + 1;
		result = max(dp[n][m], result);
	}
	else
	{
		recur(n - 1, m);
		recur(n, m - 1);
		dp[n][m] = 0;
	}
	return dp[n][m];
}


int eshita(int n, int m)
{
	int ans = 0;
	if (n == 0 || m == 0)
	{
		return 0;
	}

	if (A[n - 1] == B[m - 1])
	{
		ans = eshita(n - 1, m - 1) + 1;
		result = max(ans, result);
	}
	else
	{
		ans = 0;
		eshita(n - 1, m);
		eshita(n, m - 1);
	}
	return ans;
}

void solve()
{

	int i, j, n, m, k;
	ll temp = 0, flag = 1;
	cin >> A >> B;
	clr(dp);
	eshita(A.length(), B.length());
	cout << result << endl;
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