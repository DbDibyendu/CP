#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, a, n) for (i = a; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================

void solve()
{

    int i, j, n, m, k;
    cin >> n;
    vi A(n);
    int dp[n+1],dp2[n+1];
    fo(i, 0, n)
    {
        cin >> A[i];
        dp[i+1]=0;
        dp2[i]=0;
    }
    sort(A.begin(), A.end());
    
    
    if(A[n-1]>n){
        cout<<0;
        return;
    }
    dp[0]=0;
    for(i=1;i<=n;i++){
        if(i-A[i-1]>=0)
        dp[i]=max(dp[i-A[i-1]]+1,dp[i-1]);

        else if(i-A[i-1]<=0 && A[i-1]+i-1<=n)
        {
            dp[i+A[i-1]-1]=dp[i-1]+1;
        }
        
    }
    int ans=dp[n];
    cout<<ans<<endl;
}
void solve2()
{
 
    int i, j, n, m, k;
    ll temp = 0, flag = 0;
    cin >> n;
    vi A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    if(A[n-1]>n){
        cout<<0<<endl;
        return;
    }
    for(j=0;j<n;j++){
         temp++;
         if(temp==A[j]){
             temp=0;
             flag++;
         }
    }
    cout<<flag<<endl;
}


int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================