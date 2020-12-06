#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = 100005;
//===========================
typedef vector<int> vi;
//=======================

class Solution
{
public:
	vector<vector<int>> dp, visited;

	int calc(int i, int j, string &s)
	{

		if (i == j)
		{
			return 1;
		}

		if(visited[i][j]){
			return dp[i][j];
		}
		if (s[i] == s[j] && !visited[i][j])
		{
			visited[i][j]=1;
			dp[i][j]=calc(i + 1, j - 1, s);
			return dp[i][j];
		}
		else
		{
			visited[i][j]=1;
			return 0;
		}
	}
	int countSubstrings(string s)
	{

		int i, j;
		int n = s.size();
		int ans = 0;
		vector<vector<int>> dp, visited;

		for (i = 0; i < n; i++)
		{
			for (j = i; j < n; j++)
			{
				ans += calc(i, j, s);
			}
		}

		return ans;
	}
};