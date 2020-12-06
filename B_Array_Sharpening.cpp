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

int n, m, k;
//=======================


void solve1() {
 
  int i=0,j=-1,m=0;
  cin >> n;
  vi A(n);
  fo(i,n) cin>>A[i];

    fo(i,n){
      if(i>A[i]){
          j=i;
          break;
      }     
    }
    if(j == -1) cout<<"Yes"<<endl;
    else{
    for(i;i<n;i++){
        if(n-j-1==A[j-1]) {
            cout <<"No"<<endl; 
            m=-1; 
            break; 
            }
        if(n-i-1>A[i]){
            cout<<"No"<<endl; 
            m =-1; 
            break;
        }
    }
    if(m!=-1) cout<<"Yes"<<endl;
    }
}

void solve2(){
    int a[1000000];
    int n;scanf("%d",&n);
        int l = 0,r = n + 1;
        for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
        for(int i = 1;i <= n;i++)
        {
            if(a[i] >= i - 1)
            {
                l = i;
            }
            else break;
        }
        for(int i = n;i >= 1;i--)
        {
            if(a[i] >= n - i)
            {
                r = i;
            }
            else break;
        }
        if(l >= r)printf("Yes\n");
        else printf("No\n");

}


int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve2();
    }
 
    return 0;
}
//=======================