#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = 100005;
//===========================
typedef pair<int, int>	pii;
typedef vector<int>		vi; 
typedef vector<pii>     vpii;
typedef vector<vi>		vvi;
//=======================

// Not an optimal solution with dp
// will show run time error

void solve() {
 
    ll i, j, n=0, m, k;
    ll temp=0,flag=1;
    cin >> n;
    if(n>1000 && (n%100==0)){
        cout<<n/100;
        return;
    }
    ll dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(j=1;j<=n+1;j++) dp[j]=INT_MAX;
    
    for(i=1;i<=n;i++){
        
        dp[i]=min(dp[i],dp[i-1]+1);
        if(i>=5){
            dp[i]=min(dp[i],1+dp[i-5]);
        } 
        if(i>=10){
            dp[i]=min(dp[i],1+dp[i-10]);
        }
        if(i>=20){
             dp[i]=min(dp[i],1+dp[i-20]);
        }
        if(i>=100){
            dp[i]=min(dp[i],1+dp[i-100]);
        }

    } 
   cout<<dp[n];
}


int main() {
    int t = 1;
   // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


//=======================