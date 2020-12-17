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
    vi A(10,100);
    if(n>45){
        cout<<-1<<endl;
        return;
    }
    else if(n<10){
        cout<<n<<endl;
        return;
    }
    else if(10<=n && n<=17){
        cout<<n-9<<9<<endl;
        return;
    }
    else if(17<n && n<=24){
        cout<<n-(8+9)<<8<<9<<endl;
        return;
    }
    else if(24<n && n<=30){
        cout<<n-(7+8+9)<<7<<8<<9<<endl;
        return;
    }
    else if(30<n && n<=35){
        cout<<n-(6+7+8+9)<<6<<7<<8<<9<<endl;
        return;
    }
    else if(35<n && n<=39){
        cout<<n-(6+5+7+8+9)<<5<<6<<7<<8<<9<<endl;
        return;
    }
    else if(39<n && n<=42){
        cout<<n-(4+6+5+7+8+9)<<4<<5<<6<<7<<8<<9<<endl;
        return;
    }
    else if(42<n && n<=44){
        cout<<n-(3+4+6+5+7+8+9)<<3<<4<<5<<6<<7<<8<<9<<endl;
        return;
    }
    else if(44<n && n<=45){
        cout<<n-(2+3+4+6+5+7+8+9)<<2<<3<<4<<5<<6<<7<<8<<9<<endl;
        return;
    }
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