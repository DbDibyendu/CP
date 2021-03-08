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

void solve2()
{
    int i, j, n, m, k;
    ll temp = 0, flag = 1, temp2 = 0;
    string A;
    cin >> A;
    n = A.length();
    char t1, t2, t3;
    t1 = A[0];
    t3 = A[n - 1];
    ll l = 0, r = 1, t = -1;
    fo(i, 0, n)
    {
        if (l < 0)
        {
            flag = 0;
            break;
        }

        if (A[i] == t1)
        {
            l++;
        }
        else if (A[i] == t3)
        {
            l--;
        }
        else
        {
            l++;
        }
    }
    if (l > 0)
    {
        flag = 0;
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        t1 = A[0];
        t3 = A[n - 1];
        ll l = 0, r = 1, t = -1;
        flag = 1;  // !
        fo(i, 0, n)
        {
            if (l < 0)
            {
                flag = 0;
                break;
            }

            if (A[i] == t1)
            {
                l++;
            }
            else if (A[i] == t3)
            {
                l--;
            }
            else
            {
                l--;
            }
        }
        if (l > 0)
        {
            flag = 0;
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
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