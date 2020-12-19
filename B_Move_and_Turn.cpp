#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
const int N = INT_MAX;
//===========================
typedef vector<int> vi;
typedef vector<vi> vvi;
//=======================

void solve()
{

    int i, j, n, m, k;
    ll ans = 0, flag = 1;
    cin >> n;
    k = n / 2;
    if(n%2==0){
        ans=(k+1)*(k+1);
    }
    else{
        ans=2*(k+2)*(k+1);
    }
    cout<<ans<<endl;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================