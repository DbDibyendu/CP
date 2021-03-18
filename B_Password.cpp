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

//! Time limit exceeded
void solve()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A, B;
    cin >> A;
    B = A;
    n = A.length();
    vl prefix;
    map<string, int> hash;
    if (n < 3)
    {
        cout << "Just a legend" << endl;
        return;
    }
    fo(i, 0, n - 1)
    {
        // deb2(A.substr(0, i + 1), A.substr(n - i - 1, n - 1));
        if (A.substr(0, i + 1) == A.substr(n - i - 1, i + 1))
        {
            hash[A.substr(0, i + 1)];
            prefix.pb(i + 1);
        }
    }

    A.erase(0, 1);
    A.erase(n - 2, n - 1);
    vl ans;
    for (auto y : hash)
    {
        // deb(y.first);
        if (A.find(y.first) != string::npos) //! Finding a string in another string
        {
            ans.pb(y.first.size());
        }
    }
    sort(ans.rbegin(), ans.rend());
    if (!ans.empty())
    {
        cout << B.substr(0, ans[0]) << endl;
    }
    else
    {
        cout << "Just a legend" << endl;
    }
}

void solve2()
{

    int i, j, n, m, k;
    ll temp = 0, flag = 1;
    string A, B;
    cin >> A;
    B = A;
    n = A.length();
    map<string, int> hash;
    if (n < 3)
    {
        cout << "Just a legend" << endl;
        return;
    }
    vl prefix(n, 0);
    j = 0;
    i = 1;
    while (i < n)
    {
        if (A[i] == A[j])
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

    // ! Checking how many patterns are there
    // deb(prefix[n - 1]);
    if (prefix[n - 1])
    {
        fo(i, 1, n - 1)
        {
            // deb(prefix[i]);
            if (prefix[i] == prefix[n - 1])
            {
                cout << A.substr(0, prefix[n - 1]);
                return;
            }
        }
        // deb(prefix[prefix[n - 1] - 1]);

        if (prefix[prefix[n - 1] - 1])
        {
            // deb(prefix[prefix[n - 1]]);
            cout << A.substr(0, prefix[prefix[n - 1] - 1]);
            return;
        }

        cout << "Just a legend" << endl;
        return;
    }
    else
    {
        cout << "Just a legend" << endl;
        return;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

//=======================