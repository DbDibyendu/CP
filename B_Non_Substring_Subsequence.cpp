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


void solve() {
 
    int i, j, n, m, k, q;
    ll temp=0,flag=1;
    cin >> n>>q;
    char s[n];
    cin>>s;
    while(q--)
    {
        int l,r, len=0;
        cin>>l>>r;
        len=l-r+1;
        char dp[len];
        char temp[len];
        i=0;
       
    }
     
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