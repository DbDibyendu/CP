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
typedef pair<int, int>	pii;
typedef vector<int>		vi; 
typedef vector<pii>		vpii;
typedef vector<vi>		vvi;
//=======================
int i, j, n, m, k, l;
//=======================


void solve() {

 ll temp=0;
	    
	    ll n; cin>>n; 
	    ll A[n+1];
	    for(ll i=1;i<=n;i++){
	    	cin>>A[i];
	    }
	    ll cycle_length[n+1]={0};
	    int visited[n+1]={0};
	    for(ll i=1;i<=n;i++){
	    	if(visited[i]!=1){
	    		if(A[i]==i) cycle_length[i]=1;
	    		else{
	    			vi v;
	    			temp=A[i];
	    			while(temp!=i){
	    				v.push_back(temp);
	    				temp  = A[temp];
	    			}
	    			v.push_back(i);
	    			for(auto x:v) {
	    				cycle_length[x] = v.size();
	    				visited[x] =1;
	    			}
	    		}
	    	}
	    }
        for(ll i=1;i<=n;i++) cout<<cycle_length[i]<<" ";

        cout<<endl;
    
}


int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
//=======================