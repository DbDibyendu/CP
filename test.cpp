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

	int i, j, n, m, k;
	ll temp = 0, flag = 1;
	cin >> n;
	vector<vector<int>> bomb(n, vector<int>(2, 0));

	for (i = 0; i < n; i++)
	{
		cin >> bomb[i][0] >> bomb[i][1];

		if (bomb[i][0] == 0 || bomb[i][1] == 0)
		{
			temp += 4;
		}
		else
		{
			temp += 6;
		}
	}
	cout << temp << endl;
	sort(bomb.begin(), bomb.end());
	fo(i, 0, n)
	{
		if (abs(bomb[i][0]))
			printf("1 %d %c\n", abs(bomb[i][0]), bomb[i][0] > 0 ? 'R' : 'L');
		if (abs(bomb[i][1]))
			printf("1 %d %c\n", abs(bomb[i][1]), bomb[i][1] > 0 ? 'U' : 'D');
		printf("2\n");
		if (abs(bomb[i][0]))
			printf("1 %d %c\n", abs(bomb[i][0]), bomb[i][0] > 0 ? 'L' : 'R');
		if (abs(bomb[i][1]))
			printf("1 %d %c\n", abs(bomb[i][1]), bomb[i][1] > 0 ? 'D' : 'U');
		printf("3\n");
	}
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