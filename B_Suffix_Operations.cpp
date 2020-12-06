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
    ll temp = 0;
    int flag = 0;
    cin >> n;
    vi A(n, 0);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    fo(i,1,n)
    {
        temp+=abs(A[i]-A[i-1]);
    }
    flag=max(abs(A[1]-A[0]),abs(A[n-1]-A[n-2]));
    fo(i, 1, n-1)
    {
        flag=max(flag,abs(A[i]-A[i-1])+abs(A[i+1]-A[i])-abs(A[i+1]-A[i-1]));


    }
  //  deb2(temp,flag);
    cout << temp - flag << endl;
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