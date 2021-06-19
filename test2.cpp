#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,n) for(i=a;i<n;i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A) for(auto &aa:A) cout <<aa<<' '; cout <<endl;  
#define displayP(A) for(auto &aa:A) {display(aa);}  
#define read(A) for(auto &aa:A) {cin>>aa;} 
//===========================
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef pair<ll, ll> pll; 
typedef vector<pll> vpll; 
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================


void solve() {
 
    ll i, j, n, m, k;
    ll temp=0,flag=0;
    cin >> n>>k;
    string A;
    cin>>A;
    ll t=n;
    for(i=1;i<=n;i++){

        ll t3=0;
        for(j=0;j<i;j++){
            if(i+j>=n){
                break;
            }
            // deb2(A[i+j],A[j]);
            if(A[i+j]>A[j]){
                t=i;
                flag=1;
                break;
            }
            else if(A[i+j]==A[j]){
                // break;
                t3++;
                // t=i;
                continue;
            }
            else{
                break;
            }
        }
        if(t3==i){
            t=i;
        }
        if(flag){
            break;
        }
    }
    
    for(i=0;i<k;i++){
        cout<<A[i%t];
    }
    cout<<endl;
}


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


//=======================