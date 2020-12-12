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



void solve()
{

    int i, j, n, m, k;
    ll temp = 1, lst = 0;
    cin >> n;
    vi A(n);
    vi ans(n,0);

    fo(i, 0, n) cin >> A[i];
    if (n <= 2)
    {
        cout << n - 1 << endl;
        return;
    }

    // deb(temp);
    fo(i, 1, n )
    {
        if(A[i-1] > A[i] && i>1){
            lst++;
        }
        ans[i]=ans[lst]+1;
        
    }
    cout << ans[n-1] << endl;
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
