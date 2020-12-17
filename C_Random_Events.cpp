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
    ll temp = 0, flag = 1;
    double ans = 1, p, fans;
    cin >> n >> m;
    vi A(n + 1, 0);
    

    for(i=1;i<=n;i++) {
        cin >> A[i];
    }

    for (j = n; j > 0; j--)
    {
        if (j != A[j])
        {
          // deb2(j,A[j]);
            break;
        }
    }

    fo(i, 0, m)
    {
        cin >> k >> p;
        if (k >= j)
        {
            ans *= 1 - p;
        }
    }

    if (j == 0)
    {

        cout << 1 << endl;
        return;
    }

    fans = 1 - ans;
    cout << fans << endl;
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