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

//! Solved on my own, DP problem
void solve()
{

	int i, j, n, m, k;
	ll temp = 0, flag = 1;
	cin >> n;
	vi A(n);
	read(A);
	int dp[n][2];
	clr(dp);
	if (A[0] == 1)
	{
		dp[0][1] = 1;
	}
	dp[0][0] = MOD;
	if (n >= 2)
	{
		dp[1][0] = dp[0][1];
		if (A[1] == 1)
		{
			dp[1][1] = dp[0][1] + 1;
		}
		else
		{
			dp[1][1] = dp[0][1];
		}
		if (n > 2)
		{
			for (i = 2; i < n; i++)
			{
				if (A[i] == 1)
				{
					if (A[i - 1] == 1)
						dp[i][1] = min({dp[i - 1][0], 1 + dp[i - 2][0]}) + 1;
					else
					{
						dp[i][1] = min({dp[i - 1][0], dp[i - 2][0]}) + 1;
					}
					dp[i][0] = min({dp[i - 1][1], dp[i - 2][1]});
				}
				else
				{
					if (A[i - 1] == 1)
						dp[i][1] = min({dp[i - 1][0], 1 + dp[i - 2][0]});
					else
					{
						dp[i][1] = min({dp[i - 1][0], dp[i - 2][0]});
					}
					dp[i][0] = min({dp[i - 1][1], dp[i - 2][1]});
				}
				// deb2(dp[i][1], dp[i][0]);
			}
		}
	}
	cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
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