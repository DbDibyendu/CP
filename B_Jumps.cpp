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
int i, j, n, m, k;
//=======================


void solve() {
 
    cin >> n;

    ll ans;
    
    for(i=1;i<=n;i++){
        if(i*(i+1)/2>=n){
            ans=i;
            break;
        }
    }
    if(ans*(ans+1)/2==n+1){
        cout<<ans+1<<endl;
        return;
    }
    cout<<ans<<endl;

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