#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, n) for (i = a; i < n; i++)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define display(A)         \
    for (auto &aa : A)     \
        cout << aa << ' '; \
    cout << endl;
#define displayP(A)    \
    for (auto &aa : A) \
    {                  \
        display(aa);   \
    }
#define read(A)        \
    for (auto &aa : A) \
    {                  \
        cin >> aa;     \
    }
//===========================
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
//=======================
const int MOD = 1'000'000'007;
const int N = INT_MAX, M = N;
//=======================

void solve()
{

    ll i, j, n, m, k;
    ll temp = 0, flag = 1;
    cin >> n;
    string A;
    cin >> A;

    string s = "";
    i = 0;

    for (k = 0; k < 26; k++)
    {
        char p = 'a' + k;
        string t = s + p;
        // deb(t);
        // flag =
        if (A.find(t) == std::string::npos)
        {
            cout << t << endl;
            flag = 0;
            // break;
            return;
        }
    }

    for (i = 0; i < 26; i++)
    {
        s = 'a' + i;
        // string l = p;
        flag = -1;
        for (k = 0; k < 26; k++)
        {
            char p = 'a' + k;
            string t = s + p;
            // deb(t);
            if (A.find(t) == std::string::npos)
            {
                cout << t << endl;
                flag = 0;
                // break;
                return;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    string x = "a";
    for (i = 0; i < 26; i++)
    {
        char yl = 'a' + i;
        s = x + yl;
        // string l = p;
        flag = -1;
        for (k = 0; k < 26; k++)
        {
            char p = 'a' + k;
            string t = s + p;
            // deb(t);
            if (A.find(t) == std::string::npos)
            {
                cout << t << endl;
                flag = 0;
                // break;
                return;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    x = "b";
    for (i = 0; i < 26; i++)
    {
        char yl = 'a' + i;
        s = x + yl;
        // string l = p;
        flag = -1;
        for (k = 0; k < 26; k++)
        {
            char p = 'a' + k;
            string t = s + p;
            // deb(t);
            if (A.find(t) == std::string::npos)
            {
                cout << t << endl;
                flag = 0;
                // break;
                return;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

//=======================