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
    i=1;
    ll l=1,t=1;
    j=0;
    while(i<n){
        // deb2(A[j],A[i]);

        if(A[i]<A[j]){
            l=i+1;
            j=0;

        }
        // Iterate for comparing , but don't increase the length
        else if(A[i]==A[j]){
          j++;
          t=l;
        }
        else{
            break;
        }
        i++;
    }
    // deb2(l,t);

    for(i=0;i<k;i++){
        cout<<A[i%l];
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