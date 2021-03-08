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
const int N = (1 << 30) + 10, M = N;
//=======================

// ! Recursive Approach ..... Now need to add DP
bool ans;
void even(int n, int j)
{
    int i = 2;
    if (n > j)
    {
        return;
    }
    while (i <= n)
    {

        if ((i & n) == i)
        {
            if (i + n == j)
            {
                ans = 1;
                break;
            }
            else
            {
                even(i + n, j);
            }
        }
        i += 2;
    }
}
void odd(int n, int j)
{
    int i = 1;
    if (n > j)
    {
        return;
    }
    while (i <= n)
    {
        if ((i & n) == i)
        {
            if (i + n == j)
            {
                ans = 1;
                break;
            }
            else
            {
                if ((i + n) & 1)
                    odd(i + n, j);
                else
                {
                    even(i + n, j);
                }
            }
        }
        i++;
    }
}
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> i >> j;
    if (i > j)
    {
        cout << "NO" << endl;
        return;
    }
    if (i == j)
    {
        cout << "YES" << endl;
        return;
    }

    if (i & 1) //! For Odd case
    {
        ans = 0;
        odd(i, j);
        if (ans)
        {
            cout << "YES" << endl;
            return;
        }
    }
    else //! For even case
    {
        ans = 0;
        if (j % 2 == 0)
        {
            even(i, j);
            if (ans)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

void solve2()
{

    int i, j, n, m, k, a, b;
    ll temp = 0, flag = 1;
    cin >> a >> b;
    if (a > b)
    {
        cout << "NO" << endl;
        return;
    }
    if (a == b)
    {
        cout << "YES" << endl;
        return;
    }
    int x = 0, y = 0, t = 0;
    while (b)
    {
        x += a % 2;
        y += b % 2;
        a >>= 1;
        b >>= 1;
        if (x < y)
        {
            t = 1;
            break;
        }
    }
    if (t)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================