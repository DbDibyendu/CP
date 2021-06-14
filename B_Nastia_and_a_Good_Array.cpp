#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
#define display(A) for(auto &aa:A) cout <<aa<<" "; cout <<"\n"; 
#define displayP(A) for(auto &aa:A) {display(aa);}
#define read(A) for(auto &aa:A) {cin>>aa;}
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
//=======================
const int MOD = 1'000'000'007;
const int N = 1e8, M = N;
//=======================
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vi A(n);
    int max_ind = 0;
    int M = 0;
    read(A)

    cout << n / 2 << endl;

    for (i = 0; i < n - 1; i += 2)
    {
        cout << i + 1 << " " << i + 2 << " " << min(A[i], A[i + 1]) << " " << MOD << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================