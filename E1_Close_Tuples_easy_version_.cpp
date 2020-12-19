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

ll C(ll n, int r)
{
    if (n < 3)
        return 0;
    else
    {
        return (n * (n - 1) * (n - 2) / 6);
    }
}

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> count(n + 1, 0);
    vector<ll> visited(n + 1, 0);

    fo(i, 0, n)
    {
        cin >> arr[i];
        count[arr[i]]++;
    }

    for (j = 1; j + 2 <= n; j++)
    {
        if (count[j] + count[j + 1] + count[j + 2] >= 3)
        {
            if (visited[j] || visited[j + 1])
            {
                temp += C(count[j] + count[j + 1] + count[j + 2], 3) - C(count[j] + count[j + 1], 3);
                visited[j]++;
                visited[j + 1]++;
                visited[j + 2]++;
            }

            else
            {
                temp += C(count[j] + count[j + 1] + count[j + 2], 3);
                visited[j]++;
                visited[j + 1]++;
                visited[j + 2]++;
            }
        }
    }
    cout << temp << endl;
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