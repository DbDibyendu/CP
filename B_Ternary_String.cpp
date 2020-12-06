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
    string s;
    cin >> s;
    n = s.size();
    vector<pair<char, int>> A;
    int ans= INT_MAX;
    for (auto x : s)
    {
        if(A.empty() || A.back().first !=x){
                A.pb(make_pair(x,1));
        }
        else
        {
            A.back().second++;

        }
    }
 //   deb(A.size());
    for(i=1;i<A.size()-1;i++){
        if(A[i-1].first !=A[i+1].first){
            ans=min(ans, A[i].second+2);
        }
    }
    if(ans>n) ans=0;
    cout<<ans<<endl;

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