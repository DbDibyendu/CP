#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define pb push_back

const int N = INT_MAX;
//===========================
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================

bool check(int n)
{

	int temp = n;
	vi arr(10, 0);
	while (temp)
	{
		arr[temp % 10]++;
		if (arr[temp % 10] > 1)
			return 0;
		temp /= 10;
	}
	return 1;
}
void solve()
{

	int i, j, n, m, k;
	int temp = 0, flag = 1;
	cin >> i >> j;
	cout << (i & j) << endl;
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