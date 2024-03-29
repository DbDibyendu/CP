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
    string T, P, S;
    cin >> T >> P;
    m = P.length();
    S += P;
    S += '$';
    S += T;

    n = S.length();
    vl prefix(n, 0);

    // ! KMP algo Implementation
    j = 0;
    i = 1;
    while (i < n)
    {
        if (S[i] == S[j])
        {
            j++;
            prefix[i] = j;
            i++;
        }

        else
        {
            if (j == m)
            {
                printf("Found pattern at index %d \n", i - j - m - 1);
                j = prefix[j - 1];
            }
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
    if (j == m)
    {
        printf("Found pattern at index %d \n", i - j - m - 1);
        j = prefix[j - 1];
    }
    // ! Checking how many patterns are there
    // i = 0;
    for (auto x : prefix)
    {
        if (x == m)
        {
            temp++;
        }
    }

    cout << temp << endl;
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