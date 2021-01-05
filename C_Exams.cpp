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

    int i, j, n, m, k,a,b, lastdate;
    ll temp = 0, flag = 1;
    cin >> n;
    vector<pair<int, int>> vect;
    fo(i,0,n){
        cin>>a>>b;
        vect.pb(make_pair(a,b));
    }
    sort(vect.begin(),vect.end());

    lastdate=min(vect[0].first,vect[0].second);
    fo(i,1,n){
        if(vect[i].first >=lastdate && vect[i].second>=lastdate){
            lastdate=min(vect[i].first,vect[i].second);
        }
        else 
        {
            lastdate=vect[i].first;
        }
        
    }
    cout<<lastdate<<endl;
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