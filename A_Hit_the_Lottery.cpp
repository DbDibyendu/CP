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

// Not an optimal solution with dp
// will show run time error

void solve()
{

    ll i, j, n = 0, m, k, rem;
    ll temp = 0, flag = 1;
    cin >> n;
    if ((n % 100 == 0))
    {
        cout << n / 100;
        return;
    }
    else
    {
        rem = n % 100;
        temp += n / 100;
        if (rem % 20 == 0)
        {
            temp += rem / 20;
            cout << temp << endl;
            return;
        }
        else
        {
            n = rem;
            rem = n % 20;
            temp += n / 20;
            if (rem % 10 == 0)
            {
                temp += rem / 10;
                cout << temp << endl;
                return;
            }
            else
            {
                n = rem;
                rem = n % 10;
                temp += n / 10;
                if (rem % 5 == 0)
                {
                    temp += rem / 5;
                    cout << temp << endl;
                    return;
                }
                else
                {
                    n = rem;
                    rem = n % 5;
                    temp += n / 5 + rem;
                    cout << temp << endl;
                    return;
                }
            }
        }
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================