#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set<int> si;
typedef map<string,int> msi;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define FOR(i,a,b) for(ll i=int(a);i<ll(b);i++)
#define TR(it,a) for(auto it=a.begin();it!=a.end();it++)
#define REV(i,a,b) for(int i=a;i>=b;i--)
#define debug(x) cout<< #x <<" = "<<x<<"\n"
#define debug2(x,y) cout<< #x <<" = "<<x<<" , "<< #y <<" = "<<y<<"\n"
#define all(x) x.begin(),x.end()
#define sortall(x) (sort(all(x)))
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);

ll mpow(ll x,ll y);

const int MOD=1e9+7,MAX=2e5+5;
const ll INF=1e16;

void solve()
{
	int n;
	cin>>n;
	vl a(n);
	FOR(i,0,n)
		cin>>a[i];
	map<ll,int> ctr;
	FOR(i,0,n)
		ctr[a[i]]++;
	vi c;
	for(auto it:ctr)
		c.pb(it.ss);
	sortall(c);
	ll sum=0,dec=0;
	ll m=c.size();
	FOR(i,0,m){
		dec+=c[i]-c[0];
	}
	ll ans=dec;
	FOR(i,0,m-1){
		sum+=c[i];
		dec=dec-(c[i+1]-c[i])*(m-i-1);
		//debug(dec);
		ans=min(ans,dec+sum);

	}
	cout<<ans<<"\n";
	
}

int main()
{
	FAST_IO;
	int t=1,i=0;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<++i<<": ";
		solve();
	}
}

ll mpow(ll x, ll y)
{
	if(y==0)
		return 1;
	if(y%2)
		return (x*mpow(x,y-1))%MOD;
	ll ans=mpow(x,y/2);
	ans=(ans*ans)%MOD;
	return ans;
}
