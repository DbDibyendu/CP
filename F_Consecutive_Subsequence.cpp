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

// Time limit + memory limit Exceed
void solve()
{

    ll i, j, n, m, k;
    int temp = 0, flag = 1, last;
    cin >> n;
    vi A(n);
    vvi dp;
    dp.assign(n + 1, vector<int>(n + 1, 1));
    fo(i, 0, n) cin >> A[i];

    last = A[0];
    fo(j, 0, n - 1)
    {

        last = A[j];

        for (i = j + 1; i < n; i++)
        {
            if (A[i] == last + 1)
            {
                dp[i][j] = max(dp[i - 1][j] + 1, dp[i][j]);
                last = A[i];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }

        temp = max(temp, dp[n - 1][j]);
        if (temp == dp[n - 1][j])
        {
            flag = j;
            deb(flag);
        }
    }

    cout << temp << endl;

    last = A[flag];

    cout << flag + 1 << " ";

    for (i = flag + 1; i < n; i++)
    {
        if (A[i] == last + 1)
        {

            cout << i + 1 << " ";
            last = A[i];
        }
    }
}

// Time limit Exceed
void solve2()
{

    ll i, j, n, m, k;
    int temp = 0, flag = 1, last;
    cin >> n;
    vi A(n);
    vi dp(n + 1, 1);
    fo(i, 0, n) cin >> A[i];

    last = A[0];
    fo(j, 0, n - 1)
    {

        last = A[j];

        for (i = j + 1; i < n; i++)
        {
            if (A[i] == last + 1)
            {
                dp[i] = max(dp[i - 1] + 1, dp[i]);
                last = A[i];
            }

            else
            {
                dp[i] = dp[i - 1];
            }
        }

        temp = max(temp, dp[n - 1]);
        if (dp[n - 1] == temp)
        {
            flag = j;
        }
        dp.assign(n + 1, 1);
    }

    cout << temp << endl;

    last = A[flag];

    cout << flag + 1 << " ";

    for (i = flag + 1; i < n; i++)
    {
        if (A[i] == last + 1)
        {

            cout << i + 1 << " ";
            last = A[i];
        }
    }

}

// A Totally different Correct approach

void solve3()
{

    ll i, j, n, m, k;
    int temp = 0, flag = 1, last;
    cin >> n;
    vi A(n);
   	map<int,int> dp;
    vi r;
    fo(i, 0, n) cin >> A[i];

    // Construction of DP and what will be the parameter of DP is very important    
    fo(i, 0, n )
    {
        int x;
        x=A[i];
        dp[x]=dp[x-1]+1;

        if(temp<dp[x]){
            temp=dp[x];
            last=A[i];   
        }
        
    }
    for(j=n-1;j>=0;j--){
        if(A[j]==last){
            r.pb(j);
            last--;
        }
    }

    sort(r.begin(),r.end());

    cout << r.size() << endl;

    for(auto y: r){
        cout<<y+1<<" ";
    }
   
}


int main()
{
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve3();
    }
    return 0;
}

//=======================