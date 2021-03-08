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
const int N = INT_MAX, M = N;
//=======================

bool ismirror(int n, int m, int Ht, int Mt)
{
    int flag = 1, i;

    int n1 = n, m1 = m;
    for (i = 0; i < 2; i++)
    {
        if (n % 10 == 1 || n % 10 == 0 || n % 10 == 2 || n % 10 == 5 || n % 10 == 8)
        {
            n /= 10;
        }
        else
        {
            flag = 0;
            break;
        }
        if (m % 10 == 1 || m % 10 == 0 || m % 10 == 2 || m % 10 == 5 || m % 10 == 8)
        {
            m /= 10;
        }
        else
        {
            flag = 0;
            break;
        }
    }

    int t1, t2;
    if (n1 / 10 == 0)
    {
        // deb(n);
        if (n1 == 2)
        {
            n1 = 5;
        }
        else if (n1 == 5)
        {
            n1 = 2;
        }

        if (n1 * 10 < Mt)
        {
        }
        else
        {
            flag = 0;
        }
    }
    else
    {
        t1 = n1 / 10;
        if (t1 == 2)
        {
            t1 = 5;
        }
        else if (t1 == 5)
        {
            t1 = 2;
        }
        t2 = n1 % 10;
        if (t2 == 2)
        {
            t2 = 5;
        }
        else if (t2 == 5)
        {
            t2 = 2;
        }
        n1 = t2 * 10 + t1;
        if (n1 < Mt)
        {
        }
        else
        {
            flag = 0;
        }
    }
    if (m1 / 10 == 0)
    {
        if (m1 == 2)
        {
            m1 = 5;
        }
        else if (m1 == 5)
        {
            m1 = 2;
        }
        if (m1 * 10 < Ht)
        {
        }
        else
        {
            flag = 0;
        }
    }
    else
    {
        t1 = m1 / 10;
        if (t1 == 2)
        {
            t1 = 5;
        }
        else if (t1 == 5)
        {
            t1 = 2;
        }
        t2 = m1 % 10;
        if (t2 == 2)
        {
            t2 = 5;
        }
        else if (t2 == 5)
        {
            t2 = 2;
        }
        m1 = t2 * 10 + t1;
        if (m1 < Ht)
        {
        }
        else
        {
            flag = 0;
        }
    }
    return flag;
}
void solve()
{

    int h, i, j, n, m, k, sh, sm, a1, a2;
    ll temp = 0, flag = 0;
    cin >> h >> m;
    char t;
    cin >> sh >> t >> sm;
    i = sh;
    j = sm;

    while (i <= h)
    {
        if (i == h)
        {
            i = 0;
        }
        while (j <= m)
        {

            if (j == m)
            {
                j = 0;
                break;
            }
            // deb2(i, j);
            if (ismirror(i, j, h, m))
            {
                flag = 1;
                a1 = i, a2 = j;
                break;
            }
            j++;
        }
        if (flag == 1)
        {
            break;
        }
        i++;
    }

    // deb(ismirror(22, 0, 100, 100));

    printf("%02d:", a1);
    printf("%02d\n", a2);
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