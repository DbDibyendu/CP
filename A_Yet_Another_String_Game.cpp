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
    char B[100];
    cin >> A;
    flag = 0;
    fo(i, 0, A.length())
    {
        if (flag == 0)
        {
            if (A[i] == 'a')
            {
                B[i] = 'b';
            }
            else
            {
                B[i] = 'a';
            }
            flag = 1;
        }
        else
        {
            if (A[i] == 'z')
            {
                B[i] = 'y';
            }
            else
            {
                B[i] = 'z';
            }
            flag = 0;
        }
    }
    fo(i, 0, A.length())
    {
        cout << B[i];
    }
    cout << endl;
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