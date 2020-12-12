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

void solve()
{

	int i, j, n, m , k;
	int temp = 0, flag = 1;
	cin >> n >> k;
	vi A(n);
	fo(i, 0, n) cin >> A[i];
	sort(A.begin(), A.end());

	// Boundary conditions
	
	if (k == 0)
	{
		if(A[0]>1)
		cout << A[0]-1 << endl;
		else 
		cout << -1<<endl;
		return;
	}
	
	if(n==k){
		cout<<A[k-1]<<endl;
		return;
	}


	temp = A[k - 1];
	j = k - 1;

	if (A[k] <= temp)
	{
		cout << -1 << endl;
		return;
	}
	else
		cout << temp << endl;
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

//=======================