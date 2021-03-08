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

void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A;
    cin >> n;
    cin >> A;
    ll pre[3] = {0};
    fo(i, 0, n)
    {
        if (A[i] == 'R')
        {
            pre[0]++;
        }
        else if (A[i] == 'G')
        {
            pre[1]++;
        }
        else
        {
            pre[2]++;
        }
    }
    
    if (n == 1)
    {
        cout << A[0] << endl;
    }
    else if (n == 2)
    {
        if (pre[0] && pre[1])
        {
            cout << "B" << endl;
        }
        else if (pre[2] && pre[1])
        {
            cout << "R" << endl;
        }
        else if (pre[0] && pre[2])
        {
            cout << "G" << endl;
        }
        else
        {
            cout << A[0] << endl;
        }
    }
    else
    {
        if (pre[1] && pre[2] && pre[0])
        {
            cout << "BGR" << endl;
        }
        else if (pre[0] > 1 && pre[1] > 1)
        {
            cout << "BGR" << endl;
        }
        else if (pre[2] > 1 && pre[1] > 1)
        {
            cout << "BGR" << endl;
        }
        else if (pre[0] > 1 && pre[2] > 1)
        {
            cout << "BGR" << endl;
        }
        else if (pre[0] == 1 && pre[1] > 1) // ! 2 cases
        {
            cout << "BR" << endl;
        }
        else if (pre[0] == 1 && pre[2] > 1)
        {
            cout << "GR" << endl;
        }
        else if (pre[1] == 1 && pre[2] > 1)
        {
            cout << "GR" << endl;
        }
        else if (pre[1] == 1 && pre[0] > 1)
        {
            cout << "BG" << endl;
        }
        else if (pre[2] == 1 && pre[1] > 1)
        {
            cout << "BR" << endl;
        }
        else if (pre[2] == 1 && pre[0] > 1)
        {
            cout << "BG" << endl;
        }
        else
        {
            cout << A[0] << endl;
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