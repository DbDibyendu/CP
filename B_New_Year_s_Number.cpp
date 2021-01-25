#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,n) for(i=a;i<n;i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
//===========================
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef pair<ll, ll> pll; 
typedef vector<pll> vpll; 
typedef vector<vl> vvl; 
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

ll n;


void solve() {
 
    int i, j, m, k;
    ll temp=0,flag=1;
    cin >> n;
    k=n/2020;
    for(i=0;i<=k;i++){
        if(2020*i +2021*(k-i)==n){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
     
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