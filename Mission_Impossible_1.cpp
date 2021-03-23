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
const int N = 305, M = N;
//=======================

int solve(string &a, string &b)
{
    b = b + b;

    b = b.substr(0, b.size() - 1);

    ll temp = 0;
    string s = a + "$" + b;
    ll n = s.length();

    ll A[n];
    ll l = 0, r = 0;
    ll i;

    vl prefix(n, 0);

    // ! KMP algo Implementation
    ll j = 0;
    i = 1;
    while (i < n)
    {
        if (s[i] == s[j])
        {
            j++;
            prefix[i] = j;
            i++;
        }
        else
        {
            if (j > 0)
            {
                j = prefix[j - 1];
            }
            else
            {
                prefix[i] = 0;
                i++;
            }
        }
    }

    fo(i, 1, n)
    {
        if (prefix[i] == a.length())
            temp++;
    }
    return temp;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }

    return 0;
}
