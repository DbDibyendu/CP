#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INF 1e9+7
#define fin cin
#define ub upper_bound
#define lb lower_bound
using namespace std;
 
 
 
int main() {
	// your cod goes here
	int  t=1;
	cin>>t;
	while(t--){
	    ll temp=0,flag=1,ans=0,maxo=1e9+7,mino=-1e9-7;
	    
	    ll n; cin>>n; ll dp[n][2] = {0};ll A[n];
	    for(ll i=0;i<n;i++){
	        cin>>A[i];
	    }
	    dp[0][0] = A[0];
	    dp[0][1] = INT_MAX;
	    dp[1][0] = A[0]+A[1];
	    dp[1][1] = dp[0][0];
	    for(ll i=2;i<n;i++){
	        dp[i][0] = min(dp[i-1][1]+A[i],dp[i-2][1]+A[i-1]+A[i]);
	        dp[i][1] = min(dp[i-1][0],dp[i-2][0]);
	    }
	    cout << min(dp[n-1][0],dp[n-1][1])<<endl;
	}
	return 0;
}