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
	int lengthOfLIS(vector<int> &nums)
	{

		vector<int> dp, visited;
		int n = nums.size();
		vector<int> dp(n + 1, 0), visited(n, 0);
		int i, k;
		for (i = 0; i < n; i++)
		{
			for (k = 0; k < i; k++)
			{
				if (nums[i] < nums[k] && visited[k]==0)
				{
					dp[k] = max(dp[k], dp[i] + 1);
					visited[k]=1;
				}
			}
		}
	}
};