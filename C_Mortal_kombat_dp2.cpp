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

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n + 1];
        for (size_t i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        int ans = 0, dp[n + 1];
        for (size_t i = 0; i <= n; i++)
        {
            dp[i] = n + 1;
        }

        dp[0] = 0;
        if (n == 1)
        {
            printf("%d\n", a[1]);
        }
        else
        {
            for (int i = 2; i < n + 1; i++)
            {
        
                int A= n+1, b = n + 1, c = n + 1, d = n + 1, e = n + 1;
                A= dp[i - 1] + a[i];
                b = dp[i - 2] + a[i - 1];
                if (i >= 3)
                {
                    c = dp[i - 3] + a[i - 1] + a[i - 2];
                    d = dp[i - 3] + a[i - 2];
                }
                if (i >= 4)
                {
                    e = dp[i - 4] + a[i - 3] + a[i - 2];
                }

                dp[i] = min(min(b,d),min(c,e));
                dp[i] = min(dp[i],A);
                if (i == n)
                {
                    
                }
            }
            ans = dp[n];
            printf("%d\n", ans);
        }
    }
}
