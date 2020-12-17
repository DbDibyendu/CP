#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,a,n) for(i=a;i<n;i++)
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
typedef pair<int, int>	pii;
typedef vector<int>		vi; 
typedef vector<pii>     vpii;
typedef vector<vi>		vvi;
//=======================


void solve() {
 
    int i, j, n, m, k;
    ll temp=0,flag=1;
    cin >> n;
    vi A(n),B(n);
    j=n-1;
    k=0;
    fo(i,0,n) cin>>B[i];

    for(i=0;i<n;i++){
        if(i%2==0){
            A[i]=B[k];
            k++;
        }
        else{
            A[i]=B[j];
            j--;
        }
    } 
    fo(i,0,n) cout<<A[i]<<" ";

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