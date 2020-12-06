#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
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
    ll temp = 0, flag = 1;
    cin >> n;
    ll dp[n];
    ll arr[n];
    fo(i, n)
    {
        dp[i]=0;
        cin >> arr[i];
        if(arr[i]==0) flag=0;
        if (arr[i] < 0) temp++;
        
    }
    ll sum =0;
    for (j = 0; j < n; j++)
    {
        sum =sum + abs(abs(arr[j])-1);
    }

    if(temp%2!=0 && flag!=0){
        cout<<sum+2;
        return;
    }
    cout<<sum;
    
}

int main()
{
    int t = 1;
   // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================