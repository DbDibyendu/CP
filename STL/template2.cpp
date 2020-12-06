

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll mod = 998244353;
const int maxn = 1000010;

void calc_primes();
void calc_fact();
ll bin_pow(ll,ll);
ll C(ll,ll);
vector<bool> primes(maxn,false);
ll fact[maxn];

vector<ll> adj[maxn];
bool visited[maxn]={false};
ll siz[maxn]={0};
vector<ll> v;

void dfs(ll u){
	for(auto x:adj[u]){
        visited[x]=true;
		if(!visited[x]){
			v.push_back(x);
			dfs(x);
		}
	}
}	

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int  t=1;
	//cin>>t;
	while(t--){
	    ll temp=0,flag=1;
	    
        // for making the graph
	    ll n,m; cin>>n>>m;
	    for(ll i=1;i<=m;i++){
	    	ll a; cin>>a;
	    	if(a!=0) cin>>temp;

	    	for(ll j=0;j<a-1;j++){
	    		ll b; cin>>b;
		    	adj[temp].push_back(b);
		    	adj[b].push_back(temp);
		    }
	    
        }
        // for components

	    for(ll i=1;i<=n;i++){
	    	if(!visited[i]){
	    		visited[i]=true;
	    		dfs(i);
	    		v.push_back(i);
	    		for(auto x:v) siz[x]=v.size();
	    		v.clear();
	    	}
	    }
	    for(ll i=1;i<=n;i++) cout << max(siz[i],flag)<< " ";
	}
	return 0;
}


//calculate primes
void calc_primes(){
	for(ll i=2;i<maxn;i++){
		if(!primes[i]){
			for(ll j=2*i;j<maxn;j+=i){
				primes[j]=true;
			}
		}
	}
}

// calculate factorial
void calc_fact(){
	fact[0]=1;
	for(ll i=1;i<maxn;i++){
		fact[i] = (fact[i-1]*i)%mod;
	}
}
// calculate a^b in log(b) time 
ll bin_pow(ll x,ll y){
	ll res=1;
	while(y){
		if(y%2)res=(res*x)%mod;
		x=(x*x)%mod;
		y/=2;
	}
	return res;
}
// calculate nCr%mod
ll C(ll n,ll r){
	if(r>n)return 0;
	ll a=fact[r];
	a=(a*fact[n-r])%mod;
	ll b=fact[n];
	a=bin_pow(a,mod-2);
	b=(a*b)%mod;
	return b;
}
//priority_queue,push_back,pop_back