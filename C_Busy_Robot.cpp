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

    int i, j, n, m, k;
    ll t = 0, last = 0, ans = 0, dest = 0;
    ;
    cin >> n;

    vi T(n), A(n), arr;

    fo(i, 0, n)
    {
        cin >> T[i] >> A[i];
    }
    t = T[0] + abs(A[0]);

    last = 0;
    dest = A[0];
    j = 0;
    fo(i, 1, n)
    {
        if (dest - last >= 0)
        {
            if (T[i] >= t)
            {

                last = dest;
                dest = A[i];
                t = T[i] + abs(dest-last);
                j = i;
                ans++;
            }
            else if (T[i] < t)
            {
                if (A[i] > last + T[i] - T[j]  && A[i] < dest)
                {
                    ans++;
                        deb2(T[i],ans);
                }
            }
        }
        else if (dest - last < 0)
        {
            if (T[i] >= t)
            {

                last = dest;
                dest = A[i];
                t = T[i] + abs(dest-last);
                j = i;
                ans++;
                deb2(T[i], ans);
            }
            else
            {
                if (A[i] < last - (T[i] - T[j]) && A[i] > dest)
                {
                    ans++;
                     
                }
            }
        }
    }

    cout << ans << endl;
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