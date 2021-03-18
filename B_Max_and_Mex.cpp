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

    ll i, j, n, m, k;
    ll temp = -1, flag = 1;
    cin >> n >> k;
    vl A(n);
    map<int, int> hash;
    fo(i, 0, n)
    {
        cin >> A[i];
        temp = max(temp, A[i]);
        hash[A[i]]++;
    }
    fo(i, 0, temp + 1)
    {
        if (hash[i] == 0)
        {
            flag = 0;
            j = i;
            break;
        }
    }
    if (flag == 0)
    {
        // deb((j + temp + 1) / 2);
        if (k)
            if (hash[(j + temp + 1) / 2])
                cout << n << endl;
            else
            {
                cout << n + 1 << endl;
            }
        else
        {
            cout << n << endl;
        }
    }
    else
    {
        cout << temp + 1 + k << endl;
    }
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