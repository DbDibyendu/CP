//! ╭━━━╮╱╱╱╱╱╱╱╱╭╮╱╱╱╭━━━┳━━━╮
//! ┃╭━╮┃╱╱╱╱╱╱╱╭╯╰╮╱╱┃╭━╮┃╭━╮┃
//? ┃┃╱┃┣━┳┳━━┳━┻╮╭╋━━┫┃┃┃┣╯╭╯┃
//? ┃╰━╯┃╭╋┫╭╮┃╭╮┃┃┃╭╮┃┃┃┃┃╱┃╭╯
//? ┃╭━╮┃┃┃┃╰╯┃╭╮┃╰┫╰╯┃╰━╯┃╱┃┃
//? ╰╯╱╰┻╯╰┻━╮┣╯╰┻━┻━━┻━━━╯╱╰╯
//* ╱╱╱╱╱╱╱╭━╯┃
//* ╱╱╱╱╱╱╱╰━━╯

#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define pb push_back
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
//=======================
const int MOD = 1'000'000'007;
const int N = 3e5 + 10, M = N;
//=======================

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 0;

    cin >> n;

    ll A[n] = {0};
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    if (n == 2 || n == 3)
    {
        cout << n << endl;
        return;
    }
    vector<pair<ll, ll>> index;
    ll t = 2;
    ll M = 2;
    ll ans = 0;
    ll diff = A[1] - A[0];
    fo(i, 2, n)
    {
        if (A[i] - A[i - 1] != diff)
        {
            index.pb({t, diff});
            if (t > M)
                M = t;
            t = 2;
            diff = A[i] - A[i - 1];
            if (i == n - 1)
            {
                index.pb({t, diff});
                if (M < t)
                    M = t;
            }
        }
        else
        {
            t++;
            if (i == n - 1)
            {
                index.pb({t, diff});
                if (M < t)
                    M = t;
            }
        }
    }

    int z = index.size();
    fo(i, 0, z)
    {
        // temp = index[i].second;
        if (i < n - 2 && index[i + 1].first == 2 && index[i + 1].second + index[i + 2].second == 2 * index[i].second)
        {
            if (i < n - 3 && index[i].second == index[i + 3].second && index[i + 2].first == 2)
            {
                long long int x = index[i].first + index[i + 3].first;
                if (x > M)
                    M = x;
            }
            else
            {
                long long int x = index[i].first + 1;
                if (x > M)
                    M = x;
            }
        }

        if (i > 1 && index[i - 1].first == 2 && index[i - 1].second + index[i - 2].second == 2 * index[i].second)
        {

            long long int x = index[i].first + 1;
            if (x > M)
                M = x;
        }

        // M = max(temp, M);
    }

    if (M == n)
        M--;
    cout << M + 1;
    cout << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    int k = 1;
    while (t--)
    {
        cout << "Case #" << k << ": ";
        solve();
        k++;
    }
    return 0;
}

//=======================