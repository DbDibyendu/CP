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
    ll temp = 0, flag=-1;
    cin >> n;
    ll A[n];
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    ll maxP = -1, maxN = -1;
    i=0;
    while (i < n)
    {
        maxP=-1;
        while (A[i] >= 0 && i<n)
        {
            maxP = max(maxP, A[i]);
            i++;
            flag=1;
        }
        if(flag==1){
        temp += maxP;
        }

        maxN=-INT_MAX;
        while(A[i] < 0 && i<n)
        {
            maxN = max(maxN, A[i]);
            i++;
          //  deb(maxN);
            flag=0;
        }
        if(flag==0){
        temp+=maxN;
        }
    }
    cout<<temp<<endl;
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