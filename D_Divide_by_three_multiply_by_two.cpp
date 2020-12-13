#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, a, n) for (i = a; i < n; i++)
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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================

int calc(ll x){
    
    int temp=0;
    while(x%3==0){
        temp++;
        x/=3;
    }
    return temp;
}

void solve()
{

    int i, j, n, m, k;
    ll tempD = 0, temp2 = 0, flag = 1;
    cin >> n;
    vector<pair<int,ll>> A(n);        /// notice integer to be first for sorting in lexicographical order

    fo(i,0,n){
        cin>>A[i].second;
        
        A[i].first= -calc(A[i].second);
    }

    sort(A.begin(),A.end());      // lexicographical order

    fo(i,0,n){
        cout<<A[i].second<<" ";
    }
    cout<<endl;
    
    


}

int main()
{
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================
