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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================
ll i, j, n, m, k;
//=======================

void solve()
{

    ll temp = 0, flag = 1;
    int x;
    cin >> n >> x;
    vi A(n);
    fo(i, n) cin >> A[i];
    k = 0;
    i=0;
    while (!is_sorted(A.begin(),A.end()))
    {
        if(i==n){
            cout<<-1<<endl;
            return;
        }
    
            if(A[i] > x && i<n){
                swap(x, A[i]);
                 k++;
            }
      //  deb(k);
        
        i++;
    }
    cout<<k<<endl;
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