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

    int i, j, n, m, k, t;
    ll temp = 0, flag = 1;
    cin >> n >> m;
    vl A(n);
    fo(i, 0, n)
    {
        cin >> A[i];
    }
    t = n;
    map<int, int> hash;
    fo(i, 0, n)
    {
        k = A[i] % m;
        hash[k]++;
        // deb(k);
    }
    for (i = 0; i <= m / 2; i++)
    {
        if (i == 0)
        {
            if (hash[i])
                temp++;
        }
        else if (hash[i] || hash[m - i])
        {
            // deb2(hash[i], i);
            if (hash[i] > hash[m - i] + 1)
            {
                temp += hash[i] - hash[m - i];
            }
            else
            {
                if (hash[m - i] > hash[i] + 1)
                {
                    temp += hash[m - i] - hash[i];
                }
                else
                {
                    temp++;
                }
            }
        }
        //  deb(temp);
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